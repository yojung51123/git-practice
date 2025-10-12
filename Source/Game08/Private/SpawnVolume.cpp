#include "SpawnVolume.h"
#include "Components/BoxComponent.h"


ASpawnVolume::ASpawnVolume()
{
 
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);
	
	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);

	AnimalDataTable = nullptr;

}


FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent(); //Box�� ����
	FVector BoxOrigin = SpawningBox->GetComponentLocation(); //Box �߽� ��ġ

	return BoxOrigin + FVector( // Box ���� ������ ������ ����
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

AActor* ASpawnVolume::SpawnRandomAnimal()
{
	if (FAnimalSpawnRow* SelectedRow = GetRandomAnimal()) // GetRandomAnimal()�Լ��� ���� ����
	{
		if (UClass* ActualClass = SelectedRow->AnimalClass.Get())
		{
			return SpawnAnimal(ActualClass);
		}
	}
	return nullptr;
}

FAnimalSpawnRow* ASpawnVolume::GetRandomAnimal() const
{
	if (!AnimalDataTable) return nullptr; //������ ���̺��� ���ٸ� nullptr
	
		TArray<FAnimalSpawnRow*> AllRows;
		static const FString ContextString(TEXT("AnimalSpawnContext"));

		AnimalDataTable->GetAllRows(ContextString, AllRows);
		
		if (AllRows.IsEmpty()) return nullptr;

		//Ȯ�� �� ���ϱ�
		float TotalChance = 0.0f;
		for (const FAnimalSpawnRow* Row : AllRows)
		{
			if (Row)
			{
				TotalChance += Row->SpawnChance;
			}
		}

		// ����Ȯ���� ������ ����
		const float RandValue = FMath::FRandRange(0.0f, TotalChance); // 0 ~ TotalChance���� ������

		float AccumulateChance = 0.0f;

		for (FAnimalSpawnRow* Row : AllRows)
		{
			AccumulateChance += Row->SpawnChance;
			if (RandValue <= AccumulateChance)
			{
				return Row;
			}
		}

		return nullptr;
	

}

AActor* ASpawnVolume::SpawnAnimal(TSubclassOf<AActor> AnimalClass)
{
	if (!AnimalClass) return nullptr;

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(
		AnimalClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator
	);

	return SpawnedActor;
}


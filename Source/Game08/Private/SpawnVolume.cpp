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
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent(); //Box의 절반
	FVector BoxOrigin = SpawningBox->GetComponentLocation(); //Box 중심 위치

	return BoxOrigin + FVector( // Box 범위 내에서 랜덤값 생성
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

AActor* ASpawnVolume::SpawnRandomAnimal()
{
	if (FAnimalSpawnRow* SelectedRow = GetRandomAnimal()) // GetRandomAnimal()함수에 의해 선택
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
	if (!AnimalDataTable) return nullptr; //데이터 테이블이 없다면 nullptr
	
		TArray<FAnimalSpawnRow*> AllRows;
		static const FString ContextString(TEXT("AnimalSpawnContext"));

		AnimalDataTable->GetAllRows(ContextString, AllRows);
		
		if (AllRows.IsEmpty()) return nullptr;

		//확률 합 구하기
		float TotalChance = 0.0f;
		for (const FAnimalSpawnRow* Row : AllRows)
		{
			if (Row)
			{
				TotalChance += Row->SpawnChance;
			}
		}

		// 누적확률로 아이템 선택
		const float RandValue = FMath::FRandRange(0.0f, TotalChance); // 0 ~ TotalChance까지 랜덤값

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


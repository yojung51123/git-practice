
#include "RandomTimer.h"
#include "RandomSpawner.h"
#include "RandomActor.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


ARandomTimer::ARandomTimer()
{
 
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

}


void ARandomTimer::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		SpawnTimerHandle,
		this,
		&ARandomTimer::SpawnActor,
		4.0f,
		true
	);

	GetWorld()->GetTimerManager().SetTimer(
		DestoryTimerHandle,
		this,
		&ARandomTimer::DestoryActors,
		30.0f,
		true
	);
}

void ARandomTimer::SpawnActor()
{
	AActor* SpawnerActor = UGameplayStatics::GetActorOfClass(GetWorld(), ARandomSpawner::StaticClass());
	ARandomSpawner* SpawnerRef = Cast<ARandomSpawner>(SpawnerActor);

	if (!SpawnerRef) return;

	if (!bSpawnMessage && GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, TEXT("RandomSpawn!!"));
		bSpawnMessage = true;
	}

	float X = FMath::FRandRange(SpawnAreaMin.X, SpawnAreaMax.X);
	float Y = FMath::FRandRange(SpawnAreaMin.Y, SpawnAreaMax.Y);
	float Z = FMath::FRandRange(SpawnAreaMin.Z, SpawnAreaMax.Z);
	FVector RandomLocation = FVector(X, Y, Z);

	SpawnerRef->SpawnActorLocation(RandomLocation);

}

void ARandomTimer::DestoryActors()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARandomActor::StaticClass(), FoundActors);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Actor Deleted!!"));

		for (AActor* Actor : FoundActors)
		{
			Actor->Destroy();

			bSpawnMessage = false;
		}
	}
}





#include "FireSpawner.h"
#include "Components/BoxComponent.h"
#include "SpawnActor.h"

AFireSpawner::AFireSpawner()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	SpawnVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolume"));
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void AFireSpawner::SpawnActor()
{
	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	GetWorld()->SpawnActor<ASpawnActor>(SpawnLocation, SpawnRotation);
}


void AFireSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}


void AFireSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




#include "RandomSpawner.h"
#include "Engine/World.h"


ARandomSpawner::ARandomSpawner()
{
 
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Engine/MapTemplates/Materials/BasicAsset01.BasicAsset01"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	} 

	StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}


void ARandomSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}



void ARandomSpawner::SpawnActorLocation(FVector SpawnLocation)
{
	if (ActorRandomSpawnClass)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		GetWorld()->SpawnActor<ARandomActor>(ActorRandomSpawnClass, SpawnLocation, FRotator::ZeroRotator, SpawnParams);
	}

}



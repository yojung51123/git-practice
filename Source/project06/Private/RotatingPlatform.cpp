
#include "RotatingPlatform.h"


ARotatingPlatform::ARotatingPlatform() // È¸Àü ÇÃ·§Æû 
{
 	
	PrimaryActorTick.bCanEverTick = true;


	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Metal_Gold.M_Metal_Gold"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	RotationSpeed = 70.0f;
} 

void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(GetActorLocation()); // ÇöÀç À§Ä¡ 
	SetActorScale3D(FVector(4.0f, 4.0f, 0.25f));
	
}


void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!FMath::IsNearlyZero(RotationSpeed))
	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f)); //X,Y,ZÃà
}




#include "RoundFloor.h"


ARoundFloor::ARoundFloor()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_TableRound.SM_TableRound"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	
	MovingSpeed = 400;
}


void ARoundFloor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = FVector(1020.0f, -3590.0f, 1070.0f);
	EndLocation = FVector(StartLocation.X, -6880.0f, StartLocation.Z);
	CurrentLocation = GetActorLocation();
	SetActorLocation(StartLocation);
	SetActorScale3D(FVector(4.0f));
	
	
}

void ARoundFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Move)
	{
		CurrentLocation.Y -= MovingSpeed * DeltaTime;
		if (CurrentLocation.Y <= EndLocation.Y)
		{
			CurrentLocation.Y = EndLocation.Y;
			Move = false;
		}
		
	}
	else
	{
		CurrentLocation.Y += MovingSpeed * DeltaTime;
		if (CurrentLocation.Y >= StartLocation.Y)
		{
			CurrentLocation.Y = StartLocation.Y;
			Move = true;
		}
	}

	CurrentLocation.X = StartLocation.X;
	CurrentLocation.Z = StartLocation.Z;

	SetActorLocation(CurrentLocation);
	

}


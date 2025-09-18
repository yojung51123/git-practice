
#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform() // 움직이는 플랫폼
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}


	StartLocation = FVector(1490.0f, 460.0f, 30.0f); //현재위치
	MaxRange = FVector(StartLocation.X, StartLocation.Y, 400.0f);
	CurrentLocation = GetActorLocation();
	MoveSpeed = 200.0f; //이동속도
	

}


void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	SetActorLocation(StartLocation);
	SetActorScale3D(FVector(5.0f, 5.0f, 0.5f));
	
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMovingup) //true라면
	{
		CurrentLocation.Z += MoveSpeed * DeltaTime; //Z축 증가
		
		if (CurrentLocation.Z >= MaxRange.Z) // 현재 지점이 도착지점과 보다 크거나 같다면
		{
			CurrentLocation.Z = MaxRange.Z;
			bMovingup = false; //방향전환
		}
	}
	else
	{
		CurrentLocation.Z -= MoveSpeed * DeltaTime; //z축 감소

		if (CurrentLocation.Z <= StartLocation.Z) // 현재위치가 시작위치보다 더 작거나 같아진다면
		{
			CurrentLocation.Z = StartLocation.Z;
			bMovingup = true; // 방향 전환
		}

	}

	CurrentLocation.X = StartLocation.X;
	CurrentLocation.Y = StartLocation.Y;
	
	SetActorLocation(CurrentLocation); //Actor의 위치를 월드에 반영

}




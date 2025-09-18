
#include "MovingPlatform.h"


AMovingPlatform::AMovingPlatform() // �����̴� �÷���
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


	StartLocation = FVector(1490.0f, 460.0f, 30.0f); //������ġ
	MaxRange = FVector(StartLocation.X, StartLocation.Y, 400.0f);
	CurrentLocation = GetActorLocation();
	MoveSpeed = 200.0f; //�̵��ӵ�
	

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

	if (bMovingup) //true���
	{
		CurrentLocation.Z += MoveSpeed * DeltaTime; //Z�� ����
		
		if (CurrentLocation.Z >= MaxRange.Z) // ���� ������ ���������� ���� ũ�ų� ���ٸ�
		{
			CurrentLocation.Z = MaxRange.Z;
			bMovingup = false; //������ȯ
		}
	}
	else
	{
		CurrentLocation.Z -= MoveSpeed * DeltaTime; //z�� ����

		if (CurrentLocation.Z <= StartLocation.Z) // ������ġ�� ������ġ���� �� �۰ų� �������ٸ�
		{
			CurrentLocation.Z = StartLocation.Z;
			bMovingup = true; // ���� ��ȯ
		}

	}

	CurrentLocation.X = StartLocation.X;
	CurrentLocation.Y = StartLocation.Y;
	
	SetActorLocation(CurrentLocation); //Actor�� ��ġ�� ���忡 �ݿ�

}







#include "MyActor.h"


AMyActor::AMyActor() //별
{
 
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot); //루트 컴포넌트 설정

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot); // 루트컴포넌트에 붙인다

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C")); // 별모양 메시
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Potion.M_Potion")); // 머티리얼
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object); // 0번째에 머티리얼 설정
	}

	StartLocation = FVector(540.0f, -870.0f, 500.0f);
	 EndLocation = FVector(1260.0f, StartLocation.Y, StartLocation.Z);
	 CurrentLocation = GetActorLocation();
	 MoveSpeed = 250.0f;


}


void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(CurrentLocation);
	SetActorRotation(FRotator(0.0f, -90.0f, 0)); //Z Y X
	SetActorScale3D(FVector(3.0f));
	
}


void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Move)
	{
		CurrentLocation.X += MoveSpeed * DeltaTime;

		if (CurrentLocation.X >= EndLocation.X)
		{
			CurrentLocation = EndLocation;
			Move = false;
		}
	}
	else
	{
		CurrentLocation.X -= MoveSpeed * DeltaTime;
		if (CurrentLocation.X <= StartLocation.X)
		{
			CurrentLocation = StartLocation;
			Move = true;
		}
	}
	

	CurrentLocation.Y = StartLocation.Y;
	CurrentLocation.Z = StartLocation.Z;

	SetActorLocation(CurrentLocation);

}


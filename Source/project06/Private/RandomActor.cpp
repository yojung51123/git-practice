
#include "RandomActor.h"


ARandomActor::ARandomActor() // 핑크 코인
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/SM_Coin_A.SM_Coin_A"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/DatasmithContent/Materials/CE_OpaqueReference.CE_OpaqueReference"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	

}// 


void ARandomActor::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARandomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


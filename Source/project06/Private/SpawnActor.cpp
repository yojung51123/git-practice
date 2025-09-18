
#include "SpawnActor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"



ASpawnActor::ASpawnActor() // Æ÷¼Ç
{
 	
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComp"));
	
	SphereComp->SetupAttachment(RootComponent);
	SphereComp->SetSimulatePhysics(true);
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	StaticMeshComp->AttachToComponent(SphereComp, FAttachmentTransformRules::KeepRelativeTransform);
	ParticleComp->AttachToComponent(StaticMeshComp, FAttachmentTransformRules::KeepRelativeTransform);

	SphereComp->SetSphereRadius(16.0f);

	StaticMeshComp->SetRelativeLocation(FVector(0.0, 0.0, -12.0f));
	StaticMeshComp->SetRelativeScale3D(FVector(0.25, 0.25, 0.25));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Game/Resources/Props/SM_Star_C.SM_Star_C"));
	if (SphereMeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(SphereMeshAsset.Object);
	} 
	
	static ConstructorHelpers::FObjectFinder<UParticleSystem>ParticleCompAsset(TEXT("/Game/Resources/Particles/P_Fire.P_Fire"));
	if (ParticleCompAsset.Succeeded())
	{
		ParticleComp->SetTemplate(ParticleCompAsset.Object);
	}


}


void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();

	
	
}


void ASpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




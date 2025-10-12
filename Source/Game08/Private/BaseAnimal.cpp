#include "BaseAnimal.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

ABaseAnimal::ABaseAnimal()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collison"));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetupAttachment(Scene);

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(Collision);
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseAnimal::OnAnimalOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseAnimal::OnAnimalEndOverlap);

}


void ABaseAnimal::OnAnimalOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		ActivateAnimal(OtherActor);
	}

}

void ABaseAnimal::OnAnimalEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{

}

void ABaseAnimal::ActivateAnimal(AActor* Activator)
{

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			PickupSound,
			GetActorLocation()
		);
	}
}

FName ABaseAnimal::GetAnimalType() const
{
	return AnimalType;
}

void ABaseAnimal::DestroyAnimal()
{
	Destroy();
}
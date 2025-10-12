#include "TigerAnimal.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

ATigerAnimal::ATigerAnimal()
{
	AttackRadius = 200.0f;
	AttackDamage = 30;
	AnimalType = "Tiger";

	TigerCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	TigerCollision->InitSphereRadius(AttackRadius);
	TigerCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	TigerCollision->SetupAttachment(Scene);

}

void ATigerAnimal::ActivateAnimal(AActor* Activator)
{
	Super::ActivateAnimal(Activator);

	TArray<AActor*> OverlappingActors;
	TigerCollision->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			UGameplayStatics::ApplyDamage(
				Actor,
				AttackDamage,
				nullptr,
				this,
				UDamageType::StaticClass()
			);
			
		}
	}

	DestroyAnimal();
}
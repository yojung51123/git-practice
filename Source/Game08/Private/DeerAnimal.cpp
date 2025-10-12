#include "DeerAnimal.h"
#include "MyCharacter.h"

ADeerAnimal::ADeerAnimal()
{
	HealAmount = 20.0f;
	AnimalType = "Deer";
}

void ADeerAnimal::ActivateAnimal(AActor* Activator)
{
	Super::ActivateAnimal(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(Activator))
		{
			PlayerCharacter->AddHealth(HealAmount);
		}
	}
	DestroyAnimal();
}
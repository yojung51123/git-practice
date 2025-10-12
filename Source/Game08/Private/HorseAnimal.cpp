#include "HorseAnimal.h"
#include "AnimalGameState.h"
#include "Engine/World.h"


AHorseAnimal::AHorseAnimal()
{
	AnimalType = "Horse"; //���� ����
	PointValue = 30;
}

void AHorseAnimal::ActivateAnimal(AActor* Activator)
{
	Super::ActivateAnimal(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (AAnimalGameState* GameState = World->GetGameState<AAnimalGameState>())
			{
				GameState->SubtractScore(PointValue);
			}
		}

	}

	DestroyAnimal();
}


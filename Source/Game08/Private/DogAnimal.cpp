#include "DogAnimal.h"
#include "Engine/World.h"
#include "AnimalGameState.h"

ADogAnimal::ADogAnimal() // 포인트가 이상하다면 여기 수정 / 함수 추가해야함
{
	PointValue = 50;
	AnimalType = "Dog";
}

void ADogAnimal::ActivateAnimal(AActor* Activator)
{
	Super::ActivateAnimal(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (AAnimalGameState* GameState = World->GetGameState<AAnimalGameState>())
			{
				GameState->AddScore(PointValue);
			}
		}
		
	}

	DestroyAnimal();
}
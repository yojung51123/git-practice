#include "DogAnimal.h"
#include "Engine/World.h"
#include "AnimalGameState.h"

ADogAnimal::ADogAnimal() // ����Ʈ�� �̻��ϴٸ� ���� ���� / �Լ� �߰��ؾ���
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
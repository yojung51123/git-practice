#include "PenguinAnimal.h"
#include "MyCharacter.h"

APenguinAnimal::APenguinAnimal()
{
	AnimalType = "Penguin";
}

void APenguinAnimal::ActivateAnimal(AActor* Activator)
{
	Super::ActivateAnimal(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (AMyCharacter* PlayerCharacter = Cast<AMyCharacter>(Activator))
		{
			PlayerCharacter->SpeedDown();
		}
	}

	//몇초동안 + 몇 , 스프린트, 걷기시 이 함수 같이 호출 , UI도 같이 만들기

	DestroyAnimal();
}


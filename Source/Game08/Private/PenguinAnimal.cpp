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

	//���ʵ��� + �� , ������Ʈ, �ȱ�� �� �Լ� ���� ȣ�� , UI�� ���� �����

	DestroyAnimal();
}


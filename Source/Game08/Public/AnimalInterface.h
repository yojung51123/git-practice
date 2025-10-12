#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AnimalInterface.generated.h"


UINTERFACE(MinimalAPI)
class UAnimalInterface : public UInterface
{
	GENERATED_BODY()
};


class GAME08_API IAnimalInterface
{
	GENERATED_BODY()


public:

	UFUNCTION()
	virtual void OnAnimalOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
	
	UFUNCTION()
	virtual void OnAnimalEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;

	virtual void ActivateAnimal(AActor* Activator) = 0;
	virtual FName GetAnimalType() const = 0;




};

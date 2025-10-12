#pragma once

#include "CoreMinimal.h"
#include "BaseAnimal.h"
#include "HorseAnimal.generated.h"


UCLASS()
class GAME08_API AHorseAnimal : public ABaseAnimal
{
	GENERATED_BODY()


public:
	
	AHorseAnimal();

	virtual void ActivateAnimal(AActor* Activator) override;

	int32 PointValue;
};

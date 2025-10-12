#pragma once

#include "CoreMinimal.h"
#include "BaseAnimal.h"
#include "PenguinAnimal.generated.h"


UCLASS()
class GAME08_API APenguinAnimal : public ABaseAnimal
{
	GENERATED_BODY()
	
public:

	APenguinAnimal();

	virtual void ActivateAnimal(AActor* Activator) override;
};

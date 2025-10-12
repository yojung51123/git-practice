#pragma once

#include "CoreMinimal.h"
#include "BaseAnimal.h"
#include "DeerAnimal.generated.h"


UCLASS()
class GAME08_API ADeerAnimal : public ABaseAnimal
{
	GENERATED_BODY()

public:

	ADeerAnimal();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Deer")
	int32 HealAmount;

	virtual void ActivateAnimal(AActor* Activator) override;

	
};

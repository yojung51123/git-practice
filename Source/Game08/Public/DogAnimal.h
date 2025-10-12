#pragma once

#include "CoreMinimal.h"
#include "BaseAnimal.h"
#include "DogAnimal.generated.h"


UCLASS()
class GAME08_API ADogAnimal : public ABaseAnimal
{
	GENERATED_BODY()

public:
	ADogAnimal();
	
	virtual void ActivateAnimal(AActor* Activator) override;

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
	int32 PointValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dog")
	int32 StartPoint;

	
};

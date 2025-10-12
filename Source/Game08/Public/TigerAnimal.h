#pragma once

#include "CoreMinimal.h"
#include "BaseAnimal.h"
#include "TigerAnimal.generated.h"


UCLASS()
class GAME08_API ATigerAnimal : public ABaseAnimal
{
	GENERATED_BODY()

public:
	
	ATigerAnimal();

	USphereComponent* TigerCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiger")
	int32 AttackDamage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tiger")
	float AttackRadius;

	virtual void ActivateAnimal(AActor* Activator) override;
	
};

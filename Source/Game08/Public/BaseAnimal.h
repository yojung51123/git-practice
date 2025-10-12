#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimalInterface.h"
#include "BaseAnimal.generated.h"

class USphereComponent;

UCLASS()
class GAME08_API ABaseAnimal : public AActor, public IAnimalInterface
{
	GENERATED_BODY()
	
public:	
	
	ABaseAnimal();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animal")
	FName AnimalType;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Animal")
	USceneComponent* Scene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animal")
	USphereComponent* Collision;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animal")
	USkeletalMeshComponent* SkeletalMesh;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animal|Effects")
	//UParticleSystem* PickupParticle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animal|Effects")
	USoundBase* PickupSound;


	virtual void OnAnimalOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override;
	
	virtual void OnAnimalEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;

	virtual void ActivateAnimal(AActor* Activator) override;
	virtual FName GetAnimalType() const override;

	virtual void DestroyAnimal();

	
};

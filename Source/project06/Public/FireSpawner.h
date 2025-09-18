
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "FireSpawner.generated.h"


UCLASS()
class PROJECT06_API AFireSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AFireSpawner();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnActor();


protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorSpawner")
	class UBoxComponent* SpawnVolume;
	
	virtual void BeginPlay() override;



	

};

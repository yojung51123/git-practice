#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimalSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class GAME08_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	

	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning") 
	UDataTable* AnimalDataTable; //데이터 테이블

	
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomAnimal();


	FAnimalSpawnRow* GetRandomAnimal() const;
	AActor* SpawnAnimal(TSubclassOf<AActor> AnimalClass);
	FVector GetRandomPointInVolume() const;


};

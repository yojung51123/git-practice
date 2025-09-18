
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomActor.h"
#include "RandomSpawner.generated.h"

UCLASS()
class PROJECT06_API ARandomSpawner : public AActor //���� ���� ������
{
	GENERATED_BODY()
	
public:	
	
	ARandomSpawner();


	UFUNCTION()
	void SpawnActorLocation(FVector SpawnLocation);


protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<ARandomActor> ActorRandomSpawnClass;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

};

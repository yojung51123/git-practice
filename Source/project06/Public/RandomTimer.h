
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomTimer.generated.h"

UCLASS()
class PROJECT06_API ARandomTimer : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ARandomTimer();


	UFUNCTION()
	void SpawnActor();

	UFUNCTION()
	void DestoryActors();

protected:
	
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestoryTimerHandle;

	bool bSpawnMessage = false;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTime")
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTime") // 스포너와 적당한 위치
	FVector SpawnAreaMin = FVector(700, -13950, 4280);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomTime")
	FVector SpawnAreaMax = FVector(1300, -13350, 4430);


	

};

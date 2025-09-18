
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireSpawner.h" // 스포너
#include "SpawnActor.h" // 액터
#include "Timer.generated.h"

UCLASS()
class PROJECT06_API ATimer : public AActor //타이머
{
	GENERATED_BODY()
	
public:	
	
	ATimer();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnActors(); //액터 스폰
	
	UFUNCTION()
	void DestroyActors(); // 액터 지우기

protected:
	
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimerHandle; // 스폰
	FTimerHandle DestoryTimerHandle; // 삭제
	


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Timer")
	USceneComponent* SceneRoot;


	



	

	
	

};

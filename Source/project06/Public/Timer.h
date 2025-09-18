
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireSpawner.h" // ������
#include "SpawnActor.h" // ����
#include "Timer.generated.h"

UCLASS()
class PROJECT06_API ATimer : public AActor //Ÿ�̸�
{
	GENERATED_BODY()
	
public:	
	
	ATimer();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnActors(); //���� ����
	
	UFUNCTION()
	void DestroyActors(); // ���� �����

protected:
	
	virtual void BeginPlay() override;

	FTimerHandle SpawnTimerHandle; // ����
	FTimerHandle DestoryTimerHandle; // ����
	


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Timer")
	USceneComponent* SceneRoot;


	



	

	
	

};

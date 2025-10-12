#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "AnimalGameState.generated.h"


UCLASS()
class GAME08_API AAnimalGameState : public AGameState
{
	GENERATED_BODY()
	

public:
	
	AAnimalGameState();

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Score")
	int32 Score; //���� ����

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 SpawnedDogCount;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	int32 CollectedDogCount;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	float LevelDuration;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex; //���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevels; //�ִ� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;//���̺�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWaves;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames; //�� �̸�

	FTimerHandle LevelTimerHandle;
	FTimerHandle HUDUpDateTimerHandle;
	FTimerHandle WaveTimerHandle; //���̺�

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Score")
	void SubtractScore(int32 Amount);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();

	void StartLevel();
	void OnLevelTimeUp();
	void EndLevel();
	/*void OnDogCollected();*/
	void UpDateHUD(); //UI
	void NextWave(); //���̺�
	void StartWave(); //���̺�


};

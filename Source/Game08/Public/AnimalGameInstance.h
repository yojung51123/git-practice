#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AnimalGameInstance.generated.h"


UCLASS()
class GAME08_API UAnimalGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UAnimalGameInstance();

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "GameData")
	int32 TotalScore;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 CurrentWaveIndex;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "GameData")
	void SubtractToScore(int32 Amount); // 점수 차감 
};

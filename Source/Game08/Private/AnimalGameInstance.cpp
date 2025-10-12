#include "AnimalGameInstance.h"

UAnimalGameInstance::UAnimalGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
	CurrentWaveIndex = 0;

}

void UAnimalGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
}

void UAnimalGameInstance::SubtractToScore(int32 Amount)
{
	TotalScore -= Amount;

}
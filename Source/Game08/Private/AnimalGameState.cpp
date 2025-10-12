#include "AnimalGameState.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "AnimalGameInstance.h"
#include "DogAnimal.h"
#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "MyCharacter.h"
#include "HorseAnimal.h"

AAnimalGameState::AAnimalGameState()
{
	Score = 0;
	SpawnedDogCount = 0;
	CollectedDogCount = 0;
	LevelDuration = 30.0f; //레벨 지속시간
	CurrentLevelIndex = 0;
	MaxLevels = 3;
	CurrentWaveIndex = 0; //웨이브 
	MaxWaves = 3;

}

void AAnimalGameState::BeginPlay()
{
	Super::BeginPlay();
	
	StartLevel();
	CurrentWaveIndex = 0; //맵바뀔때 다시 초기화
	NextWave();

	GetWorldTimerManager().SetTimer( //게임 시작시 타이머 초기화
		HUDUpDateTimerHandle,
		this,
		&AAnimalGameState::UpDateHUD,
		0.1f,
		true
	);
}


int32 AAnimalGameState::GetScore() const
{
	return Score;
}

void AAnimalGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AnimalGameInstance->AddToScore(Amount);
		}
	}
}

void AAnimalGameState::SubtractScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AnimalGameInstance->SubtractToScore(Amount);
		}
	}
}


void AAnimalGameState::StartLevel() //레벨 시작
{

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->ShowGameHUD();
		}
	}

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			CurrentLevelIndex = AnimalGameInstance->CurrentLevelIndex;
			CurrentWaveIndex = AnimalGameInstance->CurrentWaveIndex; // 확인해보고 대기
		}
	}

	SpawnedDogCount = 0; //스폰된 강아지 수
	CollectedDogCount = 0; // 플레이어가 모은 강아지 수 

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 40; //아이템 스폰 개수

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)//0개 보다 크다면
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]); //0번째
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomAnimal();
				if (SpawnedActor && SpawnedActor->IsA(ADogAnimal::StaticClass()))
				{
					SpawnedDogCount++;
				}
			}
		}
	}


	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AAnimalGameState::OnLevelTimeUp,
		LevelDuration,
		false
	);

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Purple, FString::Printf(TEXT("Level %d "), CurrentLevelIndex + 1));

}

//void AAnimalGameState::OnDogCollected()
//{
//	CollectedDogCount++;
//	
//	if (SpawnedDogCount > 0 && CollectedDogCount >= SpawnedDogCount)
//	{
//		NextWave();
//	}
//}

void AAnimalGameState::OnLevelTimeUp() //시간초과
{
	NextWave();
}

void AAnimalGameState::NextWave() //웨이브
{

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->ShowGameHUD();
		}
	}
	
	SpawnedDogCount = 0; //스폰된 강아지 수
	CollectedDogCount = 0; // 플레이어가 모은 강아지 수 

	GetWorldTimerManager().ClearTimer(LevelTimerHandle); //타이머 핸들 초기화

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AddScore(Score);
			CurrentWaveIndex++; //현재 웨이브 +1
			AnimalGameInstance->CurrentWaveIndex = CurrentWaveIndex;
		}
	}

	if (CurrentWaveIndex > MaxWaves)
	{
		EndLevel();
	}
	StartWave();

}

void AAnimalGameState::StartWave() //웨이브
{
	if (CurrentWaveIndex <= MaxWaves) //메세지 출력
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Wave %d Start!!"), CurrentWaveIndex));

	}

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 20; //아이템 추가 스폰 개수

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)//0개 보다 크다면
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]); //0번째
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomAnimal();
				if (SpawnedActor && SpawnedActor->IsA(ADogAnimal::StaticClass()))
				{
					SpawnedDogCount++;
				}
			}
		}
	}


	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AAnimalGameState::OnLevelTimeUp,
		LevelDuration,
		false
	); 
}


void AAnimalGameState::EndLevel()
{

	GetWorldTimerManager().ClearTimer(LevelTimerHandle); //타이머 핸들 초기화

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AddScore(Score);
			CurrentLevelIndex++; //현재레벨 +1
			AnimalGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}
	
	
	//여기 수정
	if (CurrentLevelIndex > MaxLevels)
	{
		OnGameOver();
		return;
	} 

	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);

	}
	else
	{
		OnGameOver();
	}
	// 최대 레벨 일때
	//NextLevel() 함수로 타이머, 스폰양 초기화하고 레벨 인덱스 ++ 하면 될듯 
	//1레벨당 웨이브 3개씩 웨이브는 새로 함수만들기!



}
void AAnimalGameState::OnGameOver()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->SetPause(true);
			MyPlayerController->ShowMainMenu(true); //재시작으로 표시
		}
	}
}

void AAnimalGameState::UpDateHUD()
{

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController);
		if (UUserWidget* HUDWidget = MyPlayerController->GetHUDWidget())
		{
			if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Time")))) 
			{
				float RemainingTime = GetWorldTimerManager().GetTimerRemaining(LevelTimerHandle);
				TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time : %.1f"), RemainingTime)));
			}

			if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score")))) // 점수도 추가해야함 
			{
				//게임인스턴스 가져오기
				if (UGameInstance* GameInstance = GetGameInstance())
				{
					UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance); //내가만든 게임 인스턴스로 캐스팅
					ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score : %d "), AnimalGameInstance->TotalScore)));//총 점수 가져오기

				}
			}

			if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level")))) 
			{
				LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Level : %d"), CurrentLevelIndex + 1)));
			}

			if (UTextBlock* WaveIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave")))) //웨이브
			{
				WaveIndexText->SetText(FText::FromString(FString::Printf(TEXT("Wave : %d"), CurrentWaveIndex)));
			}
		}
	}
}


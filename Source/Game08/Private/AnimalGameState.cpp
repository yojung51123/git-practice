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
	LevelDuration = 30.0f; //���� ���ӽð�
	CurrentLevelIndex = 0;
	MaxLevels = 3;
	CurrentWaveIndex = 0; //���̺� 
	MaxWaves = 3;

}

void AAnimalGameState::BeginPlay()
{
	Super::BeginPlay();
	
	StartLevel();
	CurrentWaveIndex = 0; //�ʹٲ� �ٽ� �ʱ�ȭ
	NextWave();

	GetWorldTimerManager().SetTimer( //���� ���۽� Ÿ�̸� �ʱ�ȭ
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


void AAnimalGameState::StartLevel() //���� ����
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
			CurrentWaveIndex = AnimalGameInstance->CurrentWaveIndex; // Ȯ���غ��� ���
		}
	}

	SpawnedDogCount = 0; //������ ������ ��
	CollectedDogCount = 0; // �÷��̾ ���� ������ �� 

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 40; //������ ���� ����

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)//0�� ���� ũ�ٸ�
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]); //0��°
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

void AAnimalGameState::OnLevelTimeUp() //�ð��ʰ�
{
	NextWave();
}

void AAnimalGameState::NextWave() //���̺�
{

	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->ShowGameHUD();
		}
	}
	
	SpawnedDogCount = 0; //������ ������ ��
	CollectedDogCount = 0; // �÷��̾ ���� ������ �� 

	GetWorldTimerManager().ClearTimer(LevelTimerHandle); //Ÿ�̸� �ڵ� �ʱ�ȭ

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AddScore(Score);
			CurrentWaveIndex++; //���� ���̺� +1
			AnimalGameInstance->CurrentWaveIndex = CurrentWaveIndex;
		}
	}

	if (CurrentWaveIndex > MaxWaves)
	{
		EndLevel();
	}
	StartWave();

}

void AAnimalGameState::StartWave() //���̺�
{
	if (CurrentWaveIndex <= MaxWaves) //�޼��� ���
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Wave %d Start!!"), CurrentWaveIndex));

	}

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 20; //������ �߰� ���� ����

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)//0�� ���� ũ�ٸ�
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]); //0��°
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

	GetWorldTimerManager().ClearTimer(LevelTimerHandle); //Ÿ�̸� �ڵ� �ʱ�ȭ

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance);
		if (AnimalGameInstance)
		{
			AddScore(Score);
			CurrentLevelIndex++; //���緹�� +1
			AnimalGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}
	
	
	//���� ����
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
	// �ִ� ���� �϶�
	//NextLevel() �Լ��� Ÿ�̸�, ������ �ʱ�ȭ�ϰ� ���� �ε��� ++ �ϸ� �ɵ� 
	//1������ ���̺� 3���� ���̺�� ���� �Լ������!



}
void AAnimalGameState::OnGameOver()
{
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (AMyPlayerController* MyPlayerController = Cast<AMyPlayerController>(PlayerController))
		{
			MyPlayerController->SetPause(true);
			MyPlayerController->ShowMainMenu(true); //��������� ǥ��
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

			if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Score")))) // ������ �߰��ؾ��� 
			{
				//�����ν��Ͻ� ��������
				if (UGameInstance* GameInstance = GetGameInstance())
				{
					UAnimalGameInstance* AnimalGameInstance = Cast<UAnimalGameInstance>(GameInstance); //�������� ���� �ν��Ͻ��� ĳ����
					ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score : %d "), AnimalGameInstance->TotalScore)));//�� ���� ��������

				}
			}

			if (UTextBlock* LevelIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Level")))) 
			{
				LevelIndexText->SetText(FText::FromString(FString::Printf(TEXT("Level : %d"), CurrentLevelIndex + 1)));
			}

			if (UTextBlock* WaveIndexText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("Wave")))) //���̺�
			{
				WaveIndexText->SetText(FText::FromString(FString::Printf(TEXT("Wave : %d"), CurrentWaveIndex)));
			}
		}
	}
}


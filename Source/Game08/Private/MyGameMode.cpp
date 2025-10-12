#include "MyGameMode.h"
#include "MyCharacter.h"
#include "AnimalGameState.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{

	DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
	GameStateClass = AAnimalGameState::StaticClass();
}
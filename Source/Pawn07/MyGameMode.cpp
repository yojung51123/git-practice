#include "MyGameMode.h"
#include "PlayerPawn.h"
#include "MyPlayerController.h"

AMyGameMode::AMyGameMode()
{
	DefaultPawnClass = APlayerPawn::StaticClass(); // ½ºÆù
	PlayerControllerClass = AMyPlayerController::StaticClass();

}


#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomActor.generated.h"

UCLASS()
class PROJECT06_API ARandomActor : public AActor //·£´ý ¾×ÅÍ
{
	GENERATED_BODY()
	
public:	
	
	ARandomActor();
	virtual void Tick(float DeltaTime) override;



protected:

	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	

};

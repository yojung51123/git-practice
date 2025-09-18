
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class PROJECT06_API AMyActor : public AActor //º°
{
	GENERATED_BODY()
	
public:	

	AMyActor();

	virtual void Tick(float DeltaTime) override;

	

protected:

	virtual void BeginPlay() override;

	USceneComponent* SceneRoot;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "StaticMesh")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingStar")
	FVector StartLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingStar")
	FVector EndLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingStar")
	FVector CurrentLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingStar")
	float MoveSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingStar")
	bool Move = true;



};

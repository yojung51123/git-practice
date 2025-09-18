
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PROJECT06_API AMovingPlatform : public AActor // ¿òÁ÷ÀÌ´Â ÇÃ·§Æû
{
	GENERATED_BODY()
	
public:	
	
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;
	
	USceneComponent* SceneRoot;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "StaticMesh")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingPlatform")
	FVector StartLocation;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingPlatform")
	FVector MaxRange;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingPlatform")
	FVector CurrentLocation;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingPlatform")
	float MoveSpeed;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "MovingPlatform")
	bool bMovingup = true;
	

};

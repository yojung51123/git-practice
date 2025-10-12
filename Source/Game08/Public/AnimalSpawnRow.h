#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AnimalSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FAnimalSpawnRow : public FTableRowBase //데이터 테이블의 행
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AnimalName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> AnimalClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance;

};


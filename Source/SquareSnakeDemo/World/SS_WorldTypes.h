// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SS_WorldTypes.generated.h"

USTRUCT(BlueprintType)
struct FAthleteColors : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FLinearColor GridBgColor{FLinearColor::Black};

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FLinearColor GridWallColor{FLinearColor::Red};

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FLinearColor GridLineColor{FLinearColor::Gray};

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	FLinearColor FogColor{FLinearColor::Blue};
	
	
};

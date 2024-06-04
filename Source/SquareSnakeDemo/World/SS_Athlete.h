// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/Athlete.h"
#include "Core/Grid.h"
#include "GameFramework/Actor.h"
#include "SS_Athlete.generated.h"

class AAthleteUnit;

UCLASS()
class SQUARESNAKEDEMO_API ASS_Athlete : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASS_Athlete();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetModel(const TSharedPtr<SquareSnakeDemo::Athlete>& InAthlete, uint32 InCellSize, const SquareSnakeDemo::Dim& InDim);

protected:
	virtual void BeginPlay() override;
	//如果将以下变量放到private会导致无法访问到前置声明的AthleteUnit类
	UPROPERTY(EditDefaultsOnly, Category=Design)
	TSubclassOf<AAthleteUnit> UnitClass;
	
	
private:
	TSharedPtr<SquareSnakeDemo::Athlete> Athlete;
	TArray<TObjectPtr<AAthleteUnit>> AthleteUnits;
	uint32 CellSize;
	SquareSnakeDemo::Dim Dim;
};

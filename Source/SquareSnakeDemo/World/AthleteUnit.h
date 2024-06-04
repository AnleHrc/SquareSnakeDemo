// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AthleteUnit.generated.h"

UCLASS()
class SQUARESNAKEDEMO_API AAthleteUnit : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAthleteUnit();

	void SetModel(uint32 InCellSize);
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Origin;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> UnitMesh;
private:
};


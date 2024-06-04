// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "SquareSnakeDemo/Core/Game.h"
#include "SS_Pawn.generated.h"

UCLASS()
class SQUARESNAKEDEMO_API ASS_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASS_Pawn();
	void UpdateLocation(SquareSnakeDemo::Dim InDim, uint32 CellSize, const FTransform& InOrigin);

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;

private:
	void OnPawnResizedViewport(FViewport* InViewport, uint32 InPriority);
	FDelegateHandle ResizeHandle;
	SquareSnakeDemo::Dim Dim;
	uint32 CellSize;
	FTransform Origin;
	
};

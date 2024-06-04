// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SS_WorldTypes.h"
#include "GameFramework/Actor.h"
#include "SquareSnakeDemo/Core/Game.h"
#include "SS_Grid.generated.h"

namespace SquareSnakeDemo
{
	class Grid;
}

UCLASS()
class SQUARESNAKEDEMO_API ASS_Grid : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASS_Grid();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void SetModel(const TSharedPtr<SquareSnakeDemo::Grid>& InGrid, uint32 InCellSize);

	void UpdateColors(const FAthleteColors& InColors);
	
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> Origin;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> GridMesh;

private:
	void DrawGrid();

	SquareSnakeDemo::Dim Dim;
	uint32 CellSize;
	uint32 WorldWidth;
	uint32 WorldHeight;
	
	UMaterialInstanceDynamic* Mat;
};

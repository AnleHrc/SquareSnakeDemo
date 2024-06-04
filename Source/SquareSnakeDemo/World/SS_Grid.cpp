// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Grid.h"

#include "Components/LineBatchComponent.h"
#include "SquareSnakeDemo/Core/Grid.h"
#include "SquareSnakeDemo/MiniPlay/Core/Core_Types.h"


// Sets default values
ASS_Grid::ASS_Grid()
{
	
	// 修改true 为 false，否则网格的线条一直为红色，不会更改为设置的线条颜色
	PrimaryActorTick.bCanEverTick = false;

	Origin = CreateDefaultSubobject<USceneComponent>("Origin");
	check(Origin);
	SetRootComponent(Origin);

	GridMesh = CreateDefaultSubobject<UStaticMeshComponent>("GridMesh");
	check(GridMesh);
	//SetRootComponent(Origin);
	GridMesh->SetupAttachment(Origin);
}


// Called every frame
//在场景中生成线条
void ASS_Grid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DrawGrid();
	
	
}

void ASS_Grid::SetModel(const TSharedPtr<SquareSnakeDemo::Grid>& InGrid, uint32 InCellSize)
{
	Dim = InGrid->dim();
	CellSize = InCellSize;
	WorldWidth = CellSize * Dim.width;
	WorldHeight = CellSize * Dim.height;

	//设置模型缩放
	check(GridMesh->GetStaticMesh());
	const FVector BoxSize = GridMesh->GetStaticMesh()->GetBoundingBox().GetSize();
	check(!BoxSize.IsZero());
	GridMesh->SetRelativeScale3D({WorldHeight/BoxSize.X, WorldWidth / BoxSize.Y, 1.0});
	GridMesh->SetRelativeLocation({WorldHeight * 0.5, WorldWidth * 0.5,-BoxSize.Z * 0.5});

	//set mesh material  
	Mat = GridMesh->CreateDynamicMaterialInstance(0);
	if (Mat)
		Mat->SetVectorParameterValue("DimSize",FVector{1.f * Dim.height, 1.f * Dim.width, 0.f});
}

void ASS_Grid::UpdateColors(const FAthleteColors& InColors)
{
	if (Mat)
	{
		Mat->SetVectorParameterValue("BackgroundColor",InColors.GridBgColor);
		Mat->SetVectorParameterValue("LineColor", InColors.GridLineColor);
		Mat->SetVectorParameterValue("WallColor", InColors.GridWallColor);
	}
}

void ASS_Grid::DrawGrid()
{
	// ! + ！
	if (!GetWorld() || !GetWorld()->LineBatcher) return;

	// 水平线
	for (uint32 i = 0; i <= Dim.height; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorForwardVector() * CellSize * i;

		GetWorld()->LineBatcher->DrawLine(StartLocation, StartLocation + GetActorRightVector() * WorldWidth, FLinearColor::Red,1,2.f);
	}

	// 竖直线
	for (uint32 i = 0; i<= Dim.width; ++i)
	{
		const FVector StartLocation = GetActorLocation() + GetActorRightVector() * CellSize * i;

		GetWorld()->LineBatcher->DrawLine(StartLocation, StartLocation + GetActorForwardVector() * WorldHeight, FLinearColor::Red,1,2.f);
	}
}


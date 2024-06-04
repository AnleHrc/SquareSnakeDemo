// Fill out your copyright notice in the Description page of Project Settings.


#include "SS_Pawn.h"

namespace
{
	double FOVTan(float FOVDegree)
	{
		//求相机FOV角度(半角) 的tan值,相机到地面的高度为h,相机视角中的两边的临界边的一般为底边
		return FMath::Tan(FMath::DegreesToRadians(0.5*FOVDegree));
		
	}

	//Field of view calculations (Fied_of_view_in_video_games on Wikipedia)
	double VFOV(float HFOVDegree, double ViewportAspectHW)
	{
		//Expression write?
		return FMath::RadiansToDegrees(2 * FMath::Atan(FMath::Tan(FMath::DegreesToRadians(0.5 * HFOVDegree))) / ViewportAspectHW);
	}
	constexpr double GridMargin {5.0};
}

// Sets default values
ASS_Pawn::ASS_Pawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	check(Root);
	SetRootComponent(Root);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	check(CameraComp);
	CameraComp->SetupAttachment(Root);
	CameraComp->SetRelativeRotation(FRotator(-90.0f,0.f,0.f));
}

void ASS_Pawn::UpdateLocation(SquareSnakeDemo::Dim InDim, uint32 InCellSize, const FTransform& InOrigin)
{
	Dim = InDim;
	CellSize = InCellSize;
	Origin = InOrigin;

	
	auto* Viewport = GEngine->GameViewport->Viewport;
	Viewport->ViewportResizedEvent.Remove(ResizeHandle);
	ResizeHandle = Viewport->ViewportResizedEvent.AddUObject(this,&ASS_Pawn::OnPawnResizedViewport);
}

//窗口视角
void ASS_Pawn::OnPawnResizedViewport(FViewport* InViewport, uint32 InPriority)
{
	if (!InViewport || InViewport->GetSizeXY().Y == 0|| Dim.height == 0) return;

	const double TotalWidth = CellSize * (Dim.width + GridMargin);
	const double TotalHeight = CellSize * (Dim.height + GridMargin);

	double LocationZ {0.0};
	const double ViewportAspect = StaticCast<double>(InViewport->GetSizeXY().X) / InViewport->GetSizeXY().Y;
	const double GridAspect = StaticCast<double>(Dim.width) / Dim.height;
	if (ViewportAspect >= GridAspect) //垂直 FOV
	{
		LocationZ = TotalHeight / FOVTan(VFOV(CameraComp->FieldOfView, ViewportAspect));
	}
	else // 竖直 FOV
	{
		LocationZ = TotalWidth / FOVTan(CameraComp->FieldOfView);
	}

	SetActorLocation(0.5 * FVector {StaticCast<double>(CellSize*Dim.height), StaticCast<double>(CellSize * Dim.width), LocationZ} + Origin.GetLocation());

}

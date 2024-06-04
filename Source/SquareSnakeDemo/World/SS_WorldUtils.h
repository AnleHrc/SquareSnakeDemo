// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MiniPlay/Core/Core_Types.h"

namespace SquareSnakeDemo
{
	class WorldUtils
	{
	public:
		static FVector PositionToVector(const Position& Position, uint32 WorldSize, const Dim& Dim)
		{
			//添加 0.5的偏移
			return  FVector(Dim.height - Position.y - 1,Position.x,0.0) * WorldSize + FVector(WorldSize * 0.5);
		}
		static void ScaleMesh(UStaticMeshComponent* Mesh, uint32 InCellSize)
		{
			if (Mesh && Mesh->GetStaticMesh())
			{
				const FBox Box = Mesh->GetStaticMesh()->GetBoundingBox();
				const auto Size = Box.GetSize();
				Mesh->SetRelativeScale3D(FVector(InCellSize) / Size);
			}
		};
		
	};
}

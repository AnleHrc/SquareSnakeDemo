// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Containers/SS_List.h"

namespace SquareSnakeDemo
{
	struct SQUARESNAKEDEMO_API Dim
	{
		uint32 width;
		uint32 height;
		
	};

	struct SQUARESNAKEDEMO_API Position
	{
		uint32 x;
		uint32 y;

		Position() = default;
		Position(uint32 xIn, uint32 yIn) : x(xIn), y(yIn) {}

		FORCENOINLINE Position& operator+=(const Position& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}
		const static Position Zero;
	};
	
	enum class CellType : uint8
	{
		Empty = 0,
		NiceTaste,
		Athlete,
		Wall
	};

	struct SQUARESNAKEDEMO_API Settings
	{
		Dim dim{40,20};
		// 初始化贪吃蛇
		struct Athlete
		{
			//初始化链表起始大小，身体的初始长度
			uint32 initSize {4u};
			Position startPos {Position::Zero};
		} athlete;
	};

	struct SQUARESNAKEDEMO_API Input
	{
		int8 x {1}; // -1向左 0不动 1向右
		int8 y {1}; // -1向下 0不动 1向上
		FORCENOINLINE bool opposite(const Input& rhs) {return rhs.x == -x || rhs.y == -y; }
		const static  Input DefaultInput;
	};

	using AthleteList = TDoubleLinkedList<Position>; //1
	using AthleteNode = AthleteList::TDoubleLinkedListNode;
}

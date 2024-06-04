// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

DEFINE_LOG_CATEGORY_STATIC(LogGrid,All,All)

SquareSnakeDemo::Grid::Grid(const Dim& inDim) : m_dim(inDim)
{
	m_celltypes.Init(CellType::Empty,m_dim.width * m_dim.height);
	InitWalls();
	PrintDebug();
	
}

void SquareSnakeDemo::Grid::update(const AthleteNode* link, CellType cellType)
{
	freeCellsByType(cellType);
	auto* tempLink = link;
	while (tempLink)
	{
		updateInternal(tempLink->GetValue(),cellType);
		tempLink = tempLink->GetNextNode();  
	}
	PrintDebug();
}

bool SquareSnakeDemo::Grid::hitTest(const Position& position, CellType cellType)
{
	const uint32 index = posToIndex(position);
	return m_celltypes[index] == cellType;
}

void SquareSnakeDemo::Grid::InitWalls()
{
	// 外围墙
	for (uint32 x = 0; x < m_dim.width; ++x)
	{
		for (uint32 y = 0; y < m_dim.height; ++y)
		{
			if (x==0 || x+1==m_dim.width || y==0 || y+1==m_dim.height)
			{
				auto index = posToIndex(x,y);
				m_celltypes[index] = CellType::Wall;
				indByType[CellType::Wall].Add(index);
			}	
		}
	}
}

void SquareSnakeDemo::Grid::PrintDebug()
{
#if !UE_BUILD_SHIPPING
	// 外围墙
	for (uint32 y = 0; y < m_dim.height; ++y)
	{
		FString DebugLineMsg;
		for (uint32 x = 0; x < m_dim.width; ++x)
		{
			TCHAR temp{' '};
			switch (m_celltypes[posToIndex(x,y)])
			{
			case CellType::Empty:temp = '0';break;
			case CellType::Wall:temp = '*';break;
			case CellType::Athlete:temp = '_';break;
			case CellType::NiceTaste:temp = 'F';break;
			}
			DebugLineMsg.AppendChar(temp).AppendChar(' ');
		}
		UE_LOG(LogGrid, Display,TEXT("%s"),*DebugLineMsg);
	}
#endif
	
	
}

void SquareSnakeDemo::Grid::freeCellsByType(CellType inCellType)
{
	//判断写成了(indByType)
	if (!indByType[inCellType].IsEmpty())
	{
		for (uint32 index : indByType[inCellType])
			m_celltypes[index] = CellType::Empty;
		indByType[inCellType].Empty();
	}
}

void SquareSnakeDemo::Grid::updateInternal(const Position& position, CellType cellType)
{
	const uint32 index = posToIndex(position);
	m_celltypes[index] = cellType;
	indByType[cellType].Add(index);
}

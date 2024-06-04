// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SquareSnakeDemo/MiniPlay/Core/Core_Types.h"


/**
 * 
 */
namespace SquareSnakeDemo
{

 class SQUARESNAKEDEMO_API Grid
 {
 public:
  Grid(const Dim& inDim);

  Dim dim() const {return m_dim;}
  void update(const AthleteNode* link, CellType cellType);
  static  Position center(const Dim& inDim){return Position {inDim.width/2+1, inDim.height/2+1};}

  //碰撞检测
  bool hitTest(const Position& position, CellType cellType);
  
 protected:
 private:
  void InitWalls();
  void PrintDebug();
  void freeCellsByType(CellType inCellType);
  void updateInternal(const Position& position, CellType cellType);
 
// 将位置坐标换为索引
  FORCEINLINE uint32 posToIndex(uint32 x, uint32 y) const {return x+y*m_dim.width;}
  FORCEINLINE uint32 posToIndex(const Position& pos) const {return pos.x + pos.y * m_dim.width;}
  const Dim m_dim;
  TArray<CellType> m_celltypes;
  TMap<CellType,TArray<uint32>> indByType{
      {     CellType::Wall, {}},
		    {  CellType::Athlete, {}}, 
      {CellType::NiceTaste, {}}
   };
 };
 
}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SquareSnakeDemo/MiniPlay/Core/Core_Types.h"

namespace SquareSnakeDemo
{
	class Grid;
	class Athlete;
	class SQUARESNAKEDEMO_API Game
	{
	public:
		Game(const Settings& inSettings);
		FORCEINLINE TSharedPtr<Grid> grid() const{return m_grid;};
		FORCEINLINE TSharedPtr<Athlete> athlete() const{return m_athlete;};

		void update(float deltaSeconds);

		
		
	protected:
	private:
		void updateGrid();
		bool goHome();
		
		const Settings c_Settings;
		TSharedPtr<Grid> m_grid;
		TSharedPtr<Athlete> m_athlete;

		bool m_goHome {false};
	};
	
}

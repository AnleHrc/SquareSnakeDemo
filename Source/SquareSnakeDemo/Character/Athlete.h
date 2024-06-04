// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SquareSnakeDemo/MiniPlay/Core/Core_Types.h"



namespace SquareSnakeDemo
{

	class SQUARESNAKEDEMO_API Athlete
	{
	public:
		Athlete(const Settings::Athlete& inAthlete);

		void move(Input input);

		FORCEINLINE const AthleteList& getLinks() const {return m_links; }
		FORCEINLINE const Position& getHead() const {return m_links.GetHead()->GetValue(); }
		
	protected:
	private:
		AthleteList m_links;
		Input m_lastInput;
	};
 
}

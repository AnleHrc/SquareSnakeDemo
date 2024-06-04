// Fill out your copyright notice in the Description page of Project Settings.


#include "Athlete.h"

SquareSnakeDemo::Athlete::Athlete(const Settings::Athlete& inAthlete)
{
	checkf(inAthlete.initSize>3, TEXT("Athlete is too weak as %i unit long"), inAthlete.initSize);
	for (uint32 i = 0; i < inAthlete.initSize; ++i)
	{
		//从起点往左添加
		// Error
		// m_links.AddTail(Position(inAthlete.startPos.x-i,inAthlete.startPos.y));
		m_links.AddTail(Position{inAthlete.startPos.x - i, inAthlete.startPos.y});
	}
}

void SquareSnakeDemo::Athlete::move(Input input)
{
	if (!input.opposite(m_lastInput)) m_lastInput = input;
	m_links.GetTail()->GetValue() = m_links.GetHead()->GetValue();
	m_links.MoveTailAfterHead();
	m_links.GetHead()->GetValue() += Position(m_lastInput.x, m_lastInput.y);
}

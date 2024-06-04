// Fill out your copyright notice in the Description page of Project Settings.


//Grid -> Game -> GameMode
#include "Game.h"
#include "Grid.h"
#include "SquareSnakeDemo/Character/Athlete.h"

SquareSnakeDemo::Game::Game(const Settings& inSettings) : c_Settings(inSettings)
{
	m_grid = MakeShared<Grid>(c_Settings.dim);
	m_athlete = MakeShared<Athlete>(c_Settings.athlete);
}

void SquareSnakeDemo::Game::update(float deltaSeconds)
{
	if (m_goHome) return;
	m_athlete->move(Input::DefaultInput);
	if (goHome())
	{
		m_goHome = true;
		return;
	}
	updateGrid();
}

bool SquareSnakeDemo::Game::goHome()
{
	if (m_grid->hitTest(m_athlete->getHead(),CellType::Wall)) return true;

	return false;
}

void SquareSnakeDemo::Game::updateGrid()
{
	m_grid->update(m_athlete->getLinks().GetHead(), CellType::Athlete);
	
}
 
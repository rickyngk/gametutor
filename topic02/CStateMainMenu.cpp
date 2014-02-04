#include "CStateMainMenu.h"
#include "CStateManagement.h"
#include "CGame.h"
#include <stdio.h>

CStateMainMenu::CStateMainMenu(): m_iCount(0), CState("CStateMainMenu")
{}

void CStateMainMenu::Init()
{
	printf("State Poster: Init\n");
	m_iCount = 10;
}

void CStateMainMenu::Update()
{
	if (m_iCount <= 1)
	{
		CGame::GetInstance()->Exit();
	}
	m_iCount--;
}

void CStateMainMenu::Render()
{
	printf("State Poster: %d\n", m_iCount);
}

void CStateMainMenu::Exit()
{
	printf("State Poster: Exit\n");
}

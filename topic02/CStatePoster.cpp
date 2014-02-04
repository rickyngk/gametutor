#include "CStatePoster.h"
#include "CStateManagement.h"
#include "CGame.h"
#include <stdio.h>

CStatePoster::CStatePoster(): m_iCount(0), CState("CStatePoster")
{}

void CStatePoster::Init()
{
	printf("State Poster: Init\n");
	m_iCount = 10;
}

void CStatePoster::Update()
{
	if (m_iCount <= 1)
	{
		CGame::GetInstance()->Exit();
	}
	m_iCount--;
}

void CStatePoster::Render()
{
	printf("State Poster: %d\n", m_iCount);
}

void CStatePoster::Exit()
{
	printf("State Poster: Exit\n");
}

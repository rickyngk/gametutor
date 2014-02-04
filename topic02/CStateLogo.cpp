#include "CStateLogo.h"
#include "CStateManagement.h"
#include "CStatePoster.h"
#include <stdio.h>

CStateLogo::CStateLogo():m_iCount(0), CState("CStateLogo")
{}

void CStateLogo::Init()
{
	printf("State Logo: Init\n");
	m_iCount = 0;
}

void CStateLogo::Update()
{
	m_iCount++;
	if (m_iCount >= 10)
	{
		CStateManagement::GetInstance()->SwitchState(new CStatePoster());
	}
}

void CStateLogo::Render()
{
	printf("State Logo: %d\n", m_iCount);
}

void CStateLogo::Exit()
{
	printf("State Logo: Exit\n");
}
#include "CGame.h"
#include <stdio.h>
#include <unistd.h>
#include "CStateManagement.h"

namespace GameTutor
{
	CGame* CGame::s_pInstance = 0;

	CGame::CGame(): m_isPaused(false), m_isAlived(true)
	{
		s_pInstance = this;
	}

	void CGame::Pause()
	{
		m_isPaused = true;
	}

	void CGame::Resume()
	{
		m_isPaused = false;
	}

	void CGame::Exit()
	{
		m_isAlived = false;
	}

	void CGame::Run()
	{
		this->Init();
		while (m_isAlived)
		{
			if (m_isPaused)
			{
				CStateManagement::GetInstance()->Update(true);
			}
			else
			{
				CStateManagement::GetInstance()->Update(false);
			}
			usleep(16.67*1000);
		}
		Destroy();
	}
}
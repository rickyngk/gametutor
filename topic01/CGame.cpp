//CGame.cpp
#include "CGame.h"
#include <stdio.h>
#include <unistd.h>

namespace GameTutor
{
	CGame::CGame(): 
		m_isPaused(false), 
		m_isAlived(true){}
	
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
				printf("paused\n");
			}
			else
			{
				printf("running\n");
			}
			usleep(16.67*1000);
		}
		Destroy();
	}
}
#ifndef __CSTATEMAINMENU_H__
#define __CSTATEMAINMENU_H__

#include "cstate.h"
using namespace GameTutor;

class CStateMainMenu :public CState
{
public:
	CStateMainMenu();
	~CStateMainMenu() {}
	
	void Init();
	void Update();
	void Render();
	void Exit();

private:
	int m_iCount;
};

#endif
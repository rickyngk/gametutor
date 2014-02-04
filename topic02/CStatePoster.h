#ifndef __CSTATEPOSTER_H__
#define __CSTATEPOSTER_H__

#include "cstate.h"
using namespace GameTutor;

class CStatePoster :public CState
{
public:
	CStatePoster();
	~CStatePoster() {}
	
	void Init();
	void Update();
	void Render();
	void Exit();

private:
	int m_iCount;
};

#endif
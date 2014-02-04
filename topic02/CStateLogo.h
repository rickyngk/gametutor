#ifndef __CSTATELOGO_H__
#define __CSTATELOGO_H__
#include "CState.h"
using namespace GameTutor;

class CStateLogo: public CState
{
public:
	CStateLogo();
	~CStateLogo() {}

	void Init();
	void Update();
	void Render();
	void Exit();
private:
	int m_iCount;
};
#endif
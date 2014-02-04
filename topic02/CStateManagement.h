#ifndef __CSTATEMANAGEMENT_H__
#define __CSTATEMANAGEMENT_H__
#include "CState.h"

namespace GameTutor
{
	class CStateManagement
	{
	public:
		static CStateManagement* GetInstance() 
		{
			if (!s_pIntance) 
			{
				s_pIntance = new CStateManagement();
			}
			return s_pIntance;
		}
	protected:
		static CStateManagement* s_pIntance;
	protected:
		CStateManagement():m_pCurrentState(0), m_pNextState(0) {}
	protected:
		CState* m_pCurrentState;
		CState* m_pNextState;
	public:
		void Update(bool isPause);
		void SwitchState(CState* nextState);
	};
}
#endif
#ifndef __CSTATEMANAGEMENT_H__
#define __CSTATEMANAGEMENT_H__
#include <stdio.h>
#include "CState.h"
#include "macro.h"

#define SAVE_STATE_TRACE 0

namespace GameTutor
{

#if SAVE_STATE_TRACE
	template <typename T> class TCStateTrace { 
		public:
			int step;
			T val;
			TCStateTrace<T>* prev;
			TCStateTrace(T _val, TCStateTrace<T>* _prev = 0): val(_val), prev(_prev) {
				if (prev) {
					step = prev->step + 1;
				}
				else {
					step = 0;
				}
			}
	}; 
	typedef const char* CStateTraceEle;
	typedef TCStateTrace<CStateTraceEle> CStateTrace;
#endif

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
		CStateManagement():
			m_pCurrentState(0), 
			m_pNextState(0), 
#if SAVE_STATE_TRACE
			m_pStateTrace(0),
#endif
			m_LastState(0) {}
	protected:
		CState* m_pCurrentState;
		CState* m_pNextState;

	public:
		void Update(bool isPause);
		void SwitchState(CState* nextState);

#if SAVE_STATE_TRACE
	public:
		void CleanTrace();
		CStateTraceEle PopStateTrace();
	protected:
		CStateTrace* m_pStateTrace;
#endif

		PROP_READ_ONLY(const char *,LastState);
	};
}
#endif
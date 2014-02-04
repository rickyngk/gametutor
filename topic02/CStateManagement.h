#ifndef __CSTATEMANAGEMENT_H__
#define __CSTATEMANAGEMENT_H__
#include <stdio.h>
#include "CState.h"
#include "macro.h"

#define USE_STATE_TRACE 0
#define USE_STATE_STACK 1

namespace GameTutor
{

#if SAVE_STATE_TRACE || USE_STATE_STACK
	template <typename T> class TCStateStack { 
		public:
			int step;
			T val;
			TCStateStack<T>* prev;
			TCStateStack(T _val, TCStateStack<T>* _prev = 0): val(_val), prev(_prev) {
				if (prev) {
					step = prev->step + 1;
				}
				else {
					step = 0;
				}
			}
	}; 
#endif

#if USE_STATE_TRACE
	typedef const char* CStateTraceEle;
	typedef TCStateStack<CStateTraceEle> CStateTrace;
#endif

#if USE_STATE_STACK
	typedef CState* CStateStackEle;
	typedef TCStateStack<CStateStackEle> CStateStack;
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
#if USE_STATE_TRACE
			m_pStateTrace(0),
#endif
#if USE_STATE_STACK
			m_pStateStack(0),
#endif
			m_LastState(0) {}
	protected:
		CState* m_pCurrentState;
		CState* m_pNextState;

	public:
		void Update(bool isPause);
		void SwitchState(CState* nextState);

#if USE_STATE_TRACE
	public:
		void CleanTrace();
	protected:
		CStateTrace* m_pStateTrace;
#endif

#if USE_STATE_STACK
	public:
		void EmptyStateStack();
		void PushState(CState*);
		void PopState();
	protected:
		CStateStack* m_pStateStack;
#endif

		PROP_READ_ONLY(const char *,LastState);
	};
}
#endif
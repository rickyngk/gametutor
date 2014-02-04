#include "CStateManagement.h" 

namespace GameTutor
{
	CStateManagement* CStateManagement::s_pIntance = 0;

	void CStateManagement::Update(bool isPause)
	{
		// check if need switch state
		if (m_pCurrentState != m_pNextState)
		{
			if (m_pCurrentState) 
			{
				printf("[CStateManagement] Leave state %s \n", m_pCurrentState->GetId());

#if USE_STATE_TRACE
				//save state tracking
				if (!m_pStateTrace) 
				{
					m_pStateTrace = new CStateTrace(m_pCurrentState->GetId());
				}
				else 
				{
					m_pStateTrace = new CStateTrace(m_pCurrentState->GetId(), m_pStateTrace);
				}
#endif

				//save last state
				SetLastState(m_pCurrentState->GetId());

				m_pCurrentState->Exit();

				// by default, state will be always deleted, but USE_STATE_STACK
				if (m_pCurrentState->GetDeleteAfterSwitchingFlag()) 
				{
					delete m_pCurrentState;
					m_pCurrentState = 0;
				}
			}
			if (m_pNextState) 
			{
				printf("[CStateManagement] Enter state %s \n", m_pNextState->GetId());
				m_pNextState->Init();
			}
			m_pCurrentState = m_pNextState;
		}

		//update state
		if (m_pCurrentState)
		{
			if (!isPause)
			{
				m_pCurrentState->Update();
			}
			m_pCurrentState->Render();
		}
	}

	void CStateManagement::SwitchState(CState* nextState)
	{
		if (m_pCurrentState) {
			printf("[CStateManagement] request switching state from %s to %s \n", m_pCurrentState->GetId(), nextState->GetId());
		}
		m_pNextState = nextState;
	}

#if USE_STATE_TRACE
	void CStateManagement::CleanTrace() {
		while (m_pStateTrace) {
			CStateTrace* tmp = m_pStateTrace;
			m_pStateTrace = m_pStateTrace->prev;
			delete tmp;
		}
	}
#endif

#if USE_STATE_STACK
	void CStateManagement::EmptyStateStack()
	{
		while (m_pStateStack) 
		{
			CStateStack *tmp = m_pStateStack;
			m_pStateStack = m_pStateStack->prev;
			delete tmp;
		}
	}
		
	void CStateManagement::PushState(CState* state) 
	{
		if (!m_pStateStack) 
		{
			m_pStateStack = new CStateStack(m_pCurrentState);
		}
		else 
		{
			m_pStateStack = new CStateStack(m_pCurrentState, m_pStateStack);
		}
		m_pCurrentState->SetDeleteAfterSwitchingFlag(false); //disable delete state instance after switching
		SwitchState(state);
		printf("[CStateManagement] PushState %s \n", state->GetId());
	}

	void CStateManagement::PopState() 
	{
		if (m_pStateStack) 
		{
			CStateStack *tmp = m_pStateStack;
			m_pStateStack = m_pStateStack->prev;
			tmp->val->SetDeleteAfterSwitchingFlag(true); //allow delete state instance after switching
			SwitchState(tmp->val);
			printf("[CStateManagement] PopState %s \n", tmp->val->GetId());
		}
	}
#endif
}






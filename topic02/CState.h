#ifndef __CSTATE_H__
#define __CSTATE_H__

#include <stdio.h>
#include "macro.h"

namespace GameTutor
{
	class CState
	{
		public:
			CState(const char* id = 0){
				printf("[CState] alloc state id %s\n", id);
				this->SetId(id);
				this->SetDeleteAfterSwitchingFlag(true);
			}
			virtual ~CState() {
				printf("[CState] free state %s \n", GetId());
			}
			virtual void Init() = 0;
			virtual void Update() = 0;
			virtual void Render() = 0;
			virtual void Exit() = 0;
		PROP_READ_ONLY(const char*, Id);
		PROP_READ_WRITE(bool, DeleteAfterSwitchingFlag);
	};
}
#endif
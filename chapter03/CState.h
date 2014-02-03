#ifndef __CSTATE_H__
#define __CSTATE_H__

namespace GameTutor
{
	class CState
	{
		public:
			CState(){}
			virtual ~CState(){}
			virtual void Init() = 0;
			virtual void Update() = 0;
			virtual void Render() = 0;
			virtual void Exit() = 0;
	};
}
#endif
//CExample.cpp
#include "CExample.h"
#include "CStateLogo.h"
#include "CStateManagement.h"
#include "stdio.h"

void CExample::Init()
{
	CStateManagement::GetInstance()->SwitchState(new CStateLogo());
	printf("Init\n");
}

void CExample::Destroy()
{
	printf("Destroy\n");
}

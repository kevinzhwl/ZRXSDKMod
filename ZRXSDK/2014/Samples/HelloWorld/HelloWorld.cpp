// HelloWorld.cpp : 
//

#include "stdafx.h"
#include "tchar.h"
#include <aced.h>
#include <rxregsvc.h>

void initApp();
void unloadApp();

void helloWorld();

void initApp()
{ 
	// register a command with the AutoCAD command mechanism
	acedRegCmds->addCommand("HELLOWORLD_COMMANDS",
							"Hello",
							"Hello",
							ACRX_CMD_TRANSPARENT,
							helloWorld);
}


void unloadApp()
{ 
	acedRegCmds->removeGroup("HELLOWORLD_COMMANDS");
}


void helloWorld()
{ 
	acutPrintf("\nHello World!");
}

extern "C" AcRx::AppRetCode
zcrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		initApp();
		break;
	case AcRx::kUnloadAppMsg:
		unloadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}



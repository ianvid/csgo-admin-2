#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <stdio.h>
#include "signature.h"

namespace module {
	//===============|MODULES|=================================
	DWORD client = (DWORD)GetModuleHandle("client.dll");
	DWORD engine = (DWORD)GetModuleHandle("engine.dll");
}

namespace offset {
	//===============|+MODULOS|=================================
	// + client.dll
	DWORD EntityList = 0x4DC177C; //not in hazedumper hexa x mio es 0x4DBF764 
	DWORD PlayerBase = 0xDA747C; // dwLocalPlayer dword
	DWORD ForceJump = 0x526B590; //dwForceJump  byte 04||05
	DWORD ForceShoot = 0x31F1C94;
	

	// + engine.dll
	DWORD ClientState = 0x589FCC; //dword dwClientState

	//===============|+BASES|=================================
	// + PlayerBase
	DWORD isGrounded = 0x104; //m_fFlags int 256||257 
	DWORD flashbangHex = 0x1046C; //not in hazedumper 255||0
	DWORD CrosshairId = 0x11838;

	// + entitybase
	DWORD team = 0xF4; //m_iTeamNum  (ct) 3|| (t) 2
	DWORD Health = 0x100;//m_iHealth  int
	DWORD isSpotted = 0x980; //m_bSpottedByMask binary mask 

	// + ClientState
	DWORD dwClientState_GetLocalPlayer = 0x180;

	//+isMenuOpenBase
	DWORD isMenuOpen = 0x0;
}

//===============|POINTERS|=================================
namespace pointer {
	//pointers
	DWORD entityListptr = (DWORD)(module::client + offset::EntityList);
	DWORD localPlayerptr = (DWORD)(module::client + offset::PlayerBase);
}
//===============|variables or static de-referenced|=================================
namespace base {
	DWORD isMenuOpenBase = 0x0;
	DWORD localPlayer = 0x0;
	DWORD entityList = 0x0;
	DWORD clientState = *(DWORD*)(module::engine + offset::ClientState);
}


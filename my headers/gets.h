#include "Offsets.h"

namespace get {
	bool EntityList() { //por ahora no necesita desreferenciar
		//if (*(DWORD*)pointer::entityListptr == NULL || 0x0) { return false; }
		base::entityList = (DWORD)pointer::entityListptr;
		return  true;
	}
	bool LocalPlayerBase() {
		if (*(DWORD*)pointer::localPlayerptr == NULL || 0x0) { return false; }
		base::localPlayer = *(DWORD*)pointer::localPlayerptr; 
		return true; 
	}
	bool ClientState() {
		if (*(DWORD*)pointer::localPlayerptr == NULL || 0x0) { return false; }
		base::clientState = *(DWORD*)(pointer::clientStateptr);
		return true;
	}
}
namespace localplayer {
	int playercode() {
		return *(int*)(base::clientState + offset::dwClientState_GetLocalPlayer);
	}
	DWORD teamcode() {
		DWORD output = *(DWORD*)(base::localPlayer + offset::team);
		return output;
	}
	
	int onsight() {
		return *(int*)(base::localPlayer + offset::CrosshairId);
	}

	bool isgrounded() {
		if (*(int*)(base::localPlayer + offset::isGrounded) == 257) { 
			return true;
		}
		else {
			return false;
		}
	}

	void forcejump() {
		*(int*)(module::client + offset::ForceJump) = 5;
	}
	void forcenotjump() {
		*(int*)(module::client + offset::ForceJump) = 4;
	}
	void forceshoot() {
		*(int*)(module::client + offset::ForceShoot) = 5;
		Sleep(10);
		*(int*)(module::client + offset::ForceShoot) = 4;
	}
	void forcenotshoot() {
		*(int*)(module::client + offset::ForceShoot) = 4;
	}
	float getpos(int wich) {
		float x, y, z;
		switch (wich) {
		case 1:
			x = *(float*)(base::localPlayer + offset::positionX);
			return x;
			break;
		case 2:
			y = *(float*)(base::localPlayer + offset::positionY);
			return y;
			break;
		case 3:
			z = *(float*)(base::localPlayer + offset::positionZ);
			return z;
			break;
		}

	}
	float getviewangle(int wich) {
		float x, y;
		switch (wich) {
		case 1:
			x = *(float*)(base::clientState + offset::ViewAngleX);
			return x;
			break;
		case 2:
			y = *(float*)(base::clientState + offset::ViewAngleY);
			return y;
			break;
		}

	}
	void setviewangle(float x,float y) {
			*(float*)(base::clientState + offset::ViewAngleX) = x;
			*(float*)(base::clientState + offset::ViewAngleY) = y;
	}
}
namespace entity {
	DWORD* entptr(int iterator) {
		DWORD* output = (DWORD*)((DWORD)base::entityList + (iterator * 0x10));
		return output;
	}
	bool isdormant(DWORD currentEnt) {
		bool output = *(bool*)(currentEnt + offset::dormant);
		return output;
	}
	int health(DWORD currentEnt) {
		int output = *(int*)(currentEnt + offset::Health);
		return output;
	}
	DWORD team(DWORD currentEnt) {
		DWORD output = *(DWORD*)(currentEnt + offset::team);
		return output;
	}
	float getpos(int wich, DWORD currentEnt) {
		float x, y, z;
		switch (wich){
			case 1:
				 x = *(float*)(currentEnt + offset::positionX);
				return x;
				break;
			case 2:
				 y = *(float*)(currentEnt + offset::positionY);
				return y;
				break;
			case 3:
				 z = *(float*)(currentEnt + offset::positionZ);
				return z;
				break;
		}
	
	}
	float gethead(int wich, DWORD currentEnt) {
		DWORD bonebase = *(DWORD*)(currentEnt + offset::BoneMatrix);
		float x, y, z;
		switch (wich) {
		case 1:
			 x = *(float*)(bonebase + 0x30 * 8 + 0xC);
			return x;
			break;
		case 2:
			 y = *(float*)(bonebase + 0x30 * 8 + 0x1C);
			return y;
			break;
		case 3:
			 z = *(float*)(bonebase + 0x30 * 8 + 0x2C);
			return z;
			break;
		}
	}
}

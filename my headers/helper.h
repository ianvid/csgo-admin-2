#pragma once
#include "Offsets.h"
#include <bitset>
#include "gets.h"
#include "aimbot.h"
#include "hackbools.h"

#include "esp.h"


namespace action {

    //========================|AUTOACCEPT|================================

    void radarHack() {
        get::EntityList(); 
        get::LocalPlayerBase();
        if (get::ClientState() == false) { return; }

        for (int i = 1; i < 64; i++) {
            DWORD* entptr = entity::entptr(i);
            if (*entptr == 0x0 || NULL) { continue; }
            DWORD currentEnt = *entptr;
            std::bitset<32> x = *(int*)(currentEnt + offset::isSpotted);
            x[localplayer::playercode()] = 1; //va desde derecha a izquierda en la mascara la cantidad de veces que el teamcode indique, ese bit se pone en 1
            *(int*)(currentEnt + offset::isSpotted) = (int)(x.to_ulong());
        }
    }

    void bunnyJump() {
        if (get::LocalPlayerBase() == false) { return; }

        if (localplayer::isgrounded()) {
            if (GetAsyncKeyState(0x20) & 0x8000) {
                localplayer::forcejump();
            }
            else {
                localplayer::forcenotjump();
            }
        }
        else {
            localplayer::forcenotjump();
        }
    }
    int tick = 0;
    void triggerBot() {
        DWORD team = 0x0;
        DWORD myteam = 0x0;
        bool aimteam = hackbools::triggerbot::targetTeam;

        

        if (get::LocalPlayerBase() == false) {  return; }

        if (get::EntityList() == false) { return; }

        DWORD onsight = localplayer::onsight();
        

        if (onsight <= 64 && onsight > 1) {}  else { return; }
        DWORD* entptr = (DWORD*)(base::entityList + (0x10 * (onsight - 0x1)));
        DWORD currentEnt = *entptr;
        team = entity::team(currentEnt);
        myteam = localplayer::teamcode();
        if (!aimteam) {
            if (team == myteam) { return; }
        }
        if (GetAsyncKeyState(0x12) & 0x8000) {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            if (tick==2) {
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                tick = 0;
            }
            tick++;
           
           
            
        }

    }
    void aimbotheader() {
        aimbot();
    }

    void esplineheader() {
        espline();
    }



}




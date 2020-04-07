#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <sstream>
#include <string.h>
#include "movement.h"
#include "monster.h"

using namespace std;
/*!
 *\ brief The Game class
 */
class Game
{
    public:
        Game();
        monster enemy; // KOMPOZIJA KLASIU JUNGIMAS

        cmap m; // KOMPOZIJA KLASIU JUNGIMAS
        Movement mv;
        bool running = true;
        int x; // hero x
        int y; // hero y
        int old_x;
        int old_y;
        // GYVYBE
        int life = 0;
        int lx = 3;
        int ly = 3;
        // PRIESAS
        int ex = 1;
        int ey = 1;
        // TASKAI
        int pts = 0;
        // SPEED EFFECTAS
        int EffectOnSpeed = 0;
        int sx = 8;
        int sy = 10;
        int speedmod = 3;
        // TELEPORTAS ( ISIGELBEJIMAS NUO EATERIO )
        int EffectTeleport = 0;
        int tx = 48;
        int ty = 12;
        // LYGIO PASIRINKIMAS
        char mode;
         /*!
        *\ brief This function is for game start, all functions in this.
        */
        void Start();
        ~Game();

    protected:

    private:
    /*!
        *\ brief This function gives a life
        */
    void LifeEffect();
     /*!
        *\ brief This function makes game over
        */
    void GameOver();
     /*!
        *\ brief This function gives a speed
        */
    void OnSpeedEffect();
     /*!
        *\ brief This function gives opportunity to choose a level
        */
    void chooseLevel();
     /*!
        *\ brief This function teleports hero to start position
        */
    void TeleportToStart();
};

#endif // GAME_H

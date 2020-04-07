#ifndef MOVEMENT_H
#define MOVEMENT_H
#include <windows.h>
#include <string>
#include <vector>
#include "cmap.h"
class Movement
{
    public:
        cmap m; // KOMPOZIJA KLASIU JUNGIMAS
        Movement();
        int taskai = 0;
         /*!
        *\ brief This function is for moving to x, y
        *\ param parameter - short x and short y is for enemy position
        */
        void gotoxy( short x, short y );
         /*!
        *\ brief This function is just overload for gotoxy
        *\ param parameter - int x and int y is for enemy position
        */
        void gotoxy( int x, int y ); // OVERLOAD
         /*!
        *\ brief This function is for hero moving
        *\ param parameter - int x and int y is for enemy position
        */
        void HeroMove(int & x, int & y);
         /*!
        *\ brief This function is for hero moving on speed effect
        */
        void MoveOnSpeed(int & x, int & y);
        void gotoxy( float x, float y );
        ~Movement();

    protected:

    private:

};

#endif // MOVEMENT_H

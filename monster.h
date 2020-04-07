#ifndef MONSTER_H
#define MONSTER_H
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include "cmap.h"
using std::vector;
/*!
 *\ brief The Monster class
 */
class monster
{
    public:
        cmap m;
        monster();
        char tmp_map[21][51];

       void moveMonster(int &MonsterX, int &MonsterY,int &PlayerX, int &PlayerY);
        ~monster();

    protected:

    private:
};

#endif // MONSTER_H

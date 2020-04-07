#include "monster.h"
#include <time.h>
monster::monster()
{
    //ctor
}
void monster::moveMonster(int &MonsterX, int &MonsterY,int &PlayerX, int &PlayerY)
{
     srand(time(0));
    memcpy( tmp_map, m.map, sizeof(m.map) ); // tmp_map paverciam m.map perkopijuojam visus simbolius char
    int distancex = PlayerX - MonsterX;
    int distancey = PlayerY - MonsterY;

    if (distancex > 0)
    {
        if(tmp_map[MonsterY][MonsterX] != '#')
        {
            MonsterX++;
        }
        else
        {
            MonsterX--;
            MonsterY++;
        }

    }

    else if (distancex < 0)
    {
        if(tmp_map[MonsterY][MonsterX] != '#')
        {
            MonsterX--;
        }
        else{

           MonsterX++;
            MonsterY--;
        }

    }

if (distancey > 0)
    {
        if(tmp_map[MonsterY][MonsterX] != '#')
        {
            MonsterY++;
        }
        else
        {
            MonsterX++;
           MonsterY--; // MonsterY = rand() % 13 + 1;
        }

    }

    else if (distancey <0)
    {
        if(tmp_map[MonsterY][MonsterX] != '#')
        {
            MonsterY--;
        }
        else
        {
            MonsterX--;
           MonsterY++; // MonsterY = rand() % 13 + 1;
        }

    }


}

monster::~monster()
{
    //dtor
}

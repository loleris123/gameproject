#include "cmap.h"

cmap::cmap()
{
    count++;
    //ctor
}
void cmap::ShowMap()
{
	for(int i = 0; i < 21; i++) {
		printf("%s\n",map[i] );


	}
}
cmap::~cmap()
{
    //dtor
}

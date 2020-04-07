#include "movement.h"

Movement::Movement()
{
    //ctor
}
void Movement::gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; // duoda valdyma konsolei komandos is windows.h bibliotekos
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ; //  duoda pilna valdyma zymeklio pozicijai
}
void Movement::gotoxy( int x, int y ) // funkcijos overwrite
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ;
}
void Movement::gotoxy( float x, float y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ; // duoda valdyma konsolei komandos is windows.h bibliotekos
    COORD position = { x, y } ;

    SetConsoleCursorPosition( hStdout, position ) ; //  duoda pilna valdyma zymeklio pozicijai
}
void Movement::HeroMove(int & x, int & y)
{
    if ( GetAsyncKeyState( VK_UP ) ){
			if( m.map[y-1][x] == '.' ){ y--;} else // . yra taskai kuriuos meto mobas
			if( m.map[y-1][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( m.map[y+1][x] == '.' ){ y++;} else
			if( m.map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( m.map[y][x-1] == '.' ){ x--;} else
			if( m.map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( m.map[y][x+1] == '.' ){ x++; } else
			if( m.map[y][x+1] == ' ' ) x++;
		}

}
void Movement::MoveOnSpeed(int & x, int & y)
{
    if ( GetAsyncKeyState( VK_UP ) ){
			if( m.map[y-2][x] == '.' ){ y--;} else
			if( m.map[y-2][x] == ' ' ) y--;
		}
		if ( GetAsyncKeyState( VK_DOWN ) ){
			if( m.map[y+1][x] == '.' ){ y++;} else
			if( m.map[y+1][x] == ' ' ) y++;
		}
		if ( GetAsyncKeyState( VK_LEFT ) ){
			if( m.map[y][x-1] == '.' ){ x--;} else
			if( m.map[y][x-1] == ' ' ) x--;
		}
		if ( GetAsyncKeyState( VK_RIGHT ) ){
			if( m.map[y][x+1] == '.' ){ x++; } else
			if( m.map[y][x+1] == ' ' ) x++;
		}
}
Movement::~Movement()
{
    //dtor
}
int cmap::count =0;

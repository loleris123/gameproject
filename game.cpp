#include "game.h"

Game::Game()
{
    x = 15;
    y = 16;
}
void Game::Start()
{
    try {
      chooseLevel();

   } catch (const char* msg) {
     cerr << msg << endl;
   }

	system("cls");
    m.ShowMap();

	mv.gotoxy( x, y ); cout << "H";
    mv.gotoxy( 52, 0); cout << "Score";
	int frame = 0;

	mv.gotoxy(lx,ly); cout << "L"; // GYVYBE
	mv.gotoxy(sx,sy); cout << "S"; // Speed effectas
	mv.gotoxy(tx,ty); cout << "T"; // TELEPORTAS
	while( running ){
		mv.gotoxy( x, y ); cout << " "; // Visalaik kur vaikstom su heroju padarom tustuma
		mv.HeroMove(x,y);
		mv.gotoxy( ex, ey ); cout << " ";
		if(m.map[x][y] == '.' || m.map[y][x] == '.')
        {
            pts++;
        }

            old_x = ex;
            old_y = ey;
			enemy.moveMonster( ex,ey,x,y );


        mv.gotoxy( x,y ); cout << "H";

        mv.gotoxy( ex, ey ); cout << "E";
        m.map[ey][ex] = '.';
        mv.gotoxy(old_x, old_y); cout << ".";



        LifeEffect();
        GameOver();
        OnSpeedEffect();
        TeleportToStart();


		mv.gotoxy( 58, 0 ); cout << pts;
		Sleep( 100 );
		frame++;
	}

	system("cls");
	printf("You Lose and your score is : %i", pts );
	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
}
void Game::LifeEffect()
{
    if(lx == x && ly == y)
    {
        life = 1;
        mv.gotoxy(lx,ly); cout << " ";
        lx = -100; // .__.
        ly = -100; // Pakeiciama pozicija gyvybes i neegzistuojancia, kad antra kart negaletu pasiimti gyvybes
    }
    if( ex == x && ey == y && life == 1)
    {
        life = 0;
        ex = ex - 2;
        ey = ey - 2;
        running = true;
    }

}
void Game::GameOver()
{
    if( ex == x && ey == y && life == 0)
    {
        running = false;
    }
}
void Game::OnSpeedEffect()
{
    if(sx == x && sy == y)
    {
        EffectOnSpeed = 50;
        mv.gotoxy(sx,sy); cout << " ";
        sx = -100; // .__.
        sy = -100; // Pakeiciama pozicija i neegzistuojancia, kad antra kart negaletu pasiimti speed effecto
        while(EffectOnSpeed > 0)
        {
            mv.MoveOnSpeed(x,y);
            EffectOnSpeed--;

        }
    }

}
void Game::TeleportToStart()
{
    if(tx == x && ty == y)
    {
        if(x > 51 || y > 21)
        {
            throw "Out of map";
        }

        x = 15;
        y = 16;
        mv.gotoxy(tx,ty); cout << " ";
        tx = -100; // .__.
        ty = -100; // Pakeiciama pozicija  i neegzistuojancia, kad antra kart negaletu teleportuotis
    }

}
void Game::chooseLevel()
{
    printf("Instruction:\n1. At the bottom of the map you'll see your hero H, you can move it with ARROWS on your keyboard\n2. Eater E produces dots . you can eat them to to gain points\n3. Your purpose is to gain more points by avoiding Eater E\n4. Letter L is Life when you pick it up you can continue game one more time when eaten by Eater \n5. Letter T can teleport you to spawn position and it can help you to avoid Eater\n6. Letter S can give you a speed boost for 3 seconds \n\n");
    printf("Choose level: \n");
	printf("H -> Hard\nN -> Normal\nE -> Easy\n\nInput : ");

	cin >> mode;

	if( mode == 'N' ){
		speedmod = 2;
	}else if( mode == 'H' ){
		speedmod = 1;
	}
	else
    {
        throw "Wrong game mode chosen";
        chooseLevel();
    }
}
template <class T> // TO STRING ??
std::string to_string(const T& object) {
    std::ostringstream ss;
    ss << object;
    return ss.str();
}
Game::~Game()
{
    //dtor
}

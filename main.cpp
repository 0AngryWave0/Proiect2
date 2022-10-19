#include <stdlib.h> //Standard c and c++ libraries
#include <conio.h>
#include <stdio.h>
#include <windows.h> // To take control over the terminal
#include <list>
#include <cstdlib>
using namespace std;
#define UP    72 // arrow keys' ascii numbers
#define LEFT  75
#define RIGHT 77
#define DOWN  80

void gotoxy(int x, int y)
{ // Permite deplasarea în interiorul terminalului folosind coordonate
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
COORD dwPos;
dwPos.X = x; // Porneste de la 0
dwPos.Y = y; // Porneste de la 0
SetConsoleCursorPosition(hCon, dwPos);
}

void HideCursor()
{ // Ascunde cursorul
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cci;
cci.dwSize = 1;
cci.bVisible = FALSE;
SetConsoleCursorInfo(hCon, &cci);
}

void DrawWhiteSpace(int a_x, int a_y, int b_x, int b_y)
{ // Pentru a curata un spatiu din terminal
    for(int i = a_x; i < b_x; i++)
   {
     for(int j = a_y; j < b_y; j++)
    {
      gotoxy(i,j); printf(" ");
    }
   }
}

void DrawWindowFrame(int a_x, int a_y, int b_x, int b_y)
{ // Va crea un dreptunghi definit de 2 puncte

 DrawWhiteSpace(a_x,a_y,b_x,b_y);

   for(int i = a_x; i < b_x; i++)
  {
   gotoxy(i, a_y); printf("%c", 205);
   gotoxy(i, b_y); printf("%c", 205);
  }

    for(int i = a_y; i < b_y; i++)
   {
   gotoxy(a_x, i); printf("%c", 186);
   gotoxy(b_x, i); printf("%c", 186);
   }

 gotoxy(a_x, a_y); printf("%c", 201);
 gotoxy(b_x, a_y); printf("%c", 187);
 gotoxy(a_x, b_y); printf("%c", 200);
 gotoxy(b_x, b_y); printf("%c", 188);
}


void DrawGameLimits()
{ // Deseneaza limitele jocului și informațiile care nu trebuie tipărite în mod repetat
  DrawWindowFrame(1,2,115 ,28); //Dimensiunea implicită a terminalului Windows este de 25 de rânduri x 80 de coloane

  gotoxy( 2,1); printf("HP:");
  gotoxy(16,1); printf("ENERGY:");
  gotoxy(34,1); printf("AMMO:");
  for(int k=1;k<=7;k++){
         gotoxy(38+k,1); printf("%c",222);}
  gotoxy(60,1); printf("SCORE:");

}


void WelcomeMessage()
{ // Titlul principal
int x = 30;
int y = 12;

 gotoxy(x, y  ); printf(" _____                    _____ _           _           ");
 gotoxy(x, y+1); printf("|   __|___ ___ ___ ___   |   __| |_ ___ ___| |_ ___ ___ ");
 gotoxy(x, y+2); printf("|__   | . | .'|  _| -_|  |__   |   | . | . |  _| -_|  _|");
 gotoxy(x, y+3); printf("|_____|  _|__,|___|___|  |_____|_|_|___|___|_| |___|_|  ");
 gotoxy(x, y+4); printf("      |_|                                               ");
 gotoxy(x, y+6); printf("                 Press any key to play                  ");
}


void GameOverDefeatMessage()
{ // Cand pierzi jocul, acest mesaj va aparea pe ecran
 int a_x = 30;
 int a_y = 12;

gotoxy(a_x-16,a_y+2); printf("'########::'########:'########:'########::::'###::::'########:'####:'####:'####:");
gotoxy(a_x-16,a_y+3); printf(" ##.... ##: ##.....:: ##.....:: ##.....::::'## ##:::... ##..:: ####: ####: ####:");
gotoxy(a_x-16,a_y+4); printf(" ##:::: ##: ##::::::: ##::::::: ##::::::::'##:. ##::::: ##:::: ####: ####: ####:");
gotoxy(a_x-16,a_y+5); printf(" ##:::: ##: ######::: ######::: ######:::'##:::. ##:::: ##::::: ##::: ##::: ##::");
gotoxy(a_x-16,a_y+6); printf(" ##:::: ##: ##...:::: ##...:::: ##...:::: #########:::: ##:::::..::::..::::..:::");
gotoxy(a_x-16,a_y+7); printf(" ##:::: ##: ##::::::: ##::::::: ##::::::: ##.... ##:::: ##::::'####:'####:'####:");
gotoxy(a_x-16,a_y+8); printf(" ########:: ########: ##::::::: ########: ##:::: ##:::: ##:::: ####: ####: ####:");
gotoxy(a_x-16,a_y+9); printf("........:::........::..::::::::........::..:::::..:::::..:::::....::....::....::");

}


void GameOverVictoryMessage()
{ // Cand castigi jocul acest mesaj va aparea pe ecran
int a_x = 30;
int a_y = 11;

gotoxy(a_x-16,a_y+2); printf("'##::::'##:'####::'######::'########::'#######::'########::'##:::'##:'####:'####:'####:");
gotoxy(a_x-16,a_y+3); printf(";##:::: ##:. ##::'##... ##:... ##..::'##.... ##: ##.... ##:. ##:'##:: ####: ####: ####:");
gotoxy(a_x-16,a_y+4); printf(" ##:::: ##:: ##:: ##:::..::::: ##:::: ##:::: ##: ##:::: ##::. ####::: ####: ####: ####:");
gotoxy(a_x-16,a_y+5); printf(" ##:::: ##:: ##:: ##:::::::::: ##:::: ##:::: ##: ########::::. ##::::: ##::: ##::: ##::");
gotoxy(a_x-16,a_y+6); printf(". ##:: ##::: ##:: ##:::::::::: ##:::: ##:::: ##: ##.. ##:::::: ##:::::..::::..::::..:::");
gotoxy(a_x-16,a_y+7); printf(":. ## ##:::: ##:: ##::: ##:::: ##:::: ##:::: ##: ##::. ##::::: ##::::'####:'####:'####:");
gotoxy(a_x-16,a_y+8); printf("::. ###::::'####:. ######::::: ##::::. #######:: ##:::. ##:::: ##:::: ####: ####: ####:");
gotoxy(a_x-16,a_y+9); printf(":::...:::::....:::......::::::..::::::.......:::..:::::..:::::..:::::....::....::....::");
}


void SpecialMessage()
{ // Un mesaj special
 DrawWhiteSpace(1,1,170,29);

 gotoxy(30,11); printf(" .--.                .-.  .-.              .-.                        .-.    .-.  _                ");
 gotoxy(30,12); printf(": .--'               : :  : :              : :.-.                    .' `.  .' `.:_;               ");
 gotoxy(30,13); printf(": : _  .--.  .--.  .-' :  : :  .-..-. .--. : `'.'  ,-.,-. .--. .-.,-.`. .'  `. .'.-.,-.,-.,-. .--. ");
 gotoxy(30,14); printf(": :; :' .; :' .; :' .; :  : :_ : :; :'  ..': . `.  : ,. :' '_.'`.  .' : :    : : : :: ,. ,. :' '_.'");
 gotoxy(30,15); printf("`.__.'`.__.'`.__.'`.__.'  `.__;`.__.'`.__.':_;:_;  :_;:_;`.__.':_,._; :_;    :_; :_;:_;:_;:_;`.__.'");
}

void EndGame()
{
 DrawWhiteSpace(1,1,249,29);

 gotoxy(10,10); printf("d8888b. d8888b. d88888b .d8888. .d8888.    .d8b.  d8b   db db    db   db   dD d88888b db    db   d888888b  .d88b.     .o88b.  .d88b.  d8b   db d888888b d888888b d8b   db db    db d88888b ");
 gotoxy(10,11); printf("88  `8D 88  `8D 88'     88'  YP 88'  YP   d8' `8b 888o  88 `8b  d8'   88 ,8P' 88'     `8b  d8'   `~~88~~' .8P  Y8.   d8P  Y8 .8P  Y8. 888o  88 `~~88~~'   `88'   888o  88 88    88 88'     ");
 gotoxy(10,12); printf("88oodD' 88oobY' 88ooooo `8bo.   `8bo.     88ooo88 88V8o 88  `8bd8'    88,8P   88ooooo  `8bd8'       88    88    88   8P      88    88 88V8o 88    88       88    88V8o 88 88    88 88ooooo ");
 gotoxy(10,13); printf("88~~~   88`8b   88~~~~~   `Y8b.   `Y8b.   88~~~88 88 V8o88    88      88`8b   88~~~~~    88         88    88    88   8b      88    88 88 V8o88    88       88    88 V8o88 88    88 88~~~~~ ");
 gotoxy(10,14); printf("88      88 `88. 88.     db   8D db   8D   88   88 88  V888    88      88 `88. 88.        88         88    `8b  d8'   Y8b  d8 `8b  d8' 88  V888    88      .88.   88  V888 88b  d88 88.     ");
 gotoxy(10,15); printf("88      88   YD Y88888P `8888Y' `8888Y'   YP   YP VP   V8P    YP      YP   YD Y88888P    YP         YP     `Y88P'     `Y88P'  `Y88P'  VP   V8P    YP    Y888888P VP   V8P ~Y8888P' Y88888P");

}

class SpaceShip
{
private:
int x; // x coordonate
int y; // y coordonate
int hpset=3; // vieti initiale
int hp=hpset;// hp actual
int energyset=5; // energie initiala
int energy=energyset;// energie actuala
bool imDead; // este nava moarta?
public:
int X()  { return x; }
int Y()  { return y; }
int HP() { return hp; }

  bool isDead()
 {
   DrawSpaceShipInfo(); // Desenarea informatiilor despre nava
   return imDead;
 }

   SpaceShip(int _x, int _y)
  {
    x = _x;
    y = _y;
    hp;
    energy;
    imDead = false; // Default nava este in viata
  }


  void DrawSpaceShipInfo()
 { // Afiseaza Hp-ul si energia
   gotoxy(5, 1); printf("          ");
   for(int i = 0; i < hp; i++)
  {
    gotoxy(5 + i, 1); printf("%c", 3);
  }

 gotoxy(23, 1); printf("          ");

   for(int i = 0; i <energy; i++)
  {
   gotoxy(23 + i, 1); printf("%c", 222);
  }


 }

   void Draw()
 {// Aceasta este nava noastra spatiala
    gotoxy(x,y);          printf(".");
    gotoxy(x-1,y+1);     printf(".'.");
    gotoxy(x-1,y+2);     printf("|o|");
   gotoxy(x-2,y+3);     printf(".'o'.");
   gotoxy(x-2,y+4);     printf("|.-.|");
   gotoxy(x-2,y+5);     printf("'   '");

 }

  void Erase()
 { // Stergerea caracterelor reziduale ale navei din terminal

   gotoxy(x,y);          printf("   ");
   gotoxy(x-1,y+1);     printf("     ");
   gotoxy(x-1,y+2);     printf("     ");
   gotoxy(x-2,y+3);    printf("       ");
   gotoxy(x-2,y+4);    printf("       ");
   if(x-4>4){
   gotoxy(x-4,y+5);    printf("          ");}
    else
  gotoxy(x-2,y+5);    printf("        ");
 }

  void Damage()
 {// Declansat de asteroizi care au lovit nava
    energy--;
   if(energy == 0)
  {
   Explosion();
  }
   else
  {
    Erase(); // Iti arata vizual ca nava a fost lovita

     gotoxy(x,y);         printf("*");
    gotoxy(x-1,y+1);     printf("***");
    gotoxy(x-1,y+2);     printf("***");
   gotoxy(x-2,y+3);      printf("***");
   gotoxy(x-2,y+4);     printf("*****");
   gotoxy(x-2,y+5);     printf("*****");

   Sleep(100);
  }
}

 void Explosion()
{ // Cand pierzi o viata
 hp--;
 Erase();
     gotoxy(x,y);        printf("*");
    gotoxy(x-1,y+1);     printf("|");
    gotoxy(x-1,y+2);     printf("|");
   gotoxy(x-2,y+3);      printf("/ %c",92);
   gotoxy(x-2,y+4);     printf("/ o %c",92);
   gotoxy(x-2,y+5);     printf("\o*o/",92);

 Sleep(100);

 Erase();

     gotoxy(x,y);         printf("*");
    gotoxy(x,y+1);        printf("*");
    gotoxy(x-1,y+2);     printf("***");
   gotoxy(x-2,y+3);     printf("* * *");
   if(x-3>3&&x<105){
   gotoxy(x-3,y+4);    printf("* * * *");
   Sleep(50);
    gotoxy(x-3,y+4); printf("          ");}
   if(x-4>4&&x<105){
   gotoxy(x-4,y+5);   printf("*   *   *");
   Sleep(50);
   gotoxy(x-4,y+5); printf("             ");
   }

 Sleep(100);

 Erase();

     gotoxy(x,y);         printf("*");
    gotoxy(x-1,y+1);     printf("***");
    gotoxy(x-1,y+2);     printf("***");
   gotoxy(x-2,y+3);      printf("***");
   gotoxy(x-2,y+4);     printf("*****");
   gotoxy(x-2,y+5);     printf("*****");

 Sleep(100);

   if(hp > 0)
  { // Daca mai ai cel putin o viata
    energy = energyset;
  }
     else
   { // Daca nu mai ai nicio viata
      imDead = true;
      DrawSpaceShipInfo();
   }
 }

   void Move()
  { // Funcita principala a navei spatiale
      if(kbhit())
     { // Daca muti nava spatiala
       Erase();
       char key = getch(); // Ce ai scris?
         switch(key)
       { // Verifică dacă nava spațială nu va părăsi limitele jocului

       case LEFT:  if(x > 4)      x -= 2; break;
       case RIGHT: if(x + 6 <104) x += 2; break;
       case UP:    if(y > 5)      y -= 2; break;
       case DOWN:  if(y + 4< 26) y += 2 ; break;
       }
     }
   Draw(); // Nava spațială este desenată indiferent dacă ați mutat-o ​​sau nu, dacă ați făcut-o, va apărea în noua sa poziție.
  }
   };
class Asteroid
{
private:
int x;
int y;
public:
int X()  { return x; }
int Y()  { return y; }

 Asteroid(int _x, int _y)
 {
 x = _x;
 y = _y;
 }
    void Draw()
  {
    gotoxy(x,y); printf("*");
  }
    void Collision(SpaceShip &ss) // Asteroidul loveste nava spatiala
   {
      if(((x >= ss.X()-2) && (x <= ss.X() +2)) && ((y >= ss.Y()) && (y <= ss.Y() + 5)))
     {
       ss.Damage(); // Asteroidul distruge nava
       gotoxy(x,y); printf(" "); // Si asteroidul este "distrus"
       x = rand()%105 + 3; // Asteroidul se teleporteaza in varful terminalului
       y = 4;
     }
       else
      {
        gotoxy(x,y); printf(" ");
        y++;
          if(y > 26)
         { // Daca ajunge la fundul terminalului
           x = rand()%105 + 3; // La fel se teleporteaza in varful terminalului
           y = 4;
         }
    Draw();
      }
    }
};
class Bullet
{
private:
int x;
int y;
public:
int X()  { return x; }
int Y()  { return y; }

  Bullet(int _x, int _y)
 {
   x = _x;
   y = _y;
 }

  bool isOut()
 {
    if(y <= 3)
   { // Daca proiectilul ajunge in varful terminalului
    gotoxy(x,y); printf(" "); // Dispare
    return true;
   }
     else
    {
      return false;
    }
 }

   void Move()
  {
    gotoxy(x,y); printf(" ");
    y--;
    gotoxy(x,y);      printf("^"); // Forma proiectilului
  }
};
int iniammo=7;
int ammo=iniammo;
int countdown=0;
bool AMMO()
{
    // Informatii despre munitie
  if(ammo>0)
  {
      gotoxy(39+ammo-1,1); printf(" ");
      ammo--;
      return true;
  }
  else
  {
      gotoxy(39,1); printf("RELOADING:");

      for(int k=1;k<=countdown;k++)
        if(k%2==0){
         gotoxy(49+k,1); printf("0");}
         else{
         gotoxy(49+k,1); printf("o");}

      if(countdown<4)
      {
        return false;
      }
        else
        {
         countdown=0;
         ammo=iniammo;
         gotoxy(39,1); printf("                     ");
         for(int k=0;k<iniammo;k++){
         gotoxy(39+k,1); printf("%c",222);}
         return false;
        }

  }
}

int main()
{
HideCursor();
/*
system("color 370");
return 0;
*/
WelcomeMessage();
getch();
DrawGameLimits();
//system("MODE CON COLS=120 LINES=40");
list<Bullet*> Bullets; // Vom folosi o listă dinamică pentru gloanțele din joc
list<Bullet*>::iterator bullet; // Și un iterator pentru listă

list<Asteroid*> Asteroids; // Același lucru este valabil și pentru asteroizi
list<Asteroid*>::iterator asteroid;

  for(int i = 0; i < 14; i++) // Alegeți cât de mulți asteroizi doriți
 { //Acestea sunt plasate aleatoriu pe hartă, dar nu prea jos
   Asteroids.push_back(new Asteroid(rand()%105 + 1, rand()%4 + 3));
 }

 SpaceShip ss = SpaceShip(40,20); // Aici începe aventura noastră

 int score =0; // Scorul :3

  while(!ss.isDead() && score !=100) // Dacă mori sau atingi 100 de puncte, jocul se termină
 {
   if(kbhit())
  {
    char key = getch();
    if(key == ' ')
   { // Dacă apăsați bara de spațiu, adăugați un glonț în lista de glonțe
    if(AMMO())
    {
       Bullets.push_back(new Bullet(ss.X(), ss.Y()-1));
    }
    else
        countdown++;

   }
  }

   for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)
  { // Pentru fiecare glonț care se află în spațiu
    (*bullet)->Move();
     if((*bullet)->isOut())
    { // Dacă glonțul a ajuns la sfârșitul hărții
      delete(*bullet); // Este sters
      bullet = Bullets.erase(bullet);
    }
  }

   for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
  { // Fiecare asteroid verifică dacă nava spațială împarte coordonatele sale: 3
    (*asteroid)->Collision(ss);
  }

   for(asteroid = Asteroids.begin(); asteroid != Asteroids.end(); asteroid++)
  {
    for(bullet = Bullets.begin(); bullet != Bullets.end(); bullet++)
     { // asteroid-bullet collision

       int astX = (*asteroid)->X(); //Coordonatele asteroidului
       int astY = (*asteroid)->Y();
       int bulX = (*bullet)->X(); // Coordonatele proiectilului
       int bulY = (*bullet)->Y();

        if((astX == bulX) && ((astY == bulY) || (astY + 1 == bulY)))
          { //Șansele sunt ca în axa Y să nu atingă niciodată aceeași valoare, acest caz trebuie luat în considerare
            gotoxy(bulX,bulY); printf(" "); // Face glonțul invizibil
            gotoxy(astX,astY); printf("X"); Sleep(30); gotoxy(astX,astY); printf(" ");
            delete(*bullet); // Ștergi glonțul

            bullet = Bullets.erase(bullet);

            delete(*asteroid);// Si asteroidul

            asteroid = Asteroids.erase(asteroid);
            Asteroids.push_back(new Asteroid(rand()%105 + 1, rand()%4 + 3)); // pentru a nu reduce numărul de asteroizi, adaug câte unul de fiecare dată când unul este distrus
            score += 10; // And you get 10 points for a job well done :3
          }
      }
    }
  ss.Move();
  gotoxy(66,1); printf("%d", score);
  Sleep(30); // Acest lucru este esențial, altfel jocul nu ar putea fi jucat
}
  if(!ss.isDead())
 { // Daca ai pierdut
   GameOverVictoryMessage();
 }
   else
  { // Daca ai castigat
   GameOverDefeatMessage();
  }
 Sleep(5000);
 if(ss.isDead())
 {
 system("MODE CON COLS=170 LINES=30");
 SpecialMessage(); // Surprise
 Sleep(5000);
 }
 system("MODE CON COLS=250 LINES=30");
 EndGame();
 Sleep(5000);

 return 0;
}


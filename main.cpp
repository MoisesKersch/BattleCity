#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <mingw.thread.h>


using namespace std;
void ShowConsoleCursor(bool showFlag);
void gotoxy (int x, int y);
void displayUp(int x, int y);
void displayDown(int x, int y);
void displayRight(int x, int y);
void displayLeft(int x, int y);
void gotoxyBullet(int x, int y);
void bullet(int x, int y);
void play();
void clearBox();

int main()
{   ShowConsoleCursor(false);
    //displayRight(5,5);
    play();
}

void play()
{
    int x = 10;
    int y = 10;

    int input;

    displayRight(10, 10);


    bool enter = true;

    while (input = getch())
    {

        if (x >= 2 && input == 97 and enter)
        {
            displayLeft(x, y);
            x--;
        }

        else if (input == 100 and enter)
        {
            displayRight(x, y);
            x++;
        }

        else if (y >= 3 and input == 119 and enter)
        {
            displayUp(x, y);
            y--;
        }

        else if (input == 115 and enter)
        {
            displayDown(x, y);
            y++;
        }
        else
        {
            if (input == 97)
            {
                displayLeft(x, y);
            }

            if (input == 100)
            {
                displayRight(x, y);
            }

            if (input == 119)
            {
                displayUp(x, y);
            }

            if (input == 115)
            {
                displayDown(x, y);
            }
        }
        if (input == 32)
        {
            thread t2(bullet,x+4,y+1);
            t2.detach();
        }
    }
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),COORD {x-1,y-1});
}

void displayUp(int x, int y)
{
	gotoxy(x,y);
	cout << " " << "X" << " ";
	gotoxy(x,y+1);
	cout << "X" << " " << "X";
	gotoxy(x,y+2);
	cout << "X" << " " << "X";

	gotoxy(x-1,y+1);
    cout << " ";

    gotoxy(--x,y+3);
    cout << " " << " " << " " << " " << " ";


    gotoxy(x,y);
    cout << " ";

    gotoxy(x,y+1);
    cout << " ";

    gotoxy(x,y+2);
    cout << " ";

    gotoxy(x+4,y);
    cout << " ";

    gotoxy(x+4,y+1);
    cout << " ";

    gotoxy(x+4,y+2);
    cout << " ";


}

void displayDown(int x, int y)
{
    gotoxy(x-2,y-1);
    cout << " " << " " << " " << " " << " ";

    gotoxy(x-1,y);
    cout << " ";

    gotoxy(x-1,y+2);
    cout << " ";

    gotoxy(x,y);
    cout << "X" << " " << "X";

    gotoxy(x,y+1);
	cout << "X" << " " << "X";

	gotoxy(x-1,y+1);
    cout << " ";

	gotoxy(x,y+2);
	cout << " " << "X" << " ";
}

void displayLeft(int x, int y)
{

    gotoxy(x-2,y-1);
    cout << " " << " " << " " << " " << " ";

    gotoxy(x-2,y+3);
    cout << " " << " " << " " << " " << " ";

    gotoxy(x-2,y);
    cout << " ";

    gotoxy(x-2,y+1);
    cout << " ";

    gotoxy(x-2,y+2);
    cout << " ";

    gotoxy(x-1,y);
	cout << " " << "X" << "X";
	gotoxy(x+2,y);
	cout << " ";

	gotoxy(x-1,y+1);
	cout << "X" << " " << " ";
    gotoxy(x+2,y+1);
	cout << " ";

	gotoxy(x-1,y+2);
	cout << " " << "X" << "X";
	gotoxy(x+2,y+2);
	cout << " ";
}

void displayRight(int x, int y)
{
    gotoxy(x-1,y-1);
    cout << " " << " " << " " << " " << " ";

    gotoxy(x-1,y+3);
    cout << " " << " " << " " << " " << " ";

    gotoxy(x,y);
	cout << "X" << "X" << " ";
    gotoxy(x-1,y);
    cout << " ";

    gotoxy(x,y+1);
	cout << " " << " " << "X";
    gotoxy(x-1,y+1);
    cout << " ";
	gotoxy(x,y+2);
	cout << "X" << "X" << " ";
	gotoxy(x-1,y+2);
    cout << " ";
}

void bullet(int x, int y)
{
     int b = 0;
     int xtempt, ytempt;
     xtempt =  x;
     ytempt = y;

     while (b < 26)
     {
         //displayRight(xtempt, ytempt);
         gotoxyBullet(x, y);
         x++;
         if (b == 25)
         {
             cout << " ";
         }
         else
         cout << "0";
         gotoxyBullet(x-2, y);
         cout << " ";
         b++;
         Sleep(15);
     }

}

void gotoxyBullet(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x-1,y-1
    });
}
void clearBox()
{
    HANDLE hOut;
    COORD Position;
    DWORD Written;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    Position.X = 0;
    Position.Y = 10;
    FillConsoleOutputCharacter(hOut,' ', 1000000, Position, &Written);

    SetConsoleCursorPosition(hOut, Position);
}
void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

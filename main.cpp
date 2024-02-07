#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "McMapua.h"

using namespace std;


int main()
{
    McMapuaSystem menu;
    string startString = "";
    cout << "===== Welcome to McMapua! =====\nPress Any key to Start...";
    do
    {
        if (kbhit())
        {
            system("cls");
            cout << "===== Welcome to McMapua! =====\n";
            char c = getch();
            switch (c)
            {
                case 't':
                case 'e':
                case 's':
                    startString += c;
                    cout << "Password: " << startString;
                    break;
                default:
                    startString = "#";
                    break;
            }
        }

    } while (startString != "#" && startString.length() < 4);

    if (startString == "test")
    {
        menu.TestMode();
    }
    else
    {
        menu.MainMenu();
    }    

    return 0;
}
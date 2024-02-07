#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "McMapua.h"

using namespace std;


int main()
{
    McMapuaSystem menu;
    cout << "===== Welcome to McMapua! =====\nPress Any key to Start...";
    while(true)
    {
        if (kbhit())
        {
            switch (getch())
            {
                case 't':
                    menu.TestMode();
                    break;
                default:
                    menu.MainMenu();
                    break;
            }
        }
    }

    return 0;
}

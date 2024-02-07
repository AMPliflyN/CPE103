#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "McMapua.h"

using namespace std;

void McMapuaSystem::TestMode()
{   
    system("cls");
    cout << "===== Welcome to TestMode! =====\n"
    << "1. MainMenu\n"
    << "2. FoodMenu\n"
    << "Any other Key (Exit)\n"
    << "===============================" << endl;

    do
    {
        if (kbhit())
        switch (getch())
        {
            case '1':
                MainMenu();
                cout << "\n===== TestMode! =====\n"
                    << "1. MainMenu\n"
                    << "2. FoodMenu\n"
                    << "Any other Key (Exit)\n"
                    << "===============================" << endl;
                break;
            case '2':
                cout << "===== Welcome to McMapua! =====\n";
                FoodMenu();
                cout << "\n===== TestMode! =====\n"
                    << "1. MainMenu\n"
                    << "2. FoodMenu\n"
                    << "Any other Key (Exit)\n"
                    << "===============================" << endl;
                break;
            case '3':
                OrderNew();
            default:
                return;
        }

    } while (true);
}

void McMapuaSystem::MainMenu()
{
    system("cls");
    cout << "===== Welcome to McMapua! =====\n"
    << "1. OrderNew\n"
    << "2. Calculate Order\n"
    << "3. Import Previous Order\n"
    << "4. Exit\n"
    << "===============================" << endl;

    do
    {
        if (kbhit())
        {
            switch (getch())
            {
                case '1':
                    OrderNew();
                    break;
                case '2':
                    cout << "Calculate Order\n";
                    break;
                case '3':
                    cout << "Import Previous Order\n";
                    break;
                case '4':
                    return;
            }
        }

    } while (true);
}

void McMapuaSystem::FoodMenu() 
{
    cout << "#\tItem\tPrice\tQty\n"
    << "1.\tBurger\t$5.99\t" << order[0] << '\n'
    << "2.\tPizza\t$8.99\t" << order[1] << '\n'
    << "3.\tPasta\t$7.49\t" << order[2] << '\n'
    << "4.\tSalad\t$4.99\t" << order[3] << '\n'
    << "5.\tFries\t$2.99\t" << order[4] << '\n'
    << "6.\tDrink\t$1.99\t" << order[5] << '\n'
    << "===============================" << endl;
}

void McMapuaSystem::OrderNew()
{
    bool loop =  true;
    for (int i = 0; i < 6; i++)
    {
        order[i] = 0;
    }
    system("cls");
    cout << "===== Press a number to add order! =====" << endl;
    FoodMenu();
    do
    {
        if (kbhit())
        {
            char c = getch();
            if (int(c) > 0 && int(c) <= 6)
            {
                order[c] == addOrder();
            }
            else if (c == '\n')
            {
                cout << "Preseed Enter\n";
                loop = false;
            }
        }

    } while (loop);
}

int McMapuaSystem::addOrder()
{
    cout << "Enter Quantity: ";
    while (true)
    {
        if (kbhit())
        {
            string s = "";
            char c = getch();
            cout << "Enter Quantity: " << s;
            if (c == '\n')
            {
                return stoi(s);
            }
            else if (c == '\b')
            {
                s.pop_back();
            }
            else
            {
                s += c;
            }

        }
    }
}

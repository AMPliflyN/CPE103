#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "McMapua.h"

using namespace std;

//Start Menu 

//Test Mode for Developer

void McMapuaSystem::TestMode()
{   
    system("cls");
    cout << "===== Welcome to TestMode! =====\n"
    << "1. MainMenu\n"
    << "2. FoodMenu\n"
    << "3. OrderNew\n"
    << "4. addOrder\n"
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
                break;
            case '4':
                cout << "addOrder Returned: " << addOrder('E') << endl;
                return;
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
                    Receipt();
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


/*Function for Order inputs
Prints out menu list*/
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


//Gets the numerical value and collects them as the number of orders per meal
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
            if (int(c) >= 49 && int(c) <= 54)
            {
                order[c - 49] += addOrder(c);
                system("cls");
                cout << "===== Press a number to add order! =====" << endl;
                FoodMenu();
            }
            else if (c == '0')
            {
                cout << "Pressed 0\n";
                loop = false;
            }
            else 
            {
                system("cls");
                cout << "===== Press a number to add order! =====" << endl;
                FoodMenu();
                cout << "Invalid Input\n";
            }
        }

    } while (loop);
}

int McMapuaSystem::addOrder(char selected)
{
    int qty;
    cout << "You've selected: item #" << selected << "\n";
    cout << "Enter Quantity: ";
    cin >> qty;
    return qty;
}

void McMapuaSystem::Receipt()
{
    system("cls");
    cout << "===== Receipt =====\n";

    ofstream outFile("Receipt.txt");  // Open a text file for writing

    if (!outFile.is_open())
    {
        cout << "Error: Unable to create the receipt file.\n";
        return;
    }

    // Write the receipt content to the file
    outFile << "McMapua Receipt\n\n";
    outFile << "#\tItem\t\tPrice\t\tQty\n";

    const string items[] = {"Burger", "Pizza", "Pasta", "Salad", "Fries", "Drink"};

    double prices[] = {5.99, 8.99, 7.49, 4.99, 2.99, 1.99};

    double total = 0.0;

    for (int i = 0; i < 6; ++i)
    {
        if (order[i] > 0)
        {
            double subtotal = prices[i] * order[i];
            outFile << i + 1 << "\t" << items[i] << "\t$" << prices[i] << "\t\t" << order[i] << "\n";
            total += subtotal;
        }
    }

    outFile << "\nTotal: $" << fixed << setprecision(2) << total;

    cout << "Receipt saved to Receipt.txt\n";

    outFile.close();  // Close the file
}
  

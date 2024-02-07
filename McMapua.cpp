#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "McMapua.h"

using namespace std;

//Start Menu 

void McMapuaSystem::MainMenu(bool isNewOrder)
{
    system("cls");
    cout << "===== Welcome to McMapua! =====\n"
    << "1. Make a new order\n"
    << "2. Edit current order\n"
    << "3. Print Receipt\n"
    << (isNewOrder ? "4. Exit\n" : "4. Exit (Press twice)\n")
    << "===============================" << endl;

    while(true)
    {
        if (kbhit())
        {
            switch (getch())
            {
                case '1':
                    OrderMenu(true);
                    break;
                case '2':
                    OrderMenu(isNewOrder);
                    break;
                case '3':
                    cout << "Print Receipt\n";
                    Receipt(isNewOrder);
                    break;
                case '4':
                    return; // Use return statement to exit the function
                default:
                    system("cls");
                    cout << "===== Welcome to McMapua! =====\n"
                        << "1. Make a new order\n"
                        << "2. Edit current order\n"
                        << "3. Print Receipt\n"
                        << "4. Exit\n"
                        << "===============================" << endl;
                        cout << "Invalid Input\n";
                    break;
            }
        }
    }
    return;
}



/*Function for Order inputs
Prints out menu list*/
void McMapuaSystem::FoodMenu() 
{
    for (int i = 0; i < 6; i++)
    {
        order[i] = (order[i] < 0 ? 0 : order[i]);
    }
    cout << "#\tItem\tPrice\tQty\n"
    << "1.\tBurger\t$5.99\t" << order[0] << '\n'
    << "2.\tPizza\t$8.99\t" << order[1] << '\n'
    << "3.\tPasta\t$7.49\t" << order[2] << '\n'
    << "4.\tSalad\t$4.99\t" << order[3] << '\n'
    << "5.\tFries\t$2.99\t" << order[4] << '\n'
    << "6.\tDrink\t$1.99\t" << order[5] << '\n'
    << "====================================================\n"
    << "You've selected: item #";

}


//Gets the numerical value and collects them as the number of orders per meal
void McMapuaSystem::OrderMenu(bool isNewOrder)
{
    bool loop =  true;
    if (isNewOrder)
    {
        for (int i = 0; i < 6; i++)
        {
            order[i] = 0; 
        }
    }
    system("cls");
    cout << "===== Press a number to add order! (0 to exit) =====" << endl;
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
                cout << "===== Press a number to add order! (0 to exit) =====" << endl;
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
                cout << "===== Press a number to add order! (0 to exit) =====" << endl;
                FoodMenu();
            }
        }
    } while (loop);
    MainMenu(false);
}

int McMapuaSystem::addOrder(char selected)
{
    int qty;
    cout << selected << "\n";
    cout << "Enter Quantity: ";
    cin >> qty;
    return qty;
}

void McMapuaSystem::Receipt(bool isNewOrder)
{
    system("cls");
    cout << "===== Receipt =====\n";

    ofstream outFile("Receipt.txt");  // Open a text file for writing

    if (!outFile.is_open() || isNewOrder)
    {
        cout << "Error: Unable to create the receipt file.\n";
        system("pause");
        MainMenu(false);
    }

    // Write the receipt content to the file
    outFile << "McMapua Receipt\n\n";
    outFile << "#\tItem\tPrice\t\tQty\t\tPerItemCost\n";
    const string items[] = {"Burger", "Pizza", "Pasta", "Salad", "Fries", "Drink"};
    double prices[] = {5.99, 8.99, 7.49, 4.99, 2.99, 1.99};
    double total = 0.0;
    for (int i = 0; i < 6; ++i)
    {
        if (order[i] > 0)
        {
            double subtotal = prices[i] * order[i];
            outFile << i + 1 << "\t" << items[i] << "\t$" << prices[i] << "\t\t" << order[i]<< "\t\t$" << subtotal << "\n";
            total += subtotal;
        }
    }

    outFile << "\nTotal: $" << fixed << setprecision(2) << total;

    cout << "Receipt saved to Receipt.txt\n";
    outFile.close();  // Close the file
    cout << "===== Welcome to McMapua! =====\n"
    << "1. Make a new order\n"
    << "2. Edit current order\n"
    << "3. Print Receipt\n"
    << "4. Exit (Press twice)\n"
    << "===============================" << endl;
    return;
}

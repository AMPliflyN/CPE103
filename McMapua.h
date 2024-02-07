#include <iostream>
#include <fstream>
#include <iomanip>

class McMapuaSystem
{
public:
    void MainMenu(bool);
    void FoodMenu();
    void OrderMenu(bool);
    void Receipt(bool);
    int addOrder(char);
    
private:
    int order[6];
};

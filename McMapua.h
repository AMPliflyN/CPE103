#include <iostream>
#include <fstream>
#include <iomanip>

class McMapuaSystem
{
public:
    void TestMode();
    void MainMenu();
    void FoodMenu();
    void OrderNew();
    int addOrder(char);
    
private:
    int order[6];
};

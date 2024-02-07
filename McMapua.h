#ifndef MCMAPUA_H
#define MCMAPUA_H

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
    int addOrder();
    
private:
    int order[6];
};

#endif

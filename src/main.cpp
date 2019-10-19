#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <locale>        
#include "Map.h"
#include "GridHelper.h"

using namespace std;

int main() {
        std::cout << "##################################################################################"<< endl;
        std::cout << "#                                     |__)                                       #" << endl;
        std::cout << "#                                     |\/)                                        #" << endl;
        std::cout << "#                                     ---)                                       #" << endl;
        std::cout << "#                                     / | [)                                     #" << endl;
        std::cout << "#                              !      | |||)                                     #" << endl;
        std::cout << "#                            _/|     _/|-++')                                    #" << endl;
        std::cout << "#                        +  +--|    |--|--|_ |-)                                 #" << endl;
        std::cout << "#                     { /|__|  |/\__|  |--- |||__/)                               #" << endl;
        std::cout << "#                    +---------------___[}-_===_.'____                 /\         #" << endl;
        std::cout << "#                ____`-' ||___-{]_| _[}-  |     |_[___\==--            \/   _      #" << endl;
        std::cout << "# __..._____--==/___]_|__|_____________________________[___\==--____,------' .7   #" << endl;
        std::cout << "#|                        Welcome to Battleship                         BB-61/   #" << endl;
        std::cout << "# \_________________________________________________________________________|     #" << endl;
        std::cout << "##################################################################################"<< endl;

    srand(time(0));//seed random

    string input;
    bool turn = true;

    //create class instance
    Map map;
    GridHelper grid;

    //reset and randomize;
    map.resetGrid();
    map.startGame();
    map.printGrid();

    do{
        if(turn)//Human Player
        {
            do{
                cout << "Enter a position";
                cin >> input;
                input = grid.processGridInput(input);
                if(!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid)){
                    cout << "Invalid Position" << endl;
                }
            }while (!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid));
            map.hitShip(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid,map.cpuGrid);
            system("clear");
            cout << "Human Player Grid" << endl;
            map.printGrid();
            if(!map.checkWin(map.playerGrid))
                turn = !turn;
        }
        else//CPU
        {
            do {
                input = grid.CPUDecision();
            }while (!map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid) && !map.isBlockCleared(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.playerGrid));
            map.hitShip(grid.asciiToNum(input[0]),grid.asciiToNum(input[1]),map.cpuGrid,map.playerGrid);
            system("clear");
            cout << "CPU Player Grid" << endl;
            //map.printCPUGrid(); __DEBUG__
            if(!map.checkWin(map.cpuGrid))
                turn = !turn;
        }
    }while(true);
}
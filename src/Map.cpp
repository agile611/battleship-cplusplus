#include "Map.h"
#include <iostream>

/**
 * Reset Map Grid
 */
void Map::resetGrid() {
    for(int x =0; x < 8; x++){
        for(int y=0; y < 8; y++){
            Map::cpuGrid[x][y] = '_';
            Map::playerGrid[x][y] = '_';
        }
    }
}

/**
 * Print out Player grid
 */
void Map::printGrid() {
    std::cout << "  ";
    for(int a = 65; a <= 72; a++){
        std::cout << char(a) << "|";
    }
    std::cout << std::endl;
    for(int x =0; x < 8; x++){
        std::cout << x << "|";
        for(int y=0; y < 8; y++){
            std::cout << Map::playerGrid[x][y] << "|";
        }
        std::cout << std::endl;
    }
}

/**
 * Print out CPU grid
 * @debug
 */
void Map::printCPUGrid() {
    std::cout << "  ";
    for(int a = 65; a <= 74; a++){
        std::cout << char(a) << "|";
    }
    std::cout << std::endl;
    for(int x =0; x < 8; x++){
        std::cout << x << "|";
        for(int y=0; y < 8; y++){
            std::cout << Map::cpuGrid[x][y] << "|";
        }
        std::cout << std::endl;
    }
}

/**
 * One method randomazation of the grid
 */
void Map::randomize() {
    placeShip('A',5,Map::playerGrid);
    placeShip('B',4,Map::playerGrid);
    placeShip('C',3,Map::playerGrid);
    placeShip('S',3,Map::playerGrid);
    placeShip('D',2,Map::playerGrid);

    placeShip('A',5,Map::cpuGrid);
    placeShip('B',4,Map::cpuGrid);
    placeShip('C',3,Map::cpuGrid);
    placeShip('S',3,Map::cpuGrid);
    placeShip('D',2,Map::cpuGrid);
}

void Map::startGame() {

    std::cout<<"Please position your fleet (Game board size is from 1 to 8 in columns and 1 to 8 in rows)"<<std::endl;
    //Carrier 5
    std::cout<<"Enter position for a Carrier (5 holes)"<<std::endl;
    placeShip('A',5,Map::playerGrid);
    //Battleship 4
    std::cout<<"Enter position for a Battleship (4 holes)"<<std::endl;
    placeShip('B',4,Map::playerGrid);
    //Cruiser 3
    std::cout<<"Enter position for a Cruiser (3 holes)"<<std::endl;
    placeShip('C',3,Map::playerGrid);
    //Submarine 3
    std::cout<<"Enter position for a Submarine (3 holes)"<<std::endl;
    placeShip('S',3,Map::playerGrid);
    //Destroyer 2
    std::cout<<"Enter position for a Destroyer (2 holes)"<<std::endl;
    placeShip('D',2,Map::playerGrid);

    //CPU Place the ships
    std::cout<<"CPU is placing the ships ...."<<std::endl;
    placeShip('A',5,Map::cpuGrid);
    placeShip('B',4,Map::cpuGrid);
    placeShip('C',3,Map::cpuGrid);
    placeShip('S',3,Map::cpuGrid);
    placeShip('D',2,Map::cpuGrid);
}

/**
 * Place Ship randomly on the grid
 * @param ships Ship character
 * @param size Ship size
 * @param grid Grid Array
 */
void Map::placeShip(char ships, int size,char (&grid)[8][8]) {
    bool isVertical ;
    isVertical= bool(rand() % 2);
    int x,y;
    x = rand() % 8, y = rand() % 8;

    //Make sure is in boundary
    if(x+size > 8)
        x -= size;
    if(y+size > 8)
        y -= size;

    if(isVertical) {
        if (checkVerticalClearence(x, y, size)) {
            for (int tempy = y; tempy < (y + size); tempy++) {
                grid[x][tempy] = ships;
            }
        } else {
            placeShip(ships, size, grid);
        }
    }else{
        if(checkHoriClearence(x,y,size)){
            for(int tempx = x; tempx < x+size; tempx++){
                grid[tempx][y] = ships;
            }
        }else{
            placeShip(ships,size,grid);
        }
    }
}

/**
 * Hit Ship on the grid
 * @param x X-axis
 * @param y Y-axis
 * @param myGrid My Grid use to display hit status
 * @param oppoGrid Target Grid
 * @return hited or missed/invaild move
 */
bool Map::hitShip(int x, int y, char (&myGrid)[8][8], char (&oppoGrid)[8][8]) {
    if(isShipHit(x,y,oppoGrid))
        return false;
    else{
        if(isBlockCleared(x,y,oppoGrid) && isBlockCleared(x,y,myGrid)) {
            oppoGrid[x][y] = 'O';
            myGrid[x][y] = 'O';
            return false;
        }else if(isBlockCleared(x,y,myGrid)){
            myGrid[x][y] = '/';
            oppoGrid[x][y] = 'X';
            return true;
        }
    }
}

/**
 * Check if ship was hitted with 'X' or 'O'
 * @param x X-axis
 * @param y Y-axis
 * @param grid target grid
 * @return Hitted?
 */
bool Map::isShipHit(int x, int y, char (&grid)[8][8]) {
    return grid[x][y] == 'X' || grid[x][y] == 'O';
}

/**
 * Check if one of the block speific is blank
 * @param x X-axis
 * @param y Y-axis
 * @param grid target grid
 * @return Blank?
 */
bool Map::isBlockBlank(int x, int y, char (&grid)[8][8]) {
    return grid[x][y] == '_';
}

bool Map::isBlockCleared(int x, int y, char (&grid)[8][8]) {
    return isBlockBlank(x,y,grid) && !isShipHit(x,y,grid);
}

/**
 * Make sure Horiztal. have room for a ship
 * Use linear search method, from top to bottom
 * @param x ship start x
 * @param y ship start y
 * @param size ship size
 * @return Cleared or not
 */
bool Map::checkHoriClearence(int x, int y, int size) {
    for(int tempx = x; tempx < x+size; tempx++){
        if(Map::playerGrid[tempx][y] != '_' || Map::cpuGrid[tempx][y] != '_'){
            return false;
        }
    }
    return true;
}

/**
 * Make sure vertical have room for a ship
 * Use linear search method, from right to left
 * @param x ship start x
 * @param y ship start y
 * @param size ship size
 * @return Cleared or not
 */
bool Map::checkVerticalClearence(int x, int y, int size) {
    for(int tempy = y; tempy < (y+size); tempy++){
        if(Map::playerGrid[x][tempy] != '_' || Map::cpuGrid[x][tempy] != '_'){
            return false;
        }
    }
    return true;
}

bool Map::checkWin(char (&grid)[8][8]) {
    int shipCounter = 0;
    for (auto &x : grid) {
        for (char y : x) {
            if(y == '/')
                shipCounter++;
        }
    }
    return shipCounter == 17;
}
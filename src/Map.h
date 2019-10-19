//
// Created by apple on 2019-02-23.
//

#ifndef BATTLESHIP_MAP_H
#define BATTLESHIP_MAP_H

class Map {
public:
    char playerGrid[8][8] = {};//Grid Map
    char cpuGrid[8][8] = {};

    void resetGrid();
    void printGrid();
    void printCPUGrid();

    void randomize();
    void startGame();

    void placeShip(char ships, int size, char (&grid)[8][8]);

    bool hitShip(int x, int y,char (&myGrid)[8][8], char (&oppoGrid)[8][8]);
    bool checkWin(char (&grid)[8][8]);
    bool isBlockCleared(int x, int y, char (&grid)[8][8]);

private:
    bool checkVerticalClearence(int x, int y, int size);
    bool checkHoriClearence(int x, int y, int size);
    bool isShipHit(int x, int y, char(&grid)[8][8]);
    bool isBlockBlank(int x, int y, char(&grid)[8][8]);

};

#endif //BATTLESHIP_MAP_H
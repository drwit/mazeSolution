#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Maze.h"
#include "Tracker.h"
#include "consoleOperation.h"

using namespace std;



int main()
{
    char testMap[8][8] = {
    {WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL},
    {WALL,ROAD,ROAD,ROAD,WALL,WALL,ROAD,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,ROAD,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,ROAD,WALL},
    {WALL,ROAD,ROAD,ROAD,ROAD,ROAD,ROAD,WALL},
    {WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL},
};

    Maze maze1(testMap);
    Tracker p1('X',7,1);
    p1.startTracking(maze1);

    cout << "Good Job!" << endl;
    return 0;
}

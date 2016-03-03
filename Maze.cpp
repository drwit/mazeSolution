#include <iostream>
#include "Maze.h"

char defaultMap[8][8] = {
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
    {WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL},
};

Maze::Maze()
{
    setWallChar('*');
    setRoadChar(' ');
    setMazeMap(defaultMap);
}

Maze::Maze(char (*_map)[8])
{
    setWallChar('*');
    setRoadChar(' ');
    setMazeMap(_map);
}

void Maze::setWallChar(char wc)
{
    wallChar = wc;
}

void Maze::setRoadChar(char rc)
{
    roadChar = rc;
}

void Maze::setMazeMap(char _map[][8])
{
    int i, j;
    for(i = 0; i < 8; i++)
        for(j = 0; j < 8; j++)
            mazeMap[i][j] = _map[i][j];
}

char Maze::getWallChar()
{
    return wallChar;
}

char Maze::getRoadChar()
{
    return roadChar;
}

char (*Maze::getMazeMap())[8]
{
    return mazeMap;
}

bool Maze::mazeCheck(int x, int y)
{
    if(x < 0 || y < 0)
        return false;
    if(getMazeMap()[x][y] == WALL)
        return false;
    else
        return true;
}

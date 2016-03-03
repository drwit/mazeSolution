#include <iostream>
#include <windows.h>
#include "Tracker.h"
#include "consoleOperation.h"
//暂时不考虑根据迷宫可用坐标初始化人的坐标
Tracker::Tracker()
{
    setTrackerChar('P');
    setTrackerDirection(RIGHT);
    setRecentCordinate(0,0);
}

Tracker::Tracker(char tc, int x, int y)
{
    setTrackerChar(tc);
    setTrackerDirection(RIGHT);
    setRecentCordinate(x,y);
}

void Tracker::setTrackerChar(char tc)
{
    trackerChar = tc;
}

void Tracker::setTrackerDirection(int td)
{
    trackerDirection = td;
}

void Tracker::setRecentCordinate(int x, int y)
{
    recentCordinate[0] = x;
    recentCordinate[1] = y;
}

void Tracker::setLastCordinate()
{
    lastCordinate[0] = recentCordinate[0];
    lastCordinate[1] = recentCordinate[1];
}

char Tracker::getTrackerChar()
{
    return trackerChar;
}

int Tracker::getTrackerDirection()
{
    return trackerDirection;
}

int *Tracker::getRecentCordinate()
{
    return recentCordinate;
}

int *Tracker::getLastCordinate()
{
    return lastCordinate;
}

//
bool Tracker::moveUp(Maze _map)
{
    int x, y;
    x = (this->getRecentCordinate())[0];
    y = (this->getRecentCordinate())[1];

    if(!_map.mazeCheck(x-1,y)){
        return false;
    }
    x--;
    setRecentCordinate(x,y);
    return true;
}

bool Tracker::moveDown(Maze _map)
{
     int x, y;
    x = (this->getRecentCordinate())[0];
    y = (this->getRecentCordinate())[1];

    if(!_map.mazeCheck(x+1,y)){
        return false;
    }
    x++;
    setRecentCordinate(x,y);
    return true;
}
bool Tracker::moveLeft(Maze _map)
{
     int x, y;
    x = (this->getRecentCordinate())[0];
    y = (this->getRecentCordinate())[1];

    if(!_map.mazeCheck(x,y-1)){
        return false;
    }
    y--;
    setRecentCordinate(x,y);
    return true;
}
bool Tracker::moveRight(Maze _map)
{
     int x, y;
    x = (this->getRecentCordinate())[0];
    y = (this->getRecentCordinate())[1];

    if(!_map.mazeCheck(x,y+1)){
        return false;
    }
    y++;
    setRecentCordinate(x,y);
    return true;
}

void Tracker::moveStraight(Maze _map)
{
    if (getTrackerDirection() == UP)
        moveUp(_map);
    else if (getTrackerDirection() == RIGHT)
        moveRight(_map);
    else if (getTrackerDirection() == DOWN)
        moveDown(_map);
    else
        moveLeft(_map);
}

void Tracker::clockwiseDirection()
{
    if(this->getTrackerDirection() == UP){
        setTrackerDirection(RIGHT);
    }
    else if(this->getTrackerDirection() == RIGHT){
        setTrackerDirection(DOWN);
    }
    else if(this->getTrackerDirection() == DOWN){
        setTrackerDirection(LEFT);
    }
    else if(this->getTrackerDirection() == LEFT){
        setTrackerDirection(UP);
    }
}

void Tracker::antiClockwiseDirection()
{
    if(this->getTrackerDirection() == UP){
        setTrackerDirection(LEFT);
    }
    else if(this->getTrackerDirection() == LEFT){
        setTrackerDirection(DOWN);
    }
    else if(this->getTrackerDirection() == DOWN){
        setTrackerDirection(RIGHT);
    }
    else if(this->getTrackerDirection() == RIGHT){
        setTrackerDirection(UP);
    }
}

void Tracker::checkDirection()
{
    if (getRecentCordinate()[0] == 0)
        setTrackerDirection(DOWN);
    else if (getRecentCordinate()[0] == 7)
        setTrackerDirection(UP);

    if (getRecentCordinate()[1] == 0)
        setTrackerDirection(RIGHT);
    else if (getRecentCordinate()[1] == 7)
        setTrackerDirection(LEFT);
}

void Tracker::startTracking(Maze _map)
{
    /*int x, y;
    x = getRecentCordinate()[0];
    y = getRecentCordinate()[1];*/

    int startX, startY;
    startX = getRecentCordinate()[0];
    startY = getRecentCordinate()[1];

    checkDirection();// 摆正人前进的方向
    // 首先不考虑宽道路迷宫的情况
    while(!( (getRecentCordinate()[0] != startX || getRecentCordinate()[1] != startY) &&
            (getRecentCordinate()[0] == 0 || getRecentCordinate()[1] == 0
            || getRecentCordinate()[0] == 7 || getRecentCordinate()[1] == 7)))
    {
        drawMaze(_map,*this);

        if(this->getTrackerDirection() == UP){
            if(_map.mazeCheck(getRecentCordinate()[0], getRecentCordinate()[1] - 1) == false){
                clockwiseDirection();
            }
            else{
                antiClockwiseDirection();
                moveStraight(_map);Sleep(500);
            }
        }
        else if(this->getTrackerDirection() == RIGHT){
            if(_map.mazeCheck(getRecentCordinate()[0] - 1, getRecentCordinate()[1]) == false){
                clockwiseDirection();
            }
            else{
                antiClockwiseDirection();
                moveStraight(_map);Sleep(500);
            }
        }
        else if(this->getTrackerDirection() == DOWN){
            if(_map.mazeCheck(getRecentCordinate()[0], getRecentCordinate()[1] + 1) == false){
                clockwiseDirection();
            }
            else{
                antiClockwiseDirection();
                moveStraight(_map);Sleep(500);
            }
        }
        else if(this->getTrackerDirection() == LEFT){
            if(_map.mazeCheck(getRecentCordinate()[0] + 1, getRecentCordinate()[1]) == false){
                clockwiseDirection();
            }
            else{
                antiClockwiseDirection();
                moveStraight(_map);Sleep(500);
            }
        }

        system("cls");
    }

    drawMaze(_map,*this);
}

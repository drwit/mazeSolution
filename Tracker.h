#ifndef _TRACKER_H_
#define _TRACKER_H_

#include "Maze.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class Tracker
{
public:
    Tracker();
    Tracker(char tc, int x, int y);
    // ���ݷ�װ set
    void setTrackerChar(char tc);
    void setTrackerDirection(int td);
    void setRecentCordinate(int x, int y);
    void setLastCordinate();
    // ���ݷ�װ get
    char getTrackerChar();
    int getTrackerDirection();
    int *getRecentCordinate();
    int *getLastCordinate();
    // ��ͬ����ǰ��
    bool moveUp(Maze _map);
    bool moveDown(Maze _map);
    bool moveLeft(Maze _map);
    bool moveRight(Maze _map);
    void moveStraight(Maze _map);

    void clockwiseDirection();
    void antiClockwiseDirection();
    void checkDirection();
    void startTracking(Maze _map);
private:
    char trackerChar;
    int trackerDirection;
    int recentCordinate[2];
    int lastCordinate[2];
};

#endif // _TRACKER_H_

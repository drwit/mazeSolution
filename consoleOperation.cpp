#include <iostream>
#include "consoleOperation.h"
//#include "Maze.h"
//#include "Tracker.h"

using namespace std;

void drawMaze(Maze _map, Tracker _person)
{
    int i,j;

    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if( (_person.getRecentCordinate())[0] == i &&
               (_person.getRecentCordinate())[1] == j ){
                cout << _person.getTrackerChar();
            }
            else if((_map.getMazeMap())[i][j] == WALL){
                cout << _map.getWallChar();
            }
            else if((_map.getMazeMap())[i][j] == ROAD){
                cout << _map.getRoadChar();
            }
        }
        cout << endl;
    }

}

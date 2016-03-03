#ifndef _MAZE_H_
#define _MAZE_H_

#define WALL 1
#define ROAD 0

class Maze
{
public:
    Maze();
    Maze(char (*_map)[8]);
    void setWallChar(char wc);
    void setRoadChar(char rc);
    void setMazeMap(char _map[][8]);
    char getWallChar();
    char getRoadChar();
    char (*getMazeMap())[8];

    bool mazeCheck(int x, int y);
private:
    char wallChar;
    char roadChar;
    char mazeMap[8][8];
};
#endif // _MAZE_H_

#include<iostream>
using namespace std;
//using namespace sf;
//#include "move_func.h"

void moveFunc(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    board[end.first][end.second] = board[start.first][start.second];
    board[start.first][start.second] = ' ';
}


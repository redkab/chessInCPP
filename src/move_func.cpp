#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
#include<vector>
//using namespace sf;
#include "move_func.h"

void moveFunc(char board[8][8], pair<int, int>start, pair<int, int>end, vector<vector<Sprite>>v)
{
    if(start != end)
    {
    	board[end.first][end.second] = board[start.first][start.second];
    	board[start.first][start.second] = ' ';
    	v[end.first][end.second] = v[start.first][start.second];
    	v[start.first][start.second] = E;
    }
}


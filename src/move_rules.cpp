#include "move_rules.h"
#include <utility>
#include <cmath>
using namespace std;
bool isBlack(char p)
{
    return p>='a' && p<='z';
}

bool isWhite(char p)
{
    return p>='A' && p<='Z';
}

bool isTeam(char p, char q)
{
    return (p>='A' && p<='Z')&&(q>='A' && q<='Z') || (p>='a' && p<='z') && (q>='a' && q<='z');
}

bool isValidKnightMove(pair<int, int>start, pair<int, int>end)
{
    return (abs(end.first - start.first) == 2 && abs(end.second - start.second) == 1) || (abs(end.first - start.first) == 1 && abs(end.second - start.second) == 2);
}

bool isValidKingMove(pair<int, int>start, pair<int, int>end)
{
    return ((abs(end.first - start.first) == 1 || abs(end.first - start.first) == 0) && (abs(end.second - start.second) == 1 || abs(end.second - start.second) == 0));
}

bool isValidBishopMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    if(abs(start.first - end.first) != abs(end.second - start.second))return false;
    int dr, dc;
    dr = end.first - start.first;
    dc = end.second - start.second;
    int q;

    if(dr<0 && dc>0)q=1;
    if(dr<0 && dc<0)q=2;
    if(dr>0 && dc<0)q=3;
    if(dr>0 && dc>0)q=4;
    int delr, delc;
    switch(q)
    {
        case 1:
            delr = -1;
            delc = 1;
            break;
        case 2:
            delr = -1;
            delc = -1;
            break;
        case 3:
            delr = 1;
            delc = -1;
            break;
        case 4:
            delr = 1;
            delc = 1;
            break;
    }

    int row=start.first, col = start.second;
    while (row != end.first || col != end.second)
    {
        if (board[row][col] != ' ')
        {
            return false;
        }

        row += delr;
        col += delc;
    }

    return true;
}



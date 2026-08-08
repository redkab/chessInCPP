#include "move_rules.h"
#include <utility>
#include <cmath>
using namespace std;
int sgn(int x)
{
    return (x>0) - (x<0);
}
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
    while (row + delr != end.first && col +delc != end.second)
    {
        row += delr;
        col += delc;
        if(board[row][col] != ' ')return false;
    }
    if(isTeam(board[start.first][start.second], board[end.first][end.second]))return false;
    return true;
}

bool isValidRookMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    int dr, dc;
    if(!(start.first == end.first || start.second == end.second))
    {
        return false;
    }

    int r=start.first, c=start.second;
    if(isTeam(board[r][c], board[end.first][end.second]))return false;
    if(start.first == end.first)
    {
        dr=0;
        dc=sgn(end.second - start.second);
    }
    else
    {
        dr = sgn(end.first - start.first);
        dc=0;
    }
    r +=dr;
    c+=dc;
    while(r != end.first || c != end.second)
    {
        if(board[r][c] != ' ')return false;
        r = r+dr;
        c = c+dc;
    }
    return true;
}

bool isValidQueenMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    return isValidRookMove(board, start, end) || isValidBishopMove(board, start, end);
}


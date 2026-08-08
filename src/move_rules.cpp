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

bool isValidKnightMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    return (abs(end.first - start.first) == 2 && abs(end.second - start.second) == 1) || (abs(end.first - start.first) == 1 && abs(end.second - start.second) == 2);
}

bool isValidKingMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    return ((abs(end.first - start.first) == 1 || abs(end.first - start.first) == 0) && (abs(end.second - start.second) == 1 || abs(end.second - start.second) == 0));
}

bool isValidBishopMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    if(abs(start.first - end.first) != abs(end.second - start.second))return false;
    int dr, dc;
    dr = end.first - start.first;
    dc = end.second - start.second;
    int delr = sgn(dr);
    int delc = sgn(dc);
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

bool isValidPawnMove(char board[8][8], pair<int, int>start, pair<int, int>end)
{
    int dr, dc;
    dr = end.first - start.first;
    dc = end.second - start.second;
    char pawn = board[start.first][start.second];
    char dest = board[end.first][end.second];
    int dir, sr;
    if(isBlack(board[start.first][start.second]))
    {
        sr = 1;
        dir = 1;
    }
    else
    {
        sr = 6;
        dir = -1;
    }

    if( dc == 0 && dr == dir && dest == ' ')
    {
        return true;
    }

    if(start.first == sr && dr == 2*dir && dc==0  && board[start.first + dir][start.second] == ' ' && dest == ' ')
    {
        return true;
    }

    if(dest != ' ' && dr == dir && abs(dc) == 1)
    {
        if(isTeam(pawn, dest))return false;
        return true;
    }

    return false;
}

bool isLegal(char b[8][8], pair<int, int>start, pair<int ,int>end)
{
    if(start == end)return false;

    char piece = b[start.first][start.second];

    switch(piece)
    {
        case 'R':
        case 'r':
            return isValidRookMove(b, start, end);

        case 'N':
        case 'n':
            return isValidKnightMove(b, start, end);

        case 'B':
        case 'b':
            return isValidBishopMove(b, start, end);

        case 'Q':
        case 'q':
            return isValidQueenMove(b, start, end);

        case 'K':
        case 'k':
            return isValidKingMove(b, start, end);

        case 'P':
        case 'p':
            return isValidPawnMove(b, start, end);

        default:
            return false;
    }
}


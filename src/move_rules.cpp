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
    if(isTeam(board[start.first][start.second], board[end.first][end.second]))return false;
    return (abs(end.first - start.first) == 2 && abs(end.second - start.second) == 1) || (abs(end.first - start.first) == 1 && abs(end.second - start.second) == 2);
}

bool isValidKingMove(char board[8][8], pair<int, int>start, pair<int, int>end,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM)
{
    if(isTeam(board[start.first][start.second], board[end.first][end.second]))return false;
    if(abs(end.first - start.first) <= 1 && abs(end.second - start.second) <= 1) return true;

    char piece = board[start.first][start.second];
    bool black = isBlack(piece);

    if(black && start.first == 0 && start.second == 4 && end.first == 0 && !bKM){
        if(end.second == 6 && !bRRM){
            if(board[0][5] == ' ' && board[0][6] == ' ' && board[0][7] == 'r'){
                if(!isInCheck(board,false)){
                    char tempBoard[8][8];
                    for(int i=0;i<8;i++) for(int j=0;j<8;j++) tempBoard[i][j] = board[i][j];
                    tempBoard[0][5] = 'k';tempBoard[0][4] = ' ';
                    if(!isInCheck(tempBoard,false)) return true;
                }
            }
        }
        if(end.second == 2 && !bRLM){
            if(board[0][1] == ' ' && board[0][2] == ' ' && board[0][3] == ' ' && board[0][0] == 'r'){
                if(!isInCheck(board,false)){
                    char tempBoard[8][8];
                    for(int i=0;i<8;i++) for(int j=0;j<8;j++) tempBoard[i][j] = board[i][j];
                    tempBoard[0][3] = 'k';tempBoard[0][4] =  ' ';
                    if(!isInCheck(tempBoard,false)) return true;
                }
            }
        }
    }

    if(!black && start.first == 7 && start.second == 4 && end.first == 7 && !wKM){
        if(end.second == 6 && !wRRM){
            if(board[7][5] == ' ' && board[7][6] == ' ' && board[7][7] == 'R'){
                if(!isInCheck(board,true)){
                    char tempBoard[8][8];
                    for(int i=0;i<8;i++) for(int j=0;j<8;j++) tempBoard[i][j] = board[i][j];
                    tempBoard[7][5] = 'K';tempBoard[7][4] = ' ';
                    if(!isInCheck(tempBoard,true)) return true;
                }
            }
        }
        if(end.second == 2 && !wRLM){
            if(board[7][1] == ' ' && board[7][2] == ' ' && board[7][3] == ' ' && board[7][0] == 'R'){
                if(!isInCheck(board,true)){
                    char tempBoard[8][8];
                    for(int i=0;i<8;i++) for(int j=0;j<8;j++) tempBoard[i][j] = board[i][j];
                    tempBoard[7][3] = 'K';tempBoard[7][4] =  ' ';   
                    if(!isInCheck(tempBoard,true)) return true;
                }
            }
        }
    }

    return false;
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
    while (row + delr != end.first && col + delc != end.second)
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
    if(isTeam(board[start.first][start.second], board[end.first][end.second]))return false;
    int dr, dc;
    if(!(start.first == end.first || start.second == end.second))
    {
        return false;
    }

    int r=start.first, c=start.second;
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
    r += dr;
    c += dc;
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

bool isValidPawnMove(char board[8][8], pair<int, int>start, pair<int, int>end,vector<bool> &wpMove2,vector<bool> &bpMove2)
{
    int dr, dc;
    dr = end.first - start.first;
    dc = end.second - start.second;
    char pawn = board[start.first][start.second];
    char dest = board[end.first][end.second];
    int dir, sr;

    bool black = isBlack(pawn);

    if(black)
    {
        sr = 1;
        dir = 1;
    }
    else
    {
        sr = 6;
        dir = -1;
    }

    if(dc == 0 && dr == dir && dest == ' ')
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

    //enpassant

    if(dr == dir && abs(dc) == 1 && dest == ' ')
    {
        if(isTeam(pawn,board[start.first][end.second])) return false;
        if(black && wpMove2[end.second] && start.first == 4)
        {
            return true;
        }
        if(!black && bpMove2[end.second] && start.first == 3)
        {
            return true;
        }
    }

    return false;
}

bool isLegal(char b[8][8], pair<int, int>start, pair<int ,int>end,vector<bool> &wpMove2,vector<bool> &bpMove2,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM)
{
    if(start == end)return false;
    if(end.first <0 || end.first >= 8 || end.second <0 || end.second >=8)return 0;
    if(b[end.first][end.second] == 'k' || b[end.first][end.second] == 'K')return false;

    char piece = b[start.first][start.second];
    if(isTeam(piece, b[end.first][end.second]))return false;
    bool valid;

    switch(piece)
    {
        case 'R':
        case 'r':
            valid =  isValidRookMove(b, start, end);
            break;

        case 'N':
        case 'n':
            valid =  isValidKnightMove(b, start, end);
            break;

        case 'B':
        case 'b':
            valid =  isValidBishopMove(b, start, end);
            break;

        case 'Q':
        case 'q':
            valid =  isValidQueenMove(b, start, end);
            break;

        case 'K':
        case 'k':
            valid = isValidKingMove(b, start, end, wKM, bKM, wRLM, wRRM, bRLM, bRRM);
            break;

        case 'P':
        case 'p':
            valid =  isValidPawnMove(b, start, end,wpMove2,bpMove2);
            break;
        default:
            return false;
    }
    if(!valid)return false;

    char tempBoard[8][8];
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            tempBoard[i][j] = b[i][j];
        }
    }
    bool colour;
    colour = isWhite(piece);

    tempBoard[end.first][end.second] = tempBoard[start.first][start.second];
    tempBoard[start.first][start.second] = ' ';

    if((piece == 'P' || piece == 'p') && start.second != end.second && b[end.first][end.second] == ' ')
    {
        tempBoard[start.first][end.second] = ' ';
    }
    
    if(isInCheck(tempBoard, colour))return false;
    return valid;
}

bool isInCheck(char board[8][8], bool colour)// false = black, true = white
{
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    int r, c;
    char search, ek;
    if(colour)
    {
        search = 'K';
        ek = 'k';
    }
    else
    {
        search = 'k';
        ek = 'K';
    }
    bool flag=0;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(board[i][j] == search)
            {
                r = i;
                c = j;
                flag = 1;
                break;
            }
        }
        if(flag)break;
    }

    int ur=r, uc=c;
    for(int i=0; i<4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nr<8 && nc>=0 && nc<8)
        {
            if(board[nr][nc] == ek)return true;
        }
    }

    if(colour)
    {
        if(r-1 >=0 && r-1 <8 && c-1 >=0 && c-1<8)
        {
            if(board[r-1][c-1] == 'p')return true;
        }
        if(r-1>=0 && r-1<8 && c+1>=0 && c+1<8)
        {
            if(board[r-1][c+1] == 'p')return true;
        }
    }

    else
    {
        if(r+1 >=0 && r+1 <8 && c-1 >=0 && c-1<8)
        {
            if(board[r+1][c-1] == 'P')return true;
        }
        if(r+1>=0 && r+1<8 && c+1>=0 && c+1<8)
        {
            if(board[r+1][c+1] == 'P')return true;
        }
    }

    for(int i=0; i<4; i++)
    {
        r = ur + dr[i];
        c = uc + dc[i];
        while(r>=0 && r<8 && c>=0 && c<8)
        {
            char p = board[r][c];
            if(p != ' ' && isTeam(p, search))break;
            if(p != ' ' && !isTeam(p, search))
            {
                if(colour)
                {
                    if(p == 'p' || p == 'n' || p == 'b' || p == 'k')break;
                    if(p == 'q' || p == 'r')return true;
                }
                else
                {
                    if(p == 'P' || p == 'N' || p == 'B' || p == 'K')break;
                    if(p == 'Q' || p == 'R')return true;
                }
            }
            r += dr[i];
            c += dc[i];
        }
    }
    r=ur;
    c=uc;

    int dgr[4] = {1, 1, -1, -1};
    int dgc[4] = {-1, 1, -1, 1};

    for(int i=0; i<4; i++)
    {
        int nr = r + dgr[i];
        int nc = c + dgc[i];
        if(nr>=0 && nr<8 && nc>=0 && nc<8)
        {
            if(board[nr][nc] == ek)return true;
        }
    }

    for(int i=0; i<4; i++)
    {
        r = ur + dgr[i];
        c = uc + dgc[i];

        while(r>=0 && r<8 && c>=0 && c<8)
        {
            char p = board[r][c];
            if(p != ' ' && isTeam(p, search))break;
            if(p!= ' ' && !isTeam(p, search))
            {
                if(colour)
                {
                    if(p == 'r' || p == 'n' || p == 'k' || p == 'p')break;
                    if(p == 'q' || p == 'b')return true;
                }
                else
                {
                    if(p == 'R' || p == 'N' || p == 'K' || p == 'P')break;
                    if(p == 'Q' || p == 'B')return true;
                }
            }
            r += dgr[i];
            c += dgc[i];
        }
    }
    r=ur;
    c=uc;

    int dnr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dnc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for(int i=0; i<8; i++)
    {
        int nr = r + dnr[i];
        int nc = c + dnc[i];
        if(nr>=0 && nr<8 && nc>=0 && nc<8)
        {
            if(colour)
            {
                if(board[nr][nc] == 'n')return true;
            }
            else if(board[nr][nc] == 'N')return true;
        }
    }

    return false;
}

bool hasLegalMoves(char board[8][8], pair<int, int>start, vector<bool> &wpMove2, vector<bool> &bpMove2, bool wKM, bool bKM, bool wRLM, bool wRRM, bool bRLM, bool bRRM)
{
    char p = board[start.first][start.second];
    if(p == ' ')
    {
        return false;
    }
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};

    int dgr[4] = {1, 1, -1, -1};
    int dgc[4] = {-1, 1, -1, 1};

    int dnr[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dnc[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

    int ur = start.first, uc = start.second;
    int r,c, delr, delc;

    if(p == 'q' || p == 'Q' || p == 'r' || p == 'R')
    {
        for(int i=0; i<4; i++)
        {
            delr = dr[i];
            delc = dc[i];
            r = ur + delr;
            c = uc + delc;

            while(r>=0 && r<8 && c>=0 && c<8)
            {
                if(isTeam(p, board[r][c]))break;
                else 
                {
                    if(isLegal(board, start, {r,c},wpMove2,bpMove2,wKM,bKM,wRLM,wRRM,bRLM,bRRM))
                    {
                        return true;
                    }
                }
                r += delr;
                c += delc;
            }
        }
    }

    if(p == 'b' || p == 'B' || p == 'q' || p == 'Q')
    {
        for(int i=0; i<4; i++)
        {
            delr = dgr[i];
            delc = dgc[i];
            r = ur + delr;
            c = uc + delc;

            while(r>=0 && r<8 && c>=0 && c<8)
            {
                if(isTeam(p, board[r][c]))break;
                else 
                {
                    if(isLegal(board, start, {r,c},wpMove2,bpMove2,wKM,bKM,wRLM,wRRM,bRLM,bRRM))
                    {
                        return true;
                    }
                }
                r += delr;
                c += delc;
            }
        }
    }
    r = ur;
    c = uc;
    if(p == 'n' || p == 'N')
    {
        int nr, nc;
        for(int i=0; i<8; i++)
        {
            nr = r + dnr[i];
            nc = c + dnc[i];
            if(nr>=0 && nr<8 && nc>=0 && nc<8)
            {
                if(isLegal(board, start, {nr, nc},wpMove2,bpMove2,wKM,bKM,wRLM,wRRM,bRLM,bRRM))
                {
                    return true;
                }
            }
        }
    }

    r = ur;
    c = uc;

    if(p == 'k' || p == 'K')
    {
        for(int i=0; i<4; i++)
        {
            if(isLegal(board, start, {r + dr[i], c + dc[i]},wpMove2,bpMove2,wKM,bKM,wRLM,wRRM,bRLM,bRRM))
            {
                return true;
            }
            if(isLegal(board, start, {r + dgr[i], c + dgc[i]},wpMove2,bpMove2,wKM,bKM,wRLM,wRRM,bRLM,bRRM))
            {
                return true;
            }
        }
    }

    if(p == 'p')
    {
        return (isLegal(board, start, {r+1, c-1},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r+1, c},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r+1, c+1},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r+2, c},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM));
    }

    if(p == 'P')
    {
        return (isLegal(board, start, {r-1, c-1},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r-1, c},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r-1, c+1},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM) || isLegal(board, start, {r-2, c},wpMove2,bpMove2,wKM, bKM, wRLM, wRRM, bRLM, bRRM));
    }
    return false;
}

// i like this checking
bool isCheckmate(char board[8][8], bool colour, vector<bool> &wpMove2, vector<bool> &bpMove2, bool wKM, bool bKM, bool wRLM, bool wRRM, bool bRLM, bool bRRM)//false = black, true = white
{
    char t;
    if(colour)t = 'K';
    else t = 'k';
    if(!isInCheck(board, colour))return false;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(isTeam(t, board[i][j]))
            {
                if(hasLegalMoves(board, {i,j}, wpMove2, bpMove2, wKM, bKM, wRLM, wRRM, bRLM, bRRM))
                {
                    return false;
                }
            }
        }
    }
    return true;
}

bool isStalemate(char board[8][8], bool colour, vector<bool> &wpMove2, vector<bool> &bpMove2, bool wKM, bool bKM, bool wRLM, bool wRRM, bool bRLM, bool bRRM)
{
    char t;
    if(colour)t = 'K';
    else t = 'k';
    if(isInCheck(board, colour))return false;

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(isTeam(t, board[i][j]))
            {
                if(hasLegalMoves(board, {i,j}, wpMove2, bpMove2, wKM, bKM, wRLM, wRRM, bRLM, bRRM))
                {
                    return false;
                }
            }
        }
    }
    return true;
}



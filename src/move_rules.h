#ifndef MOVE_RULES_H
#define MOVE_RULES_H

#include <utility>
#include<vector>
#include<cmath>

bool isLegal(char board[8][8], std::pair<int, int>start, std::pair<int, int>end,std::vector<bool> &wpMove2, std::vector<bool> &bpMove2,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM);
bool isWhite(char p);
bool isBlack(char p);
bool isTeam(char p, char q);
bool isValidKnightMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidKingMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM);
bool isValidRookMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidQueenMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidPawnMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end, std::vector<bool> &wpMove2, std::vector<bool> &bpMove2);
bool isValidBishopMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
int sgn(int x);
bool isInCheck(char board[8][8], bool colour);
bool hasLegalMoves(char board[8][8], std::pair<int, int>start,std::vector<bool> &wpMove2, std::vector<bool> &bpMove2,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM);
bool isCheckmate(char board[8][8], bool colour,std::vector<bool> &wpMove2, std::vector<bool> &bpMove2,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM);
bool isStalemate(char board[8][8], bool colour,std::vector<bool> &wpMove2, std::vector<bool> &bpMove2,bool wKM,bool bKM,bool wRLM,bool wRRM,bool bRLM,bool bRRM);
#endif

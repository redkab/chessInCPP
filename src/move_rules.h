#ifndef MOVE_RULES_H
#define MOVE_RULES_H

#include <utility>
#include<cmath>

bool isLegal(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isWhite(char p);
bool isBlack(char p);
bool isTeam(char p, char q);
bool isValidKnightMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidRookMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidQueenMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidPawnMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isValidBishopMove(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
int sgn(int x);
bool isLegal(char board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isInCheck(char board[8][8], bool colour);
#endif

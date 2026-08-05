#ifndef MOVE_RULES_H
#define MOVE_RULES_H

#include <utility>
#include<cmath>

bool isLegal(board[8][8], std::pair<int, int>start, std::pair<int, int>end);
bool isWhite(char w);
bool isBlack(char b);
bool isTeam(char p, char q);
bool isValidKnightMove(pair<int, int>start, pair<int, int>end);

#endif

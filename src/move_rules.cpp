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

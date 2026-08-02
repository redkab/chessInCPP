#ifndef TEXSPRI_H
#define TEXSPRI_H

#include <SFML/Graphics.hpp>

extern sf::Texture wKt, wQt, wNt, wBt, wRt, wPt;
extern sf::Texture bKt, bQt, bNt, bBt, bRt, bPt;

extern sf::Sprite wK, wQ, wN1, wN2, wB1, wB2, wR1, wR2;
extern sf::Sprite wP[8];

extern sf::Sprite bK, bQ, bN1, bN2, bB1, bB2, bR1, bR2;
extern sf::Sprite bP[8];

void loadTextures();

#endif

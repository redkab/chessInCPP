#include "texspri.h"
#include <iostream>
using namespace sf;
using namespace std;

Texture wKt, wQt, wNt, wBt, wRt, wPt;
Texture bKt, bQt, bNt, bBt, bRt, bPt;

Sprite wK, wQ, wN1, wN2, wB1, wB2, wR1, wR2;
Sprite wP[8];

Sprite bK, bQ, bN1, bN2, bB1, bB2, bR1, bR2;
Sprite bP[8];

void loadTextures()
{
	// whiteking
	if(!wKt.loadFromFile("../assets/pieces/wK.png"))
	{
		cout<<"Error\n";
	}
	wK.setTexture(wKt);
	wK.setScale(100.0f/wKt.getSize().x, 100.0f/wKt.getSize().y);
	wK.setPosition(400, 700);

	// whitequeen
	if(!wQt.loadFromFile("../assets/pieces/wQ.png"))
	{
		cout<<"Error\n";
	}
	wQ.setTexture(wQt);
	wQ.setScale(100.0f/wQt.getSize().x, 100.0f/wQt.getSize().y);
	wQ.setPosition(300, 700);

	// whiteknight1
	if(!wNt.loadFromFile("../assets/pieces/wN.png"))
	{
		cout<<"Error\n";
	}
	wN1.setTexture(wNt);
	wN1.setScale(100.0f/wNt.getSize().x, 100.0f/wNt.getSize().y);
	wN1.setPosition(100, 700);

	// whiteknight2
	wN2.setTexture(wNt);
	wN2.setScale(100.0f/wNt.getSize().x, 100.0f/wNt.getSize().y);
	wN2.setPosition(600, 700);

	// whitebishop1
	if(!wBt.loadFromFile("../assets/pieces/wB.png"))
	{
		cout<<"Error\n";
	}
	wB1.setTexture(wBt);
	wB1.setScale(100.0f/wBt.getSize().x, 100.0f/wBt.getSize().y);
	wB1.setPosition(200, 700);

	// whitebishop2
	wB2.setTexture(wBt);
	wB2.setScale(100.0f/wBt.getSize().x, 100.0f/wBt.getSize().y);
	wB2.setPosition(500, 700);

	// whiterook1
	if(!wRt.loadFromFile("../assets/pieces/wR.png"))
	{
		cout<<"Error\n";
	}
	wR1.setTexture(wRt);
	wR1.setScale(100.0f/wRt.getSize().x, 100.0f/wRt.getSize().y);
	wR1.setPosition(700, 700);

	// whiterook2
	wR2.setTexture(wRt);
	wR2.setScale(100.0f/wRt.getSize().x, 100.0f/wRt.getSize().y);
	wR2.setPosition(0, 700);

	// whitepawns
	if(!wPt.loadFromFile("../assets/pieces/wP.png"))
	{
		cout<<"Error\n";
	}
	for(int i = 0; i < 8; i++)
	{
		wP[i].setTexture(wPt);
		wP[i].setScale(100.0f/wPt.getSize().x, 100.0f/wPt.getSize().y);
		wP[i].setPosition((float)i*100.0f, 600);
	}

	// blackking
	if(!bKt.loadFromFile("../assets/pieces/bK.png"))
	{
		cout<<"Error\n";
	}
	bK.setTexture(bKt);
	bK.setScale(100.0f/bKt.getSize().x, 100.0f/bKt.getSize().y);
	bK.setPosition(400, 0);

	// blackqueen
	if(!bQt.loadFromFile("../assets/pieces/bQ.png"))
	{
		cout<<"Error\n";
	}
	bQ.setTexture(bQt);
	bQ.setScale(100.0f/bQt.getSize().x, 100.0f/bQt.getSize().y);
	bQ.setPosition(300, 0);

	// blackknight1
	if(!bNt.loadFromFile("../assets/pieces/bN.png"))
	{
		cout<<"Error\n";
	}
	bN1.setTexture(bNt);
	bN1.setScale(100.0f/bNt.getSize().x, 100.0f/bNt.getSize().y);
	bN1.setPosition(100, 0);

	// blackknight2
	bN2.setTexture(bNt);
	bN2.setScale(100.0f/bNt.getSize().x, 100.0f/bNt.getSize().y);
	bN2.setPosition(600, 0);

	// blackbishop1
	if(!bBt.loadFromFile("../assets/pieces/bB.png"))
	{
		cout<<"Error\n";
	}
	bB1.setTexture(bBt);
	bB1.setScale(100.0f/bBt.getSize().x, 100.0f/bBt.getSize().y);
	bB1.setPosition(200, 0);

	// blackbishop2
	bB2.setTexture(bBt);
	bB2.setScale(100.0f/bBt.getSize().x, 100.0f/bBt.getSize().y);
	bB2.setPosition(500, 0);

	// blackrook1
	if(!bRt.loadFromFile("../assets/pieces/bR.png"))
	{
		cout<<"Error\n";
	}
	bR1.setTexture(bRt);
	bR1.setScale(100.0f/bRt.getSize().x, 100.0f/bRt.getSize().y);
	bR1.setPosition(700, 0);

	// blackrook2
	bR2.setTexture(bRt);
	bR2.setScale(100.0f/bRt.getSize().x, 100.0f/bRt.getSize().y);
	bR2.setPosition(0, 0);

	// blackpawns
	if(!bPt.loadFromFile("../assets/pieces/bP.png"))
	{
		cout<<"Error\n";
	}
	for(int i = 0; i < 8; i++)
	{
		bP[i].setTexture(bPt);
		bP[i].setScale(100.0f/bPt.getSize().x, 100.0f/bPt.getSize().y);
		bP[i].setPosition((float)i*100.0f, 100);
	}
}

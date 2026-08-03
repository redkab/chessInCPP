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

void setBoardPositions(vector<vector<Sprite>>& v)
{
    for(int row = 0; row < 8; row++)
    {
        for(int col = 0; col < 8; col++)
        {
            v[row][col].setPosition(col * 100.0f, row * 100.0f);
        }
    }
}

vector<vector<Sprite>> initializeObjVec()
{
    vector<vector<Sprite>>v(8, vector<Sprite>(8));
    v[0][0] = bR1;
    v[0][1] = bN1;
    v[0][2] = bB1;
    v[0][3] = bQ;
    v[0][4] = bK;
    v[0][5] = bB2;
    v[0][6] = bN2;
    v[0][7] = bR2;
    for(int i=0; i<8; i++)
    {
        v[1][i] = bP[i];
    }
    v[7][0] = wR1;
    v[7][1] = wN1;
    v[7][2] = wB1;
    v[7][3] = wQ;
    v[7][4] = wK;
    v[7][5] = wB2;
    v[7][6] = wN2;
    v[7][7] = wR2;

    for(int i=0; i<8; i++)
    {
        v[6][i] = wP[i];
    }
    return v;
}

void loadTextures()
{
	// whiteking
	if(!wKt.loadFromFile("../assets/pieces/wK.png"))
	{
		cout<<"Error\n";
	}
	wK.setTexture(wKt);
	wK.setScale(100.0f/wKt.getSize().x, 100.0f/wKt.getSize().y);

	// whitequeen
	if(!wQt.loadFromFile("../assets/pieces/wQ.png"))
	{
		cout<<"Error\n";
	}
	wQ.setTexture(wQt);
	wQ.setScale(100.0f/wQt.getSize().x, 100.0f/wQt.getSize().y);


	// whiteknight1
	if(!wNt.loadFromFile("../assets/pieces/wN.png"))
	{
		cout<<"Error\n";
	}
	wN1.setTexture(wNt);
	wN1.setScale(100.0f/wNt.getSize().x, 100.0f/wNt.getSize().y);


	// whiteknight2
	wN2.setTexture(wNt);
	wN2.setScale(100.0f/wNt.getSize().x, 100.0f/wNt.getSize().y);


	// whitebishop1
	if(!wBt.loadFromFile("../assets/pieces/wB.png"))
	{
		cout<<"Error\n";
	}
	wB1.setTexture(wBt);
	wB1.setScale(100.0f/wBt.getSize().x, 100.0f/wBt.getSize().y);


	// whitebishop2
	wB2.setTexture(wBt);
	wB2.setScale(100.0f/wBt.getSize().x, 100.0f/wBt.getSize().y);


	// whiterook1
	if(!wRt.loadFromFile("../assets/pieces/wR.png"))
	{
		cout<<"Error\n";
	}
	wR1.setTexture(wRt);
	wR1.setScale(100.0f/wRt.getSize().x, 100.0f/wRt.getSize().y);


	// whiterook2
	wR2.setTexture(wRt);
	wR2.setScale(100.0f/wRt.getSize().x, 100.0f/wRt.getSize().y);


	// whitepawns
	if(!wPt.loadFromFile("../assets/pieces/wP.png"))
	{
		cout<<"Error\n";
	}
	for(int i = 0; i < 8; i++)
	{
		wP[i].setTexture(wPt);
		wP[i].setScale(100.0f/wPt.getSize().x, 100.0f/wPt.getSize().y);		
	}

	// blackking
	if(!bKt.loadFromFile("../assets/pieces/bK.png"))
	{
		cout<<"Error\n";
	}
	bK.setTexture(bKt);
	bK.setScale(100.0f/bKt.getSize().x, 100.0f/bKt.getSize().y);


	// blackqueen
	if(!bQt.loadFromFile("../assets/pieces/bQ.png"))
	{
		cout<<"Error\n";
	}
	bQ.setTexture(bQt);
	bQ.setScale(100.0f/bQt.getSize().x, 100.0f/bQt.getSize().y);


	// blackknight1
	if(!bNt.loadFromFile("../assets/pieces/bN.png"))
	{
		cout<<"Error\n";
	}
	bN1.setTexture(bNt);
	bN1.setScale(100.0f/bNt.getSize().x, 100.0f/bNt.getSize().y);

	// blackknight2
	bN2.setTexture(bNt);
	bN2.setScale(100.0f/bNt.getSize().x, 100.0f/bNt.getSize().y);


	// blackbishop1
	if(!bBt.loadFromFile("../assets/pieces/bB.png"))
	{
		cout<<"Error\n";
	}
	bB1.setTexture(bBt);
	bB1.setScale(100.0f/bBt.getSize().x, 100.0f/bBt.getSize().y);


	// blackbishop2
	bB2.setTexture(bBt);
	bB2.setScale(100.0f/bBt.getSize().x, 100.0f/bBt.getSize().y);


	// blackrook1
	if(!bRt.loadFromFile("../assets/pieces/bR.png"))
	{
		cout<<"Error\n";
	}
	bR1.setTexture(bRt);
	bR1.setScale(100.0f/bRt.getSize().x, 100.0f/bRt.getSize().y);


	// blackrook2
	bR2.setTexture(bRt);
	bR2.setScale(100.0f/bRt.getSize().x, 100.0f/bRt.getSize().y);


	// blackpawns
	if(!bPt.loadFromFile("../assets/pieces/bP.png"))
	{
		cout<<"Error\n";
	}
	for(int i = 0; i < 8; i++)
	{
		bP[i].setTexture(bPt);
		bP[i].setScale(100.0f/bPt.getSize().x, 100.0f/bPt.getSize().y);
	}
}

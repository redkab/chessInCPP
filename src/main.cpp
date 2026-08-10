#include "texspri.h"
#include "move_func.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "move_rules.h"
//#include "materializer.h"
using namespace std;
using namespace sf;


int main()
{
    char b[8][8] = {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' ',' ',' ',' '},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'},	
    };
    RenderWindow win(VideoMode(800, 800), "Taesef");
    loadTextures();
    int x,y;
    Color dark_green(0, 100, 0);
    Color cream(238, 238, 210);
    vector<vector<RectangleShape>> v(8, vector<RectangleShape>(8));
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            RectangleShape rec; 
            rec.setSize(Vector2f(100, 100));
            if((i+j)%2==0)
            {
                rec.setFillColor(cream);
            }
            else
            {
                rec.setFillColor(dark_green);
            }
            rec.setPosition({(float)i*100.0f, (float)j*100.0f});
            v[i][j] = rec;
        }
    }


    pair<int, int>start, end;
    bool flag = true;
    bool turn = true;
    bool over = false;
    bool promo = false;
    pair<int, int>promoSquare;
    bool whitePromo = false;
    RectangleShape promoMenu;
    promoMenu.setSize(Vector2f(400, 100));
    promoMenu.setPosition(200, 350);
    promoMenu.setFillColor(Color(112, 138, 164));
    Sprite wpq = wQ, wpr = wR1, wpn = wN1, wpb = wB1;
    Sprite bpq = bQ, bpr = bR1, bpn = bN1, bpb = bB1;

    wpq.setPosition(200, 350);
    wpr.setPosition(300, 350);
    wpn.setPosition(400, 350);
    wpb.setPosition(500, 350);
    bpq.setPosition(200, 350);
    bpr.setPosition(300, 350);
    bpn.setPosition(400, 350);
    bpb.setPosition(500, 350);

    while(win.isOpen())
    {
        Event e;
        while(win.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                win.close();
            }

            if(e.type == Event::MouseButtonPressed && e.mouseButton.button == Mouse::Left)
            {
                if(over)
                {
                    continue;
                }
                if(promo)
                {
                    int x = e.mouseButton.x;
                    int y = e.mouseButton.y;
                    char chosenPiece = ' ';
                    if(y>=350 && y<450)
                    {
                        if(x >= 200 && x<300)
                        {
                            chosenPiece = 'Q';
                        }
                        else if(x >= 300 && x<400)
                        {
                            chosenPiece = 'R';
                        }
                        else if(x >= 400 && x<500)
                        {
                            chosenPiece = 'N';
                        }
                        else if(x >= 500 && x<600)
                        {
                            chosenPiece = 'B';
                        }
                        if(chosenPiece != ' ')
                        {
                            if(!whitePromo)
                            {
                                chosenPiece = tolower(chosenPiece);
                            }
                            b[promoSquare.first][promoSquare.second] = chosenPiece;
                            promo = false;
                            if(isCheckmate(b, !turn))
                            {
                                over = true;
                                if(turn)
                                {
                                    cout << "Checkmate! White wins!" << endl;
                                }
                                    else
                                    {
                                    cout << "Checkmate! Black wins!" << endl;
                                    }
                            }
                            else if(isStalemate(b, !turn))
                            {
                                over = true;
                                cout << "Stalemate! Match will end in a draw!" << endl;
                            }

                            turn = !turn;
                        }
                    }
                    continue;
                }
                int row = e.mouseButton.y/100;
                int col = e.mouseButton.x/100;
                if(row>=8 || row <0 || col >=8 || col <0)
                {
                    continue;
                }
                char p = b[row][col];
                if(flag)
                {
                    if(p == ' ')
                    {
                        cout<<"Empty\n";
                    }
                    else 
                    {
                        cout<<"start Selected "<<p<<endl;
                        start = {row, col};   
                        flag = false;  	
                    }
                }
                else
                {
                    cout<<"end Selected "<<p<<endl;
                    end = {row, col};
                    flag = true;
                    if(isLegal(b, start, end))
                    {
                        char moving = b[start.first][start.second];

                        if(turn && isWhite(b[start.first][start.second]))
                        {
                            moveFunc(b, start, end);
                            if(( moving == 'P' && end.first == 0))
                            {
                                promo = true;
                                promoSquare = end;
                                whitePromo = true;
                                continue;
                            }
                            if(isCheckmate(b, !turn))
                            {
                                over = true;
                                cout<<"Checkmate! White wins!"<<endl;
                                break;
                            }
                            if(isStalemate(b, !turn))
                            {
                                over = true;
                                cout<<"Stalemate! Match will end in a draw!"<<endl;
                                break;
                            }
                            turn = false;
                        }
                        if(!turn && isBlack(b[start.first][start.second]))
                        {
                            moveFunc(b, start, end);
                            if((moving  == 'p' && end.first == 7))
                            {
                                promo = true;
                                promoSquare = end;
                                whitePromo = false;
                                continue;
                            }
                            if(isCheckmate(b, !turn))
                            {
                                over = true;
                                cout<<"Checkmate! Black wins!"<<endl;
                                break;
                            }
                            if(isStalemate(b, !turn))
                            {
                                over = true;
                                cout<<"Stalemate! Match will end in a draw!"<<endl;
                                break;
                            }
                            turn = true;
                        }
                    }
                    else 
                    {
                        cout<<"Illegal"<<endl;
                        //grafiks
                    }
                }

            }
        }
        win.clear(Color::Black);
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                win.draw(v[i][j]);
            }
        }
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                Sprite *s = nullptr;
                if(b[i][j] == ' ')continue;

                switch (b[i][j])
                {
                    case 'R':
                        s = &wR1;
                        break;

                    case 'N':
                        s = &wN1;
                        break; 

                    case'B':
                        s = &wB1;
                        break;

                    case 'K':
                        s = &wK;
                        break;

                    case 'Q':
                        s = &wQ;
                        break;

                    case 'P':
                        s = &wP[0];
                        break;

                    case 'r':
                        s = &bR1;
                        break;

                    case 'n':
                        s = &bN1;
                        break;

                    case 'b':
                        s = &bB1;
                        break;

                    case 'k':
                        s = &bK;
                        break;

                    case 'q':
                        s = &bQ;
                        break;

                    case 'p':
                        s = &bP[0];
                        break;
                }
                if(s != nullptr)
                {
                    s->setPosition(j*100.0f, i*100.0f);
                    win.draw(*s);
                }
            }
        }
        if(promo)
        {
            win.draw(promoMenu);

            if(whitePromo)
            {
                win.draw(wpq);
                win.draw(wpr);
                win.draw(wpn);
                win.draw(wpb);
            }
            else
            {
                win.draw(bpq);
                win.draw(bpr);
                win.draw(bpn);
                win.draw(bpb);
            }
        }
        win.display();
    }
}


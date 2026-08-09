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
                    if(isLegal(b, start, end) && turn)
                    {
		                
		                if(turn && isWhite(b[start.first][start.second]))
		                {
		                	moveFunc(b, start, end);
		                	turn = false;
		                }
		                if(!turn && isBlack(b[start.first][start.second]))
		                {
		                	moveFunc(b, start, end);
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
        /*win.draw(wK);
          win.draw(wQ);
          win.draw(wN1);
          win.draw(wN2);
          win.draw(wB1);
          win.draw(wB2);
          win.draw(wR1);
          win.draw(wR2);
          win.draw(bK);
          win.draw(bQ);
          win.draw(bN1);
          win.draw(bN2);
          win.draw(bB1);
          win.draw(bB2);
          win.draw(bR1);
          win.draw(bR2);
          for(int i = 0; i < 8; i++){
          win.draw(wP[i]);
          win.draw(bP[i]);
          }*/

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
        win.display();
    }
}

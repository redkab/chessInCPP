#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow win(VideoMode(800, 800), "Taesef");
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

    Texture kingtex;

    if(!kingtex.loadFromFile("../assets/pieces/black_king.png"))
    {
        cout<<"Error\n";
    }

    Sprite king;
    king.setTexture(kingtex);

    king.setScale(100.0f/kingtex.getSize().x, 100.0f/kingtex.getSize().y);
    king.setPosition(400, 300);


    while(win.isOpen())
    {
        Event e;
        while(win.pollEvent(e))
        {
            if(e.type == Event::Closed)
            {
                win.close();
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
        win.draw(king);
        win.display();
    }

}

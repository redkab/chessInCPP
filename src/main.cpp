#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow win(VideoMode(900, 969), "Taesef");
    RectangleShape rec;
    rec.setSize(Vector2f(169, 167));
    rec.setOutlineColor(Color::Red);
    rec.setFillColor(Color::Blue);
    rec.setPosition({0, 0});
    win.draw(rec);
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
        win.display();
    }


}

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
    rec.setPosition({100, 0});
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
        win.draw(rec);
        win.display();
    }


}

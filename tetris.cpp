#include <SFML/Graphics.hpp>
#include <time.h>
#include "heads.h"
#include "Field.h"




bool check()
{
    for (int i = 0; i < 4; i++)
        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
        else if (field[a[i].y][a[i].x]) return 0;

    return 1;
};

class tetris() {
private:
    gameField(m_gameField);
};


int main()
{
    srand(time(0));

    RenderWindow window(VideoMode(320, 480), "The Game!");

    Texture t1, t2, t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");

    Sprite s(t1), background(t2), frame(t3);

    int dx = 0; bool rotate = 0; int colorNum = 1;
    float timer = 0, delay = 0.3;

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

            if (e.type == Event::KeyPressed)
                if (e.key.code == Keyboard::Up) rotate = true;
                else if (e.key.code == Keyboard::Left) dx = -1;
                else if (e.key.code == Keyboard::Right) dx = 1;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

        //// <- Move -> ///
        move();

        //////Rotate//////
        if (rotate)
            rotate();

        ///////Tick//////
        if (timer > delay)
            tick();

        ///////check lines//////////
        checklines();

        /////////draw//////////
        paint();
    }

    return 0;
}
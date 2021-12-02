
#include <SFML/Graphics.hpp>
#include <time.h>
#include <Windows>
#include "Canvas.h"

canvas::canvas(){
    RenderWindow window(VideoMode(320, 480), "The Game!");

    Texture t1, t2, t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");

    Sprite s(t1), background(t2), frame(t3);
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include "mandel.hpp"
int 
main()
{
    int width = 1280;
    int height = 720;
    const coord_t shift = {(long double) width/2, (long double) height/2};
    
    long double zoom = 300;

    sf::String title = "MandelExplorer";
    sf::RenderWindow window(sf::VideoMode(width, height), title);
    sf::err().rdbuf(NULL);
    window.setFramerateLimit(10); //CHANGE
    sf::VertexArray set(sf::Points, width * height);
    
    
    mandelbrot res = mandelbrot(width, height, shift, zoom, set);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        
        window.clear();
        window.draw(set);
        window.display();
    }
}   

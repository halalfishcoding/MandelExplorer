#ifndef MANDEL_H
#define MANDEL_H

#include <complex>
#include <iostream>
#include <utility>
#include <SFML/graphics.hpp>


typedef std::pair<long double, long double> coord_t;

class 
mandelbrot 
{
public:
    mandelbrot(int width, int height, const coord_t &shift_, long double zoom_, sf::VertexArray &vertexarray);
    int mandel(sf::VertexArray &vertexarray);
    std::string res;

private:
    long double zoom;
    int MAX_ITER;
    int width;
    int height;
    coord_t shift;
};

#endif 
#include "mandel.hpp"

mandelbrot::mandelbrot
(int width_, int height_, const coord_t& shift_, long double zoom_, sf::VertexArray &vertexarray)
    : width(width_), height(height_), shift(shift_), MAX_ITER(100), zoom(zoom_) {
        mandel(vertexarray);
};

int
mandelbrot::mandel(sf::VertexArray &vertexarray)
{
    std::string res = "";

    #pragma omp parallel for
    for (int j = 0; j < width; j++)
    {
        for (int i = 0; i < height; i++)
        {   
            long double x = ((long double)j - shift.first) / zoom;
            long double y = ((long double)i - shift.second) / zoom;
            std::complex<long double> z = {(long double)0, (long double)0};
            std::complex<long double> c = {
                (long double) y,
                (long double) x
            };
            int iteration = 0;

            while (abs(z) < 2 && ++iteration < MAX_ITER)
                z = pow(z, 2) + c;
            
            //std::cout << iteration << std::endl;
            

            //adding to vertexarray

            if (iteration < MAX_ITER / 4.0f)
            {
                vertexarray[i*width + j].position = sf::Vector2f(j, i);
                sf::Color color(iteration * 255.0f / (MAX_ITER / 4.0f), 0, 0);
                vertexarray[i*width + j].color = color;
            }
            else if (iteration < MAX_ITER / 2.0f)
            {
                vertexarray[i*width + j].position = sf::Vector2f(j, i);
                sf::Color color(0, iteration * 255.0f / (MAX_ITER / 2.0f), 0);
                vertexarray[i*width + j].color = color;
            }
            else if (iteration < MAX_ITER)
            {
                vertexarray[i*width + j].position = sf::Vector2f(j, i);
                sf::Color color(0, 0, iteration * 255.0f / MAX_ITER);
                vertexarray[i*width + j].color = color;
            }
            
        }
        
    }
    return 0;
}


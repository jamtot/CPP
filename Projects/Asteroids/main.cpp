#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "Asteroid.h"

int main()
{
    // Create the main window
    int windowsize[2] = {1600,1000};
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(windowsize[0], windowsize[1]), "SFML window");
    Ship *pShip = new Ship(windowsize[0]/2, windowsize[1]/2, 20.f, 30.f, window, windowsize);
    Asteroid *ast = new Asteroid(windowsize[0]/2, windowsize[1]/2,25,5,window,windowsize);

	// Start the game loop
    while (window->isOpen())
    {
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window->close();
        }

        // Clear screen
        window->clear();

        pShip->draw();
        ast->draw();

        window->display();

        pShip->update();
        ast->update();
    }

    return EXIT_SUCCESS;
}

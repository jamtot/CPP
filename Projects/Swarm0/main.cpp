#include <SFML/Graphics.hpp>
#include "Swarm.h"
#include "Ship.h"
#include "Flock.h"

int main()
{
    //srand();

    // Create the main window
    int windowsize[2] = {1600,1000};
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(windowsize[0], windowsize[1]), "SFML window");
    Ship *player = new Ship(windowsize[0]/2, windowsize[1]/2, 20.f, 30.f, window, windowsize);
    //Swarm *s = new Swarm(window, 10000, windowsize);
    Flock *flock = new Flock(window, windowsize);

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

        // Draw the sprite
        //s->draw();
        flock->draw();
        player->draw();

        // Update the window
        window->display();

        player->update();
        //s->update();
        flock->update();

    }

    return EXIT_SUCCESS;
}

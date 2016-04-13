#include <SFML/Graphics.hpp>
#include "Swarm.h"

int main()
{
    // Create the main window
    int windowsize[2] = {1600,1000};
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(windowsize[0], windowsize[1]), "SFML window");
    Swarm *s = new Swarm(window, 10000, windowsize);

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
        s->draw();


        // Update the window
        window->display();
        s->update();
    }

    return EXIT_SUCCESS;
}

#include <SFML/Graphics.hpp>
#include "Ship.h"
#include "AsteroidFactory.h"
#include "ExplosionFactory.h"
#include "Explosion.h"

int main()
{
    // Create the main window
    int windowsize[2] = {1600,1000};
    sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(windowsize[0], windowsize[1]), "SFML window");
    Ship *pShip = new Ship(windowsize[0]/2, windowsize[1]/2, 20.f, 30.f, window, windowsize);
    AsteroidFactory * astFact = AsteroidFactory::getInstance(pShip);

    ExplosionFactory * expFact = ExplosionFactory::getInstance();

    astFact->SetShip(pShip); // setting the ship and bullet vector in asteroid factory

    //Asteroid *ast = new Asteroid(windowsize[0]/2, windowsize[1]/2,25,5,window,windowsize);
    astFact->CreateObject(windowsize[0]/4, windowsize[1]/2,25,5,window,windowsize);
    astFact->CreateObject(windowsize[0]/2, windowsize[1]/2,25,5,window,windowsize);
    astFact->CreateObject((windowsize[0]/4)*3, windowsize[1]/2,25,5,window,windowsize);

    Explosion e = Explosion(sf::Vector2f(windowsize[0]/2,windowsize[1]/2),5,128,50,window);

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
        astFact->draw();
        expFact->draw();
        e.draw();

        window->display();

        pShip->update();
        astFact->update();
        expFact->update();
        e.update();
    }

    return EXIT_SUCCESS;
}

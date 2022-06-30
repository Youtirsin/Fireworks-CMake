#include <SFML/Graphics.hpp>

#include "fireworks.h"
#include "util.h"

int main() {
  // random seed
  srand(time(0));
  const int WIN_WIDTH = 1000;
  const int WIN_HEIGHT = 720;
  const char* WIN_TITLE = "Fireworks by Youtirsin";

  // create the window
  sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), WIN_TITLE);

  std::vector<Fireworks> fireworks_grp;
  std::vector<Particle> particle_grp;

  for (int i = 0; i < 5; i++) {
    fireworks_grp.emplace_back(randColor(), WIN_HEIGHT, WIN_WIDTH);
  }

  // global clock
  sf::Clock clock;
  sf::Time t;
  sf::Time elapsed;

  // run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) window.close();
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

    // update elapsed time
    elapsed += t;

    // draw everything here...
    // window.draw(...);
    for (auto it = fireworks_grp.begin(); it != fireworks_grp.end();) {
      it->update();
      window.draw(*it);

      if (!it->isAlive()) {
        it->explore(particle_grp);
        it = fireworks_grp.erase(it);
      } else {
        ++it;
      }
    }

    for (auto it = particle_grp.begin(); it != particle_grp.end();) {
      it->update();
      window.draw(*it);

      if (!it->isAlive()) {
        it = particle_grp.erase(it);
      } else {
        ++it;
      }
    }

    if (elapsed.asSeconds() >= rand(5, 15) / 10.f) {
      fireworks_grp.emplace_back(randColor(), WIN_HEIGHT, WIN_WIDTH);
      elapsed = sf::Time::Zero;
    }

    t = clock.restart();
    sf::sleep(sf::seconds(DELTA_T - t.asSeconds()));

    // end the current frame
    window.display();
  }

  return 0;
}
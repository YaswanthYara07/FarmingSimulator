//Farm Functionality and Display

#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <string>

#ifndef FARM_H
#define FARM_H

using namespace std;
using namespace sf;
// Farm Class
class Farm {
 private:
  // Plot Shape
  RectangleShape* farm;

 public:
  // Main Farm Land including plots
  Farm(int r, int x, int y) {
    farm = new RectangleShape();
    farm->setSize(Vector2f(r, r));
    farm->setPosition(x, y);
    farm->setFillColor(sf::Color(255, 231, 112));
    farm->setOutlineColor(Color::Black);
    farm->setOutlineThickness(5);
  }
  // Draw Farm
  void draw(RenderWindow* win) { win->draw(*farm); };
  // Change Color if Fertile
  int isFertile() {
    Color fertile(86, 61, 49);
    if (Keyboard::isKeyPressed(Keyboard::Q)) {
      farm->setFillColor(fertile);
      return 1;
    }
    return 0;
  }
  // Fertiilised Color
  void isFertilized() {
    Color fertilized(54, 36, 25);
    if (Keyboard::isKeyPressed(Keyboard::P)) {
      farm->setFillColor(fertilized);
    }
  }
  // Harvested Color
  void isHarvested() {
    if (Keyboard::isKeyPressed(Keyboard::O)) {
      farm->setFillColor(Color::Yellow);
    }
  }
};

#endif
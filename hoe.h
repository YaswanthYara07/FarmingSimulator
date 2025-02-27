//Hoe Functionality

#include <SFML/Graphics.hpp>
#include <iostream>
#ifndef HOE_H
#define HOE_H

// Hoe Class
class hoe {
 protected:
  // Hoe Shape
  sf::RectangleShape* hoe1;

 public:
  // Constructor
  hoe() {
    hoe1 = new sf::RectangleShape();
    hoe1->setSize(sf::Vector2f(10, 10));
    hoe1->setPosition(-30, -30);
    hoe1->setFillColor(sf::Color::Red);
  }
  // If Used
  int use_hoe() { return 1; }
  // Draw Hoe
  void draw(sf::RenderWindow* win) { win->draw(*hoe1); }

  // Deconstructor
  ~hoe() {}
};

#endif
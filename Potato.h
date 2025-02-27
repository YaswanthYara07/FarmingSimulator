// Potato Plant Functionality, and Display

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Farm.h"
#include "Plant.h"

#ifndef POTATO_H
#define POTATO_H
// Plant is called as it contains timer
class Potato : public Plant {
 protected:
  // Body of Potato
  CircleShape *pot_body_1;
  // Boolean to send to main if fully grown
  bool fully_grown;

 public:
  // Constructor of Potato Size, position, Color
  Potato() {
    fully_grown = false;

    Color brown(183, 146, 104);

    radius = 5;

    x = -10;
    y = -10;

    pot_body_1 = new CircleShape();
    pot_body_1->setRadius(radius);
    pot_body_1->setPosition(x, y);
    pot_body_1->setFillColor(brown);
    pot_body_1->setOrigin(radius / 2, radius / 2);
  }
  // Draw Potato
  void draw(RenderWindow *win) { win->draw(*pot_body_1); };

  // Find and return Radius of Potato
  int getRadius() { return radius; };

  // Growth Stage 1
  void watered1() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 25) {
      counter++;
      cout << counter << endl;
    }

    if (counter == 24) {
      pot_body_1->setRadius(10);
    }
  }

  // Growth Stage 2
  void watered2() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 51 && counter > 24) {
      counter++;
      cout << counter << endl;
    }

    if (counter >= 50) {
      pot_body_1->setRadius(20);
      pot_body_1->setOutlineColor(Color::White);
      pot_body_1->setOutlineThickness(10);
      fully_grown = true;
    }
  }

  void print() {
    if (counter >= 50) {
      std::cout << "Potato is fully grown" << std::endl;
    }
  }

  // Return if the plant is fully grown or not for harvet
  bool is_grown() { return fully_grown; }
  // Move Potato
  void move(int x_pos, int y_pos) { pot_body_1->setPosition(x_pos, y_pos); }

  // Harvest Potato
  void harvest() {
    if (Keyboard::isKeyPressed(Keyboard::L)) {
      pot_body_1->setPosition(-100, -100);
      pot_body_1->setRadius(5);
      pot_body_1->setOutlineThickness(1);
    }
  }

  // Deconstructor Potato
  ~Potato(){};
};

#endif
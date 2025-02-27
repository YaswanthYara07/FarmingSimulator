// Rose Functionality and Display
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Farm.h"
#include "Plant.h"
#ifndef ROSE_H
#define ROSE_H
// Plant is called as it contains timer
class Rose : public Plant {
 private:
 public:
  // Rose Shape
  CircleShape *R_body_1;
  // Boolean to send to main if fully grown
  bool fully_grown;
  // Constructor of Rose Size, position, Color
  Rose() {
    radius = 5;
    fully_grown = false;
    x = -10;
    y = -10;
    R_body_1 = new CircleShape();
    R_body_1->setRadius(radius);
    R_body_1->setPosition(x, x);
    R_body_1->setFillColor(Color::Blue);
  }
  // Move Rose
  void r_1_move() { R_body_1->setPosition(10, 10); }
  // Draw Rose
  void draw(RenderWindow *win) { win->draw(*R_body_1); };
  // Radius of Rose
  int getRadius() { return radius; };

  // Move Rose
  void move(int x_pos, int y_pos) { R_body_1->setPosition(x_pos, y_pos); }
  // Stage 1 of Rose Growth
  void watered1() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 41) {
      counter++;
      cout << counter << endl;
    }

    if (counter == 40) {
      R_body_1->setRadius(10);
      
    }
  }
  // Stage 2 of Rose Growth
  void watered2() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 81 && counter > 40) {
      counter++;
      cout << counter << endl;
    }

    if (counter >= 80) {
      R_body_1->setRadius(20);
      R_body_1->setOutlineColor(Color::White);
      R_body_1->setOutlineThickness(10);
      fully_grown = true;
    }
  }

  void print() {
    if (counter >= 80) {
      std::cout << "Rose is fully grown" << std::endl;
    }
  }
  // Returns if the rose is fully grown
  bool is_grown() { return fully_grown; }
  // Harvest Rose
  void harvest() {
    if (Keyboard::isKeyPressed(Keyboard::L)) {
      R_body_1->setPosition(-100, -100);
      R_body_1->setRadius(5);
      R_body_1->setOutlineThickness(0);
    }
  }
};

#endif
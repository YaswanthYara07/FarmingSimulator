//Apple Functionality and Display

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Farm.h"
#include "Plant.h"
#ifndef APPLE_H
#define APPLE_H
// Plant is called as it contains timer
class Apple : public Plant {
 protected:
  sf::CircleShape *apple_body_1;
  // Boolean to send to main if fully grown
  bool fully_grown;

 public:
  // Constructor of Apple Size, position, Color
  Apple() {
    radius = 5;
    fully_grown = false;

    x = -10;
    y = -10;

    apple_body_1 = new CircleShape();
    apple_body_1->setRadius(radius);
    apple_body_1->setPosition(x, y);
    apple_body_1->setFillColor(Color::Green);
    apple_body_1->setOrigin(radius / 2, radius / 2);
  }

 
  // Draw Apple
  void draw(RenderWindow *win) { win->draw(*apple_body_1); };
  // Move Apple
  void move(int x_pos, int y_pos) { apple_body_1->setPosition(x_pos, y_pos); }
  // Radius of Apple
  int getRadius() { return radius; };
  // Growth Stage 1
  void watered1() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 61) {
      counter++;
      cout << counter << endl;

      if (counter >= 60) {
        apple_body_1->setRadius(10);
      }
    }
  }
  // Growth Stage 2
  void watered2() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter <= 121 && counter >= 60) {
      counter++;
      cout << counter << endl;
    }
    if (counter >= 120) {
      apple_body_1->setRadius(20);
      apple_body_1->setOutlineColor(Color::White);
      apple_body_1->setOutlineThickness(10);
      fully_grown = true;
    }
  }
  void print(){
      if (counter>=120){
        std::cout<<"Apple is fully grown"<<std::endl;
      }
    }
  // Return if the Apple is fully grown
  bool is_grown() { return fully_grown; }
  // Harvest Apple
  void harvest() {
    if (Keyboard::isKeyPressed(Keyboard::L)) {
      apple_body_1->setPosition(-100, -100);
      apple_body_1->setRadius(5);
      apple_body_1->setOutlineThickness(0);
    }
  }
  // Deconstrucor
  ~Apple(){};
};

#endif
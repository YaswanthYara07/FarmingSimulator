//Rice Plant Funcionality and Diplay

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Farm.h"
#include "Plant.h"
#ifndef RICE_H
#define RICE_H
// Plant is called as it contains timer
class Rice : public Plant {
 protected:
  CircleShape *rice_body_1;
  CircleShape *rice_body_2;
  CircleShape *rice_body_3;
  CircleShape *rice_body_4;
  CircleShape *rice_body_5;
  // Boolean to send to main if fully grown
  bool fully_grown;

 public:
  // Constructor of Rice Size, position, Color
  Rice() {
    radius = 5;
    fully_grown = false;

    x = -10;
    y = -10;

    rice_body_1 = new CircleShape();
    rice_body_1->setRadius(radius);
    rice_body_1->setPosition(x, y);
    rice_body_1->setFillColor(Color::Magenta);
  }
  // Draw Rice
  void draw(RenderWindow *win) { win->draw(*rice_body_1); };
  // Radius of rice
  int getRadius() { return radius; };
  // Move Rice
  void move(int x_pos, int y_pos) { rice_body_1->setPosition(x_pos, y_pos); }
  // Stage 1 of rice
  void watered1() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 13) {
      counter++;
      cout << counter << endl;
    }

    if (counter == 12) {
      rice_body_1->setRadius(10);
    }
  }
  // Stage 2 of rice
  void watered2() {
    if ((Keyboard::isKeyPressed(Keyboard::D) ||
         Keyboard::isKeyPressed(Keyboard::A) ||
         Keyboard::isKeyPressed(Keyboard::S) ||
         Keyboard::isKeyPressed(Keyboard::W)) &&
        counter < 41 && counter > 12) {
      counter++;
      cout << counter << endl;
    }

    if (counter >= 40) {
      rice_body_1->setRadius(20);
      rice_body_1->setOutlineColor(Color::White);
      rice_body_1->setOutlineThickness(10);
      fully_grown = true;
    }
  }

  void print(){
      if (counter>=40){
        std::cout<<"Rice is fully grown"<<std::endl;
      }
    }
  // Return if the rice is fully grown
  bool is_grown() { return fully_grown; }
  // Harvest Rice
  void harvest() {
    if (Keyboard::isKeyPressed(Keyboard::L)) {
      rice_body_1->setPosition(-100, -100);
      rice_body_1->setRadius(5);
      rice_body_1->setOutlineThickness(0);
    }
  }
};

#endif
// Runs timer and other elements for all the other plants(Potato,Rice,Apple and

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Farm.h"
#ifndef PLANT_H
#define PLANT_H

using namespace std;
using namespace sf;
// Plant Class- Runs timer, Movement and Stages of all plants
class Plant {
 protected:
  // Amount of seconds it takes for a plant to go from one stage to the next.
  CircleShape *body;

  int radius;
  int x;
  int y;

 public:
  // Plant Counter Variable
  int counter = 0;
  // Move Plant
  void move(int x, int y) { body->setPosition(x, y); }
  // Plant Stages
  virtual void watered1() = 0;
  virtual void watered2() = 0;

  // Polymorphism-plant is grown test
  virtual void print() { std::cout << "plant is full grown" << std::endl; }
};

#endif

//Watering Can Functionality

#include "Apple.h"
#include "Rice.h"
#include "Rose.h"
#include "potato.h"
class wateringCan {
  // Watering Can Constructor, creating the object to be displayed in the Main
  wateringCan() {
    body1 = new sf::CircleShape();
    body1->setRadius(10);
    body1->setPosition(25, 25);
    body1->setFillColor(sf::Color::Blue);
    body1->setOrigin(10 / 4, 10 / 4);
  }
  // Draw Watering Can
  draw_can(sf::RenderWindow* win) {draw(*body1); }
  // If Watering Can is used
  int run_w_wateringCan() { return 1; }
  int run_s_wateringCan() {
    counter = counter + 10;
    std::cout<<counter;
    return 2;
  }
  // Watering Can Functionality
  int run_r_wateringCan() {
    std::cout<<"watering can run" << std::endl
    counter = counter + 20;
    std::cout<<counter;
    return 3;
  }
}
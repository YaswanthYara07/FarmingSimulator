// This is the player class that has controls Inventory, Money, Store, Displays
// the characters and each of the items and controls cerain parts of plants.

#include <SFML/Graphics.hpp>
#include <iostream>

// Farm and Plant Classes
#include "Apple.h"
#include "Farm.h"
#include "Plant.h"
#include "Potato.h"
#include "Rice.h"
#include "Rose.h"

// Functionality Classes
#include "inventory.h"
#include "money.h"
#include "store.h"

class Player : public store,
               public Rose,
               public Potato,
               public Rice,
               public Apple {
 private:
  // Farmer Body
  sf::CircleShape* body;
  // Tool Body
  sf::CircleShape* tool;
  // Seed Body
  sf::CircleShape* seed;
  sf::CircleShape* rose_seed;

 public:
  // Constructor
  Player(){

  }
  Player(int radius, int x, int y, int a_num_plant) {
    // Main Body
    body = new sf::CircleShape();
    body->setRadius(radius);
    body->setPosition(x, y);
    body->setFillColor(sf::Color::Red);
    body->setOrigin(radius / 2, radius / 2);
    body->setOutlineColor(Color::Black);
    body->setOutlineThickness(3);

    // Tools Circle
    tool = new sf::CircleShape();
    tool->setRadius(radius / 3);
    tool->setPosition(x, y);
    tool->setFillColor(sf::Color::Blue);
    tool->setOrigin(radius / 2 - 12, radius / 2 + 3);
    tool->setOutlineColor(Color::Black);
    tool->setOutlineThickness(2);

    // Seeds Circle
    seed = new sf::CircleShape();
    seed->setRadius(radius / 3);
    seed->setPosition(x, y);
    seed->setFillColor(sf::Color::Green);
    seed->setOrigin(radius / 2 - 12, radius / 2 - 15);
    seed->setOutlineColor(Color::Black);
    seed->setOutlineThickness(2);
  }
  void p_position() { body->getPosition(); }
  // Draw Function
  void draw(sf::RenderWindow* win) {
    win->draw(*body);
    win->draw(*tool);
    win->draw(*seed);
  }

  // Movement
  void move_right(int speed) {
    body->move(speed, 0);
    tool->move(speed, 0);
    seed->move(speed, 0);
  }
  void move_left(int speed) {
    body->move(-speed, 0);
    tool->move(-speed, 0);
    seed->move(-speed, 0);
  }
  void move_up(int speed) {
    body->move(0, -speed);
    tool->move(0, -speed);
    seed->move(0, -speed);
  }
  void move_down(int speed) {
    body->move(0, speed);
    tool->move(0, speed);
    seed->move(0, speed);
  }

  // Return Amount of Money Function
  int return_money() { return money::get_money(); }

  // Selecting Inventory
  int inv_1() {
    store::buy_can();
    if (inventory::get_inv_1() == 0) {
      std::cout<<"inventory has no items";
      return 0;
    } else {
      set_c_slot(1);
      return 1;
    }
  }
  int inv_2() {
    if (inventory::get_inv_2() == 0) {
      return 0;
    } else {
      set_c_slot(2);
      return 2;
    }
  }
  int inv_3() {
    if (inventory::get_inv_3() == 0) {
      return 0;
    } else {
      set_c_slot(3);
      return 3;
    }
  }
  int inv_4() {
    if (inventory::get_inv_4() == 0) {
      return 0;
    } else {
      set_c_slot(4);
      return 4;
    }
  }
  int inv_5() { return inventory::get_inv_5(); }
  int inv_6() {
    if (inventory::get_inv_6() == 0) {
      return 0;
    } else {
      set_c_slot(6);
      return 6;
    }
  }
  int inv_7() {
    if (inventory::get_inv_7() == 0) {
      set_c_slot(7);
      return 0;
    } else {
      set_c_slot(7);
      return 7;
    }
  }
  int inv_8() {
    if (inventory::get_inv_8() == 0) {
      return 0;
    } else {
      set_c_slot(8);
      return 8;
    }
  }

  // Store Access/Run Store Class
  void store_a() { store::run_store(500, "Store"); }

  ~Player() {}
};

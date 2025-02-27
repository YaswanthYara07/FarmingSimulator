// This is our Main Game File, that access all the classes, run all the code and
// controls when classes are called
#include <string.h>

#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
// Equipment Classes

#include "hoe.h"
// Farm Class
#include "Farm.h"
// Plants Class
#include "Apple.h"
#include "Plant.h"
#include "Potato.h"
#include "Rose.h"
// Player Class
#include "Playertest.h"

// Main Game Class
using namespace sf;
class OOPGame : public money {
 private:
  // Main Window
  sf::RenderWindow* win;
  // Player Class
  Player* player;
  // Sorting between
  bool set;

  // tools
  hoe* hoe1;

  // Plant objects
  Potato* potato1;
  Potato* potato2;
  Potato* potato3;
  Potato* potato4;
  Potato* potato5;

  Rice* rice1;
  Rice* rice2;
  Rice* rice3;
  Rice* rice4;
  Rice* rice5;

  Rose* rose1;
  Rose* rose2;
  Rose* rose3;
  Rose* rose4;
  Rose* rose5;

  Apple* apple1;

  Apple* apple2;
  Apple* apple3;
  Apple* apple4;
  Apple* apple5;

  // Farm Display
  Farm* farm1;
  Farm* farm2;
  Farm* farm3;
  Farm* farm4;
  Farm* farm5;

  // If Plot is used
  bool plot_1_usage;
  bool plot_2_usage;
  bool plot_3_usage;
  bool plot_4_usage;
  bool plot_5_usage;

  // Stage 1 Plants grown
  bool pot_1;
  bool pot_2;
  bool pot_3;
  bool pot_4;
  bool pot_5;

  bool ros_1;
  bool ros_2;
  bool ros_3;
  bool ros_4;
  bool ros_5;

  bool ric_1;
  bool ric_2;
  bool ric_3;
  bool ric_4;
  bool ric_5;

  bool app_1;
  bool app_2;
  bool app_3;
  bool app_4;
  bool app_5;

  // Stage 2 Plants grown
  bool pot_grow_1;
  bool pot_grow_2;
  bool pot_grow_3;
  bool pot_grow_4;
  bool pot_grow_5;

  bool ros_grow_1;
  bool ros_grow_2;
  bool ros_grow_3;
  bool ros_grow_4;
  bool ros_grow_5;

  bool ric_grow_1;
  bool ric_grow_2;
  bool ric_grow_3;
  bool ric_grow_4;
  bool ric_grow_5;

  bool app_grow_1;
  bool app_grow_2;
  bool app_grow_3;
  bool app_grow_4;
  bool app_grow_5;

 public:
  // Constructor
  OOPGame(int size, std::string title) {
    // creation of objects within constructor
    win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    // Player Object
    player = new Player(10, 50, 50, 10);
    // Plant Object Creation
    potato1 = new Potato;
    potato2 = new Potato;  // 2nd
    potato3 = new Potato;
    potato4 = new Potato;
    potato5 = new Potato;

    rice1 = new Rice;
    rice2 = new Rice;
    rice3 = new Rice;
    rice4 = new Rice;
    rice5 = new Rice;

    rose1 = new Rose;
    rose2 = new Rose;
    rose3 = new Rose;
    rose4 = new Rose;
    rose5 = new Rose;

    apple1 = new Apple;
    apple2 = new Apple;
    apple3 = new Apple;
    apple4 = new Apple;
    apple5 = new Apple;

    farm1 = new Farm(75, 300, 200);
    farm2 = new Farm(75, 135, 200);
    farm3 = new Farm(75, 212, 350);
    farm4 = new Farm(75, 50, 350);
    farm5 = new Farm(75, 375, 350);

    // Hoe Creation
    hoe1 = new hoe;

    // Bool Access
    set = false;

    // Bool Constructors for plant growth
    plot_1_usage = false;
    plot_2_usage = false;
    plot_3_usage = false;
    plot_4_usage = false;
    plot_5_usage = false;

    pot_1 = false;
    pot_2 = false;
    pot_3 = false;
    pot_4 = false;
    pot_5 = false;

    ros_1 = false;
    ros_2 = false;
    ros_3 = false;
    ros_4 = false;
    ros_5 = false;

    ric_1 = false;
    ric_2 = false;
    ric_3 = false;
    ric_4 = false;
    ric_5 = false;

    app_1 = false;
    app_2 = false;
    app_3 = false;
    app_4 = false;
    app_5 = false;

    pot_grow_1 = false;
    pot_grow_2 = false;
    pot_grow_3 = false;
    pot_grow_4 = false;
    pot_grow_5 = false;

    ros_grow_1 = false;
    ros_grow_2 = false;
    ros_grow_3 = false;
    ros_grow_4 = false;
    ros_grow_5 = false;

    ric_grow_1 = false;
    ric_grow_2 = false;
    ric_grow_3 = false;
    ric_grow_4 = false;
    ric_grow_5 = false;

    app_grow_1 = false;
    app_grow_2 = false;
    app_grow_3 = false;
    app_grow_4 = false;
    app_grow_5 = false;
  }

  void run() {
    // Loading Fonts
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
      std::cout << "Error" << std::endl;
      system("pause");
    }
    // Setting Text
    sf::Text text;
    sf::Text inv_text;

    text.setFont(font);
    inv_text.setFont(font);
    // Welcome Text
    text.setString("Welcome to our Game");
    inv_text.setString(
        "\t\t\t\t\t\t\t\t\t\t\t\t\t1.Can\n\t\t\t\t\t\t\t\t\t\t\t\t\t2."
        "Hoe\n\t\t\t\t\t\t\t\t\t\t\t\t  3.Rose\n\t\t\t\t\t\t\t\t\t\t\t\t "
        "4.Apple\n\t\t\t\t\t\t\t\t\t\t\t\t5."
        "Potato\n\t\t\t\t\t\t\t\t\t\t\t\t\t6.Rice");

    // Main Window Start
    while (win->isOpen()) {
      Event e;
      Event checker;
      while (win->pollEvent(e) && win->pollEvent(checker)) {
        // Close Window when "P" is clicked
        if ((e.type == Event::Closed && checker.type == Event::Closed) ||
            sf::Keyboard::isKeyPressed(Keyboard::P)) {
          win->close();
        }

        // Movement Keys by accessing Player Class
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          player->move_left(6);
          std::cout << "left";
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          player->move_right(6);
          std::cout << "Right";
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          player->move_up(6);
          std::cout << "Up";
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          player->move_down(6);
          std::cout << "down";
        }
        // Inventory Access
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
          if (player->get_inv_1() == 0) {
            text.setString("No Can's Bought");
          } else {
            text.setString("Can Selected");
            player->set_c_slot(1);
          }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
          if (player->get_inv_2() == 0) {
            text.setString("No Hoe's Bought");
          } else {
            text.setString("Hoe Selected");
            player->set_c_slot(2);
          }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
          if (player->get_inv_5() == 0) {
            text.setString("No Potato's Bought");
          } else {
            text.setString("Potato Selected");
            player->set_c_slot(5);
          }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
          if (player->get_inv_6() == 0) {
            text.setString("No Rose's Bought");
          } else {
            text.setString("Rose Selected");
            player->set_c_slot(6);
          }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
          if (player->get_inv_7() == 0) {
            text.setString("No Rice's Bought");
          } else {
            text.setString("Rice Selected");
            player->set_c_slot(7);
          }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
          if (player->get_inv_8() == 0) {
            text.setString("No Apple's Bought");
            // player->set_c_slot(8); Testing if works
          } else {
            text.setString("Apple Selected");
            player->set_c_slot(8);
          }

        }

        // Store Access
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
          player->store_a();
        }
        // Place Down Seed Key
        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::K))) {
          if (player->current_slot() == 1 || player->current_slot() == 2 ||
              player->current_slot() == 3 || player->current_slot() == 4) {
            text.setString("Please Select a seed");
          } else {
            // Potato Placement
            if (player->current_slot() == 5) {
              if (plot_1_usage == false) {
                pot_1 = true;
              } else {
                if (plot_2_usage == false) {
                  pot_2 = true;
                } else {
                  if (plot_3_usage == false) {
                    pot_3 = true;
                  } else {
                    if (plot_4_usage == false) {
                      pot_4 = true;
                    } else {
                      if (plot_5_usage == false) {
                        pot_5 = true;
                        std::cout << "Potato last slot";
                      } else {
                        text.setString("Land not available");
                      }
                    }
                  }
                }
              }
            }
            // Rose Placement
            if (player->current_slot() == 6) {
              if (plot_1_usage == false) {
                ros_1 = true;
              } else {
                if (plot_2_usage == false) {
                  ros_2 = true;
                } else {
                  if (plot_3_usage == false) {
                    ros_3 = true;
                  } else {
                    if (plot_4_usage == false) {
                      ros_4 = true;
                    } else {
                      if (plot_5_usage == false) {
                        ros_5 = true;
                        std::cout << "rose last slot";
                      } else {
                        text.setString("Land not available");
                      }
                    }
                  }
                }
              }
            }
            // Rice Placement
            if (player->current_slot() == 7) {
              if (plot_1_usage == false) {
                ric_1 = true;
              } else {
                if (plot_2_usage == false) {
                  ric_2 = true;
                } else {
                  if (plot_3_usage == false) {
                    ric_3 = true;
                  } else {
                    if (plot_4_usage == false) {
                      ric_4 = true;
                    } else {
                      if (plot_5_usage == false) {
                        ric_5 = true;
                        std::cout << "rice last slot";
                      } else {
                        text.setString("Land not available");
                      }
                    }
                  }
                }
              }
            }
            // Apple Placement
            if (player->current_slot() == 8) {
              if (plot_1_usage == false) {
                app_1 = true;
              } else {
                if (plot_2_usage == false) {
                  app_2 = true;
                } else {
                  if (plot_3_usage == false) {
                    app_3 = true;
                  } else {
                    if (plot_4_usage == false) {
                      app_4 = true;
                    } else {
                      if (plot_5_usage == false) {
                        app_5 = true;
                        std::cout << "apple last slot";
                      } else {
                        text.setString("Land not available");
                      }
                    }
                  }
                }
              }
            }
          }

        }
        // Use Item
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
          // If Fruit is selected
          if (player->current_slot() == 4 || player->current_slot() == 5 ||
              player->current_slot() == 6 || player->current_slot() == 7 ||
              player->current_slot() == 8) {
            text.setString("Please Select a tool");
            std::cout << "plant incorrectly chosen";
          } else {
            // Run Growth stage 1 if Watercan is selected
            if (player->current_slot() == 1) {
              if (pot_1 == true) {
                pot_grow_1 = true;
              }
              if (pot_2 == true) {
                pot_grow_2 = true;
              }
              if (pot_3 == true) {
                pot_grow_3 = true;
              }
              if (pot_4 == true) {
                pot_grow_4 = true;
              }
              if (pot_5 == true) {
                pot_grow_5 = true;
              }

              if (ros_1 == true) {
                ros_grow_1 = true;
              }
              if (ros_2 == true) {
                ros_grow_2 = true;
              }
              if (ros_3 == true) {
                ros_grow_3 = true;
              }
              if (ros_4 == true) {
                ros_grow_4 = true;
              }
              if (ros_5 == true) {
                ros_grow_5 = true;
              }

              if (ric_1 == true) {
                ric_grow_1 = true;
              }
              if (ric_2 == true) {
                ric_grow_2 = true;
              }
              if (ric_3 == true) {
                ric_grow_3 = true;
              }
              if (ric_4 == true) {
                ric_grow_4 = true;
              }
              if (ric_5 == true) {
                ric_grow_5 = true;
              }
              if (app_1 == true) {
                app_grow_1 = true;
              }
              if (app_2 == true) {
                app_grow_1 = true;
              }
              if (app_3 == true) {
                app_grow_2 = true;
              }
              if (app_4 == true) {
                app_grow_4 = true;
              }
              if (app_5 == true) {
                app_grow_5 = true;
              }
            }
            // Harvest if Hoe Selected
            // Remove Money set to 5 for testing purposes
            if (player->current_slot() == 2) {
              if (potato1->is_grown() == true) {
                std::cout << "potato harvest";
                potato1->print();
                pot_1 = false;
                plot_1_usage = false;
                potato1->harvest();
                player->add_money(5);
                text.setString("+$5");
              }
              if (potato2->is_grown() == true) {
                potato2->print();
                pot_2 = false;
                plot_2_usage = false;
                potato2->harvest();
                player->add_money(5);
                text.setString("+$5");
              }
              if (potato3->is_grown() == true) {
                potato3->print();
                pot_3 = false;
                plot_3_usage = false;
                potato3->harvest();
                player->add_money(5);
                text.setString("+$5");
              }
              if (potato4->is_grown() == true) {
                potato4->print();
                pot_4 = false;
                plot_4_usage = false;
                potato4->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (potato5->is_grown() == true) {
                potato5->print();
                pot_5 = false;
                plot_5_usage = false;
                potato5->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rose1->is_grown() == true) {
                rose1->print();
                ros_1 = false;
                plot_1_usage = false;
                rose1->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rose2->is_grown() == true) {
                rose2->print();
                ros_2 = false;
                plot_2_usage = false;
                rose2->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rose3->is_grown() == true) {
                std::cout << "rose harvest slot 3";
                rose3->print();
                ros_3 = false;
                plot_3_usage = false;
                rose3->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rose4->is_grown() == true) {
                rose4->print();
                ros_4 = false;
                plot_4_usage = false;
                rose4->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rose5->is_grown() == true) {
                rose5->print();
                ros_5 = false;
                plot_5_usage = false;
                rose5->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rice1->is_grown() == true) {
                rice1->print();
                ric_1 = false;
                plot_1_usage = false;
                rice1->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rice2->is_grown() == true) {
                rice2->print();
                ric_2 = false;
                plot_2_usage = false;
                rice2->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rice3->is_grown() == true) {
                rice3->print();
                ric_3 = false;
                plot_3_usage = false;
                rice3->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rice4->is_grown() == true) {
                std::cout << "rice harvest slot 4";
                rice4->print();
                ric_4 = false;
                plot_4_usage = false;
                rice4->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (rice5->is_grown() == true) {
                rice5->print();
                ric_5 = false;
                plot_5_usage = false;
                rice5->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (apple1->is_grown() == true) {
                apple1->print();
                app_1 = false;
                plot_1_usage = false;
                apple1->harvest();
                player->add_money(5);
                text.setString("+$5");
              }
              if (apple2->is_grown() == true) {
                apple2->print();
                app_2 = false;
                plot_2_usage = false;
                apple2->harvest();
                player->add_money(5);
                text.setString("+$5");
              }
              if (apple3->is_grown() == true) {
                apple3->print();
                app_3 = false;
                plot_3_usage = false;
                apple3->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (apple4->is_grown() == true) {
                apple4->print();
                app_4 = false;
                plot_4_usage = false;
                apple4->harvest();
                player->add_money(5);
                text.setString("+$5");
              }

              if (apple5->is_grown() == true) {
                apple5->print();
                app_5 = false;
                plot_5_usage = false;
                apple5->harvest();
                player->add_money(5);
                text.setString("+$5");
              } else {
                text.setString("No seeds fully grown");
              }
            }
          }
        }
        // gets plant to second stage
        if (pot_grow_2 == true) {
        std:
          cout << "potato 2 stage 2 growth";
          potato2->watered2();
        }
        if (pot_grow_1 == true) {
          potato1->watered2();
        }
        if (pot_grow_3 == true) {
          potato3->watered2();
        }
        if (pot_grow_4 == true) {
          potato4->watered2();
        }
        if (pot_grow_5 == true) {
          potato5->watered2();
        }
        if (ros_grow_1 == true) {
          rose1->watered2();
        }
        if (ros_grow_2 == true) {
          rose2->watered2();
        }
        if (ros_grow_3 == true) {
          rose3->watered2();
        }
        if (ros_grow_4 == true) {
          rose4->watered2();
        }
        if (ros_grow_5 == true) {
          rose5->watered2();
        }
        if (ric_grow_1 == true) {
          rice1->watered2();
        }
        if (ric_grow_2 == true) {
          rice2->watered2();
        }
        if (ric_grow_3 == true) {
          rice3->watered2();
        }
        if (ric_grow_4 == true) {
          rice4->watered2();
        }
        if (ric_grow_5 == true) {
          rice5->watered2();
        }
        if (app_grow_1 == true) {
          apple1->watered2();
        }
        if (app_grow_2 == true) {
          apple2->watered2();
        }
        if (app_grow_3 == true) {
          apple3->watered2();
        }
        if (app_grow_4 == true) {
          apple4->watered2();
        }
        if (app_grow_5 == true) {
          apple5->watered2();
        }

        // First Stage of Growth
        if (pot_1 == true && hoe1->use_hoe() == 1) {
          std::cout << "stage 1 potato 1 growth";
          potato1->move(170, 235);
          potato1->watered1();
          // potato1->watered2(); This was set originally to test if both stages
          // worked at once
          plot_1_usage = true;
        }
        if (pot_2 == true) {
          potato2->move(335, 235);
          potato2->watered1();
          plot_2_usage = true;
        }

        if (pot_3 == true) {
          potato3->move(83, 385);
          potato3->watered1();
          plot_3_usage = true;
        }

        if (pot_4 == true) {
          potato4->move(247, 385);
          potato4->watered1();
          plot_4_usage = true;
        }

        if (pot_5 == true) {
          potato5->move(410, 385);
          potato5->watered1();
          plot_5_usage = true;
        }

        if (ros_1 == true) {
          rose1->move(170, 235);
          rose1->watered1();
          plot_1_usage = true;
        }

        if (ros_2 == true) {
          rose2->move(335, 235);
          rose2->watered1();
          plot_2_usage = true;
        }

        if (ros_3 == true) {
          rose3->move(83, 385);
          rose3->watered1();
          plot_3_usage = true;
        }

        if (ros_4 == true) {
          rose4->move(247, 385);
          rose4->watered1();
          plot_4_usage = true;
        }

        if (ros_5 == true) {
          rose5->move(410, 385);
          rose5->watered1();
          plot_5_usage = true;
        }

        if (ric_1 == true) {
          rice1->move(170, 235);
          rice1->watered1();
          plot_1_usage = true;
        }

        if (ric_2 == true) {
          rice2->move(335, 235);
          rice2->watered1();
          plot_2_usage = true;
        }

        if (ric_3 == true) {
          rice3->move(83, 385);
          rice3->watered1();
          plot_3_usage = true;
        }

        if (ric_4 == true) {
          rice4->move(247, 385);
          rice4->watered1();
          plot_4_usage = true;
        }
        if (ric_5 == true) {
          rice5->move(410, 385);
          rice5->watered1();
          plot_5_usage = true;
        }
        if (app_1 == true) {
          apple1->move(170, 235);
          apple1->watered1();
          plot_1_usage = true;
        }
        if (app_2 == true) {
          apple2->move(335, 235);
          apple2->watered1();
          plot_2_usage = true;
        }
        if (app_3 == true) {
          apple3->move(83, 385);
          apple3->watered1();
          plot_3_usage = true;
        }
        if (app_4 == true) {
          apple4->move(247, 385);
          apple4->watered1();
          plot_4_usage = true;
        }
        if (app_5 == true) {
          apple5->move(410, 385);
          apple5->watered1();
          plot_5_usage = true;
        }
      }
      // Clear Current Window
      win->clear();
      // Draw Player
      player->draw(win);
      // Set Background Color
      win->clear(sf::Color(0, 154, 23));

      // draw farm and plots
      farm1->draw(win);
      farm2->draw(win);
      farm3->draw(win);
      farm4->draw(win);
      farm5->draw(win);

      // Save Game stats
      std::ofstream myfile;
      std::string line;
      // Save File Name
      myfile.open("Save.txt");
      // Saving Content
      myfile << "Final Money:" << player->get_money() << "\n";
      myfile << "Potatos bought:" << player->get_inv_5() << "\n";
      myfile << "Roses bought:" << player->get_inv_6() << "\n";
      myfile << "Rice bought:" << player->get_inv_7() << "\n";
      myfile << "Apples bought:" << player->get_inv_8() << "\n";
      myfile << "Upgrades to Hoe:" << player->get_inv_2() << "\n";
      myfile << "Upgrades to Watering Can:" << player->get_inv_1() - 2 << "\n";

      myfile.close();

      // draw tools
      hoe1->draw(win);
      // create plants
      rice1->draw(win);
      rice2->draw(win);
      rice3->draw(win);
      rice4->draw(win);
      rice5->draw(win);

      rose1->draw(win);
      rose2->draw(win);
      rose3->draw(win);
      rose4->draw(win);
      rose5->draw(win);

      apple1->draw(win);

      apple2->draw(win);
      apple3->draw(win);
      apple4->draw(win);
      apple5->draw(win);

      potato1->draw(win);
      potato2->draw(win);
      potato3->draw(win);
      potato4->draw(win);
      potato5->draw(win);
      player->draw(win);

      // Draw Text
      win->draw(text);
      win->draw(inv_text);
      // Display all drawn
      win->display();
    }
  }
  ~OOPGame() {
    // deleting all dynamically allocated variables
    delete potato1;
    delete potato2;
    delete potato3;
    delete potato4;
    delete potato5;

    delete rice1;
    delete rice2;
    delete rice3;
    delete rice4;
    delete rice5;

    delete rose1;
    delete rose2;
    delete rose3;
    delete rose4;
    delete rose5;

    delete apple1;
    delete apple2;
    delete apple3;
    delete apple4;
    delete apple5;

    delete farm1;
    delete farm2;
    delete farm3;
    delete farm4;
    delete farm5;

    delete hoe1;
  };
};

class titleScreen {
 protected:
  sf::RenderWindow* title_win;

 public:
  titleScreen() {}
  void run_title(int size, string title) {
    title_win = new sf::RenderWindow(sf::VideoMode(size, size), title);
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
      std::cout << "Error" << std::endl;
      system("pause");
    }
    sf::Text title_text;
    title_text.setFont(font);
    title_text.setString(
        "Hi,\nWelcome to our Farming Simulator.\nThe Basic Controls "
        "are:\n\t-W,A,S,D to move\n\t-1-6 to select items\n\t-K to plant a "
        "seed\n\t-L to use and item\n\t-P to close main window\n\t-N to close "
        "Shop window.\n\nStart the game by buying a can,hoe and rice as\nthese "
        "are the cheapest.You can then select a plant and\nplace it down using "
        "K.Then you walk around the map to\ngrow the plant. After it reaches "
        "stage 1, you can use\nthe watering can to grow it to stage 2. After "
        "that you can\nuse the hoe to grow harvest the plant in return for "
        "money.\n There is no finish to this game, play till your happy "
        "and\nattempt to earn the most money!");

    while (title_win->isOpen()) {
      sf::Event t;
      while (title_win->pollEvent(t)) {
        if (t.type == sf::Event::Closed) {
          title_win->close();
        }
      }
      title_win->clear();
      title_win->draw(title_text);
      title_win->display();
    }
  }
};
int main() {
  titleScreen t;
  t.run_title(800, "Farming Simulator");
  OOPGame g(500, "OOP Game");
  g.run();

  std::string line;
  std::ifstream myfile("Save.txt");
  std::cout << endl;
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      cout << line << '\n';
    }
    myfile.close();
  }

  //___

  return 0;
}
// This Class Controls Displaying and running store.

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "inventory.h"
#include "money.h"
class store : public money, public inventory {
 protected:
  // Number of an item is bought
  int num_can_bought;
  int num_hoe_bought;
  int num_fertiliser_bought;
  int num_nets_bought;
  int num_potato_bought;
  int num_rose_bought;
  int num_rice_bought;
  int num_apple_bought;
  // Shop Window Display
  sf::RenderWindow* store_win;
  // Error message Display
  sf::Text err_msg;
  // If an item is clciked once condition
  sf::Event event;

 public:
  // Constructor setting number of items bought to 0, and constructing error
  // message
  store() {
    int num_can_bought = 0;
    int num_hoe_bought = 0;
    int num_fertiliser_bought = 0;
    int num_nets_bought = 0;
    int num_potato_bought = 0;
    int num_rose_bought = 0;
    int num_rice_bought = 0;
    int num_apple_bought = 0;
    sf::Text err_msg;
  }

  // Store Run
  void run_store(int size, std::string title) {
    // Display Window
    store_win = new sf::RenderWindow(sf::VideoMode(size, size), title);

    // run the program as long as the window is open
    sf::Font font;
    if (!font.loadFromFile("font.ttf")) {
      std::cout << "Error" << std::endl;
      system("pause");
    }
    sf::Text text;
    text.setFont(font);
    text.setString(
        "\t\t\t\t\t\tShop\n 1. Watering Can\t\t\t\t\t\t\t$5\n "
        "2. Hoe\t\t\t\t\t\t\t\t\t\t\t$5\n"
        " 3. Rose\t\t\t\t\t\t\t\t\t\t  $5\n 4. Apple\t\t\t\t\t\t\t\t\t\t $5\n "
        "5. Potato\t\t\t\t\t\t\t\t\t   $5\n 6. Rice\t\t\t\t\t\t\t\t\t\t   $5");

    err_msg.setFont(font);
    err_msg.setString("");

    while (store_win->isOpen()) {
      sf::Event e;
      sf::Event checker;  // Makes sure only one input is taken everytime(Spam
                          // Protection)
      while (store_win->pollEvent(e) && store_win->pollEvent(checker)) {
        // Close Window
        if (e.type == sf::Event::Closed) {
          store_win->close();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
          store_win->close();
        }
        // Key set for Can
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
          buy_can();
          // Key set for Hoe
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
          buy_hoe();
        }
        // Key set for Rose
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
          buy_rose();
          // Key set for Apple
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
          buy_apple();
        }
        // Key set for Potato
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
          buy_potato();
        }
        // Key set for Rice
        else if (2 * (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))) {
          buy_rice();
        }
      }
      // Clear and Display all Words, Area and text
      store_win->clear();
      store_win->draw(text);
      store_win->draw(err_msg);
      store_win->display();
    }
  }

  // Buy Can function
  void buy_can() {
    std::cout << get_money();
    if (money::get_money() <= 5) {
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_can_bought >= 1) {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\tHighest Can Reached");
      } else {
        num_can_bought = num_can_bought + 1;
        inventory::set_inv_1(num_can_bought);
        money::remove_money(5);
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Can Bought");
      }
    }
  }
  // Hoe Buy Function
  void buy_hoe() {
    if (money::get_money() <= 5) {
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_hoe_bought >= 1) {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\tHighest Hoe Reached");
      } else {
        num_hoe_bought = num_hoe_bought + 1;
        inventory::set_inv_2(num_hoe_bought);
        money::remove_money(5);
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tHoe Bought");
      }
    }
  }
  // Fertiliser Buy Function
  void buy_fertiliser() {
    std::cout << get_money();
    if (money::get_money() <= 5) {
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_fertiliser_bought == 1) {
        err_msg.setString(
            "\n\n\n\n\n\n\n\n\n\nHighest Number of Fertiliser Reached");
      } else {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tFertiliser Bought");
        num_fertiliser_bought = num_fertiliser_bought + 1;
        inventory::set_inv_3(num_fertiliser_bought);
        // std::cout<<num_fertiliser_bought<<"test";
        money::remove_money(5);
        // std::cout<<get_money();
      }
    }
  }
  // Net Buy Function
  void buy_net() {
    if (money::get_money() <= 0) {
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_nets_bought == 3) {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\tHighest Net Reached");
      } else {
        num_nets_bought = num_nets_bought + 1;
        inventory::set_inv_4(num_nets_bought);
        money::remove_money(5);
      }
    }
  }
  // Potato Buy Function
  void buy_potato() {
    std::cout << get_money();
    if (get_money() < 5) {
      // output not enough money
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
      std::cout << "No";
    } else {
      if (num_potato_bought == 6) {
        err_msg.setString(
            "\n\n\n\n\n\n\n\n\n\n Highest Number of Potato Reached");
      } else {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Potato Bought");
        num_potato_bought = num_potato_bought + 1;
        // std::cout << "yes";
        inventory::set_inv_5(num_potato_bought);
        money::remove_money(5);
      }
    }
  }
  // Rose Buy function
  void buy_rose() {
    if (money::get_money() <= 5) {
      // output not enough money
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_rose_bought == 5) {
        err_msg.setString(
            "\n\n\n\n\n\n\n\n\n\n Highest Number of Rose Reached");
      } else {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Rose Bought");
        num_rose_bought = num_rose_bought + 1;
        inventory::set_inv_6(num_rose_bought);
        money::remove_money(5);
      }
    }
  }
  // Rice Buy Function
  void buy_rice() {
    if (money::get_money() <= 5) {
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
      // std::cout << "testing";
    } else {
      if (num_rice_bought == 6) {
        err_msg.setString(
            "\n\n\n\n\n\n\n\n\n\n Highest Number of Rice Reached");
      } else {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Rice Bought");
        num_rice_bought = num_rice_bought + 1;
        inventory::set_inv_7(num_rice_bought);
        money::remove_money(5);
      }
    }
  }
  // Apple Buy Function
  void buy_apple() {
    if (money::get_money() <= 0) {
      // output not enough money
      err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\tInsufficent Funds");
    } else {
      if (num_apple_bought == 6) {
        err_msg.setString(
            "\n\n\n\n\n\n\n\n\n\n Highest Number of Apple Reached");
      } else {
        err_msg.setString("\n\n\n\n\n\n\n\n\n\n\t\t\t\t Apple Bought");
        num_apple_bought = num_apple_bought + 1;
        inventory::set_inv_8(num_apple_bought);
        money::remove_money(5);
      }
    }
  }
};
//Money Functionality

#include <iostream>
#pragma once
//Money is inheritance Player->Store->Money
// Money Class
class money {
 protected:
  // Money Variable
  double mon;

 public:
  // Money Constructor
  money() {
    mon = 100;  // Set to 100 for testing purposes, normally set to 15
  }

  // Add Money
  void add_money(double amount) { mon = amount + mon; }
  // Remove Money
  void remove_money(double amount) { mon = mon - amount; }
  // Return Money
  int get_money() { return mon; }
};
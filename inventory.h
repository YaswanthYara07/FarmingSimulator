// Runs Player Inventory

#include <iostream>
#include <string>
#pragma once
//Inventory is inheritance Player->Store->Inventory
class inventory {
 protected:
  int num_w_can;
  int num_of_hoe;
  int num_fertiliser;
  int num_net;
  int num_s_can;
  int num_potato;
  int num_rose;
  int num_apple;
  int num_rice;
  int current_inv_slot;

 public:
  inventory() {
    // Number of items in inventory
    int num_w_can = 0;
    int num_w_hoe = 0;
    int num_net = 0;
    int num_s_can = 0;
    int num_s_hoe = 0;
    int num_i_hoe = 0;
    int num_fertiliser = 0;
    int num_potato = 0;
    int num_rose = 0;
    int num_apple = 0;
    int num_rice = 0;
    // Current inventory Slot Selected
    int current_inv_slot = 0;
  }

  // Watering Can Inventory
  void set_inv_1(int can_type) {
    if (can_type == 0) {
      num_w_can = 0;
      num_s_can = 0;
    }
    if (can_type == 1) {
      num_w_can = 1;
      num_s_can = 0;
    }
    if (can_type == 2) {
      num_w_can = 0;
      num_s_can = 1;
    }
    if (can_type == 3) {
      num_w_can = 0;
      num_s_can = 0;
    } else {
      num_w_can = 0;
      num_s_can = 0;
    }
    int current_inv_slot = 1;
  }

  // Return the class of Can bought.
  int get_inv_1() {
    if (num_w_can == 1 && num_s_can == 0) {
      return 1;
    }
    if (num_w_can == 0 && num_s_can == 1) {
      return 2;
    }
    if (num_w_can == 0 && num_s_can == 0) {
      return 3;
    }
    if (num_w_can == 0 && num_s_can == 0) {
      return 0;
    } else {
      return 0;
    }
  }

  // Hoe
  void set_inv_2(int hoe_num) {
    if (hoe_num >= 1) {
      num_of_hoe = 1;
    } else {
      num_of_hoe = 0;
    }
    int current_inv_slot = 2;
  }

  int get_inv_2() {
    if (num_of_hoe == 1) {
      return 1;
    } else {
      return 0;
    }
  }

  // Fertiliser
  void set_inv_3(int num_of_fertiliser) {
    if (num_of_fertiliser >= 1) {
      num_fertiliser = 1;
    } else {
      num_fertiliser = 0;
    }
    int current_inv_slot = 3;
  }
  int get_inv_3() {
    if (num_fertiliser == 1) {
      return 1;
    }
    if (num_fertiliser == 0) {
      return 0;
    } else {
      return 0;
    }
  }

  // Nets
  void set_inv_4(int num_of_nets) {
    if (num_of_nets >= 1) {
      num_net = 1;
    } else {
      num_net = 0;
    }
    int current_inv_slot = 4;
  }

  int get_inv_4() {
    if (num_net == 1) {
      return 1;
    }
    if (num_net == 0) {
      return 0;
    } else {
      return 0;
    }
  }

  // Potato
  void set_inv_5(int num_of_potato) {
    num_potato = num_potato + num_of_potato;
    int current_inv_slot = 5;
  }
  int get_inv_5() { return num_potato; }

  // Rose
  void set_inv_6(int num_of_rose) {
    num_rose = num_rose + num_of_rose;
    int current_inv_slot = 6;
  }
  int get_inv_6() { return num_rose; }

  // Rice
  void set_inv_7(int num_of_rice) {
    num_rice = num_rice + num_of_rice;
    int current_inv_slot = 7;
  }
  int get_inv_7() { return num_rice; }

  // Apple
  void set_inv_8(int num_of_apple) {
    num_apple = num_apple + num_of_apple;
    int current_inv_slot = 8;
  }
  int get_inv_8() { return num_apple; }

  void set_c_slot(int slot_num) { current_inv_slot = slot_num; }
  int current_slot() { return current_inv_slot; }
};
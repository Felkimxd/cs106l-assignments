/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include <iostream>
#include "class.h"

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Plant myPlant("Oak", "Quercus", 100, true, true);
  
  // STUDENT TODO: Call a method on your class!
  
  std::cout << "My plant is a " << myPlant.getName() << " tree." << std::endl;
  std::cout << "It has " << myPlant.getLeavesNum() << " leaves." << std::endl;
  std::cout << "It has flowers: " << myPlant.getFlowersExists() << std::endl;

  myPlant.setFlowers(false);
  std::cout << "It has flowers: " << myPlant.getFlowersExists() << std::endl;

  myPlant.treeLive();
  std::cout << "It has " << myPlant.getLeavesNum() << " leaves." << std::endl;
}


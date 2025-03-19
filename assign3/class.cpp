#include "class.h"
#include <string>
#include <iostream>

Plant::Plant(std::string name, std::string specie, int leave_num, bool flowers, bool fruits)
{
    this->name = name;
    this->specie = specie;
    this->leaveNum = leave_num;
    this->flowers = flowers;
    this->fruits = fruits;
}

std::string  const Plant::getName()
{
    return name;
}

int const Plant::getLeavesNum()
{
    return leaveNum;
} 

bool const Plant::getFlowersExists()
{
    return flowers;
}

bool const Plant::getFruitsExists()
{
    return fruits;
}

void Plant::photosyntesis(){

    std::cout << "I'm making the photosyntesis" << std::endl;
}

void Plant::fallingLeaves(){

    std::cout << "I'm losing a leave :(" << std::endl;
    this->leaveNum--;
}

void Plant::setName(std::string name)
{
    this->name = name;
}

void Plant::setSpecie(std::string specie)
{
    this->specie = specie;
}

void Plant::setNumLeaves(int leaves)
{
    this->leaveNum = leaves;
}

void Plant::setFlowers(bool flowers)
{
    this->flowers = flowers;
}

void Plant::setFruits(bool fruits)
{
    this->fruits = fruits;
}

// Copyright 2022 NNTU-CS
#include <iostream>
#include <random>
#include "train.h"

int main() {
    Train train;
    int count = 100; // кол-во вагонов
    int type = 3;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    switch (type) {
    case 1:
        while (count--)
            train.addCar(false);
        break;
    case 2:
        while (count--)
            train.addCar(true);
        break;
    case 3:
        while (count--)
            train.addCar(dist(gen));
        break;
    default:
        break;
    }

    std::cout << train.getLength() << std::endl;
    std::cout << train.getOpCount() << std::endl;
    return 0;
}

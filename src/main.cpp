// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    Train train;
    int count = 100; // кол-во вагонов
    int type = 3;
    srand((time(0)));
    switch (type)
    {
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
            train.addCar(rand()%2);
        break;
    default:
        break;
    }

    std::cout << train.getLength() << std::endl;
    std::cout << train.getOpCount() << std::endl;
    return 0;
}

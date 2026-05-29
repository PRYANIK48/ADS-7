// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car* car = new Car();
    car->light = light;
    if (first) {
        car->prev = first->prev;
        first->prev->next = car;
    } else {
        first = car;
    }
    first->prev = car;
    car->next = first;
}

int Train::getLength() {
    if (!first) {
        return 0;
    }
    bool flag = true;
    int length = 0;
    first->light = true;
    while (flag) {
        int distance = 0;

        do {
            distance++;
            countOp++;
            first = first->next;
        } while (first->light == false);

        first->light = false;
        length = distance;

        for (; distance > 0; distance--) {
            countOp++;
            first = first->prev;
        }
        if (first->light == false) {
            flag = false;
        }
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}

//
// Created by gate3 on 2019-05-18.
//

#ifndef EXERCISE_ROAD_H
#define EXERCISE_ROAD_H
#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <list>
class Order {
public:
    Order() {}
    Order(char* direction, int wheel_direction, int step) {
        strcpy(direction_, direction);
        wheel_direction_ = wheel_direction;
        step_ = step;
    }

    char* direction() { return direction_; }
    int wheel_direction() { return wheel_direction_; }
    int step() { return step_; }
    void set_direction(char* direction) { strcpy(direction_, direction); }
    void set_wheel_direction(int wheel_direction) { wheel_direction_ = wheel_direction; }
    void set_step(int step) { step_ = step; }
private:
    char direction_[128];
    int wheel_direction_;
    int step_;
};
#endif //EXERCISE_ROAD_H

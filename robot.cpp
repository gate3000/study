//
// Created by Minho Lee on 2019-05-18.
//

#include <iostream>
#include <assert.h>
#include <string.h>
#include <vector>
#include <list>

#include "potters_wheel.h"
#include "road.h"

const int CHAR_SIZE = 128;
int test_count = 0;

int main(){

    std::cout << "Robot Test Start" << std::endl;

    //Part 0: Save Input
    char input[CHAR_SIZE];
    unsigned int x_size = 0;
    unsigned int y_size = 0;
    int x_initial_position = 0;
    int y_initial_position = 0;
    int road[500][500] = {0};

    std::cin.getline(input, CHAR_SIZE, '\n');
    test_count = std::atoi(input);
    std::cout << "The Number of Test Cases : " << test_count << std::endl;

    std::cin.getline(input, CHAR_SIZE, '\n');
    x_size = std::atoi(strtok(input, " "));
    y_size = std::atoi(strtok(NULL, " "));
    x_initial_position = std::atoi(strtok(NULL, " "));
    y_initial_position = std::atoi(strtok(NULL, " "));
    assert((x_size >= 3) && (x_size <= 500));
    assert((y_size >= 3) && (y_size <= 500));
//    assert((x_initial_position >= 10) && (x_initial_position <= 500));
//    assert((y_initial_position >= 10) && (y_initial_position <= 500));
    std::cout << "Size of Road : (" << x_size << ", " << y_size << ")" << std::endl;
    std::cout << "Initial Position of Robot : (" << x_initial_position << ", " << y_initial_position << ")" <<std::endl;

    for (int i = 0; i < x_size; ++i) {
        std::cin.getline(input, CHAR_SIZE, '\n');
        road[i][0] = std::atoi(strtok(input, " "));
        for (int j = 1; j < y_size; ++j) {
            road[i][j] = std::atoi(strtok(NULL, " "));
        }
    }
    //For Debug
    for (int i = 0; i < x_size; ++i) {
        for (int j = 0; j < y_size; ++j) {
            std::cout << road[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //Make PottersWheel
    int section_count;
    std::vector<int> number_array;
    std::cin.getline(input, CHAR_SIZE, '\n');
    section_count = std::atoi(input);
    assert((section_count <= 8) && (section_count >= 1));
    std::cin.getline(input, CHAR_SIZE, '\n');
    PottersWheel potters_wheel(section_count, input);

    //Save Order
    int order_count;
    std::vector<Order*> order_array;
    std::cin.getline(input, CHAR_SIZE, '\n');
    order_count = std::atoi(input);

    for (int i = 0; i < order_count; ++i) {
        std::cin.getline(input, CHAR_SIZE, '\n');
        Order *order = new Order;
        order->set_direction(strtok(input, " "));
        order->set_wheel_direction(std::atoi(strtok(NULL, " ")));
        order->set_step(std::atoi(strtok(NULL, " ")));
        order_array.push_back(order);
    }

    //Debug
    for (int i = 0; i < order_count; ++i) {
        Order* order = order_array[i];
        std::cout << order->direction() << " " << order->wheel_direction() << " " << order->step() << std::endl;
    }

    for (auto it = order_array.begin(); it != order_array.end(); ++it) {
        Order* order = *it;
        order_array.erase(it);
        delete order;
    }
    return 0;
}
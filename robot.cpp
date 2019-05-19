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
int road[500][500] = {0};

int TakeStepsToNorth(int step_count, int* initial_x, int* initial_y, int x_size, int y_size) {
    int point = 0;
    assert((*initial_x >= 0) && (*initial_y >= 0) && (*initial_y <= y_size) && (*initial_x <= x_size));

    for (int i = 0; i < step_count; ++i) {
        if (*initial_y == y_size)
            return point;
        *initial_y += 1;
        if (road[*initial_x][*initial_y] == -1) {
            return point;
        }
        point += road[*initial_x][*initial_y];
        //road[*initial_x][*initial_y] = 0;
    }
    return point;
}

int TakeStepsToSouth(int step_count, int* initial_x, int* initial_y, int x_size, int y_size) {
    int point = 0;
    assert((*initial_x >= 0) && (*initial_y >= 0) && (*initial_y <= y_size) && (*initial_x <= x_size));

    for (int i = 0; i < step_count; ++i) {
        if (*initial_y == 0)
            return point;
        *initial_y -= 1;
        if (road[*initial_x][*initial_y] == -1) {
            return point;
        }
        point += road[*initial_x][*initial_y];
        //road[*initial_x][*initial_y] = 0;
    }
    return point;
}

int TakeStepsToEast(int step_count, int* initial_x, int* initial_y, int x_size, int y_size) {
    int point = 0;
    assert((*initial_x >= 0) && (*initial_y >= 0) && (*initial_y <= y_size) && (*initial_x <= x_size));

    for (int i = 0; i < step_count; ++i) {
        if (*initial_x == x_size)
            return point;
        *initial_x += 1;
        if (road[*initial_x][*initial_y] == -1) {
            return point;
        }
        point += road[*initial_x][*initial_y];
        //road[*initial_x][*initial_y] = 0;
    }
    return point;
}

int TakeStepsToWest(int step_count, int* initial_x, int* initial_y, int x_size, int y_size) {
    int point = 0;
    assert((*initial_x >= 0) && (*initial_y >= 0) && (*initial_y <= y_size) && (*initial_x <= x_size));

    for (int i = 0; i < step_count; ++i) {
        if (*initial_x == 0)
            return point;
        *initial_x -= 1;
        if (road[*initial_x][*initial_y] == -1) {
            return point;
        }
        point += road[*initial_x][*initial_y];
        //road[*initial_x][*initial_y] = 0;
    }
    return point;
}

int main(){

    std::cout << "Robot Test Start" << std::endl;

    //Part 0: Save Input
    char input[CHAR_SIZE];
    int round = 0;
    unsigned int x_size = 0;
    unsigned int y_size = 0;
    int x_initial_position = 0;
    int y_initial_position = 0;
    int result[10][3];

    std::cin.getline(input, CHAR_SIZE, '\n');
    test_count = std::atoi(input);
    std::cout << "The Number of Test Cases : " << test_count << std::endl;

    while (round < test_count) {
        std::cin.getline(input, CHAR_SIZE, '\n');
        y_size = std::atoi(strtok(input, " "));
        x_size = std::atoi(strtok(NULL, " "));
        x_initial_position = std::atoi(strtok(NULL, " "));
        y_initial_position = std::atoi(strtok(NULL, " "));
        assert((x_size >= 3) && (x_size <= 500));
        assert((y_size >= 3) && (y_size <= 500));

        std::cout << "Size of Road : (" << x_size << ", " << y_size << ")" << std::endl;
        std::cout << "Initial Position of Robot : (" << x_initial_position << ", " << y_initial_position << ")"
                  << std::endl;

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

        //Part 1: Make PottersWheel
        int section_count;
        std::vector<int> number_array;
        std::cin.getline(input, CHAR_SIZE, '\n');
        section_count = std::atoi(input);
        assert((section_count <= 8) && (section_count >= 1));
        std::cin.getline(input, CHAR_SIZE, '\n');
        PottersWheel potters_wheel(section_count, input);

        //Part 2: Save Order
        int order_count;
        std::vector<Order *> order_array;
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
            Order *order = order_array[i];
            std::cout << order->direction() << " " << order->wheel_direction() << " " << order->step() << std::endl;
        }

        //Part 3: Calculate
        int point = 0;
        for (int i = 0; i < order_count; ++i) {
            Order *order = order_array[i];
            int distance = potters_wheel.GetDistance(order->wheel_direction(), order->step());
            char *direction = order->direction();
            if (strcmp(direction, "E")) {
                point += TakeStepsToEast(distance, &x_initial_position, &y_initial_position, x_size, y_size);
            } else if (strcmp(direction, "W")) {
                point += TakeStepsToWest(distance, &x_initial_position, &y_initial_position, x_size, y_size);
            } else if (strcmp(direction, "S")) {
                point += TakeStepsToSouth(distance, &x_initial_position, &y_initial_position, x_size, y_size);
            } else if (strcmp(direction, "N")) {
                point += TakeStepsToNorth(distance, &x_initial_position, &y_initial_position, x_size, y_size);
            } else {
                assert("Wrong Direction!");
            }
        }

        result[round][0] = point;
        result[round][1] = x_initial_position;
        result[round][2] = y_initial_position;

        //Debug
        std::cout << round << " : " << point << " " << x_initial_position << " " << y_initial_position << std::endl;

        //Part 4: Arrange Memory
        for (auto it = order_array.begin(); it != order_array.end(); ++it) {
            Order* order = *it;
            order_array.erase(it);
            delete order;
        }
        round++;
    }

    for (int i = 0; i < test_count; ++i) {
        std::cout << "#" << i+1 << " " << result[i][0] << " " << result[i][1] << " " << result[i][2] << std::endl;
    }

    return 0;
}
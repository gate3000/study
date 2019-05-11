//
// Created by Minho Lee on 2019-05-12.
//

#include <iostream>
#include <cstring>
#include "input_to_array.h"

int HandleInput::InputToArray(std::vector<int> *point) {
    const int INPUT_SIZE = 128;
    char input[INPUT_SIZE]= {};
    int retry_count = 0;

    while (retry_count < 5) {
        bool invalid_input = false;
        std::cout << "Exercise For Converting Input String To Int Array." << std::endl;
        std::cout << "Enter the multiple numbers (eg., 1 2 3)" << std::endl;
        std::cin.getline(input, INPUT_SIZE, '\n');

        char* new_number = std::strtok(input, " ");
        while (new_number != nullptr) {
            int new_point = std::atoi(new_number);
            if (new_point < 0 || new_point > 100) {
                invalid_input = true;
                std::cout << new_point << " is not eligible for the input point." << std::endl;
                point->clear();
                break;
            }
            point->push_back(new_point);
            new_number = std::strtok(NULL, " "); //NULL을 넣으면 알아서 잘린 문자열 다음 위치를 가리키고 있다가 더이상 가리킬 곳이 없으면 nullptr 반환
        }
       if (invalid_input) {
           retry_count++;
       } else {
           break;
       }
    }
    return 0;
}

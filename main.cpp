#include <iostream>
#include <vector>
#include "input_to_array.h"
#include "array_sorting.h"

int main() {
    std::cout << "Hello, World! It is First Project of mine" << std::endl;
    std::vector<int> point;
    HandleInput::InputToArray(&point);

    if (point.size() == 0) {
        std::cout << "Exceed Retry Count!!!" << std::endl;
    } else {
        for (int i = 0; i < point.size(); ++i) {
            std::cout << point[i] << std::endl;
        }
    }

    ArraySorting::BubbleSorting(&point);

    std::cout << "Ascending Sorting Finished." << std::endl;
    for (int i = 0; i < point.size(); ++i) {
        std::cout << point[i] << std::endl;
    }
    return 0;
}


//
// Created by gate3 on 2019-05-12.
//

#ifndef EXERCISE_ARRAY_SORTING_H
#define EXERCISE_ARRAY_SORTING_H

#include <vector>

class ArraySorting {
public:
    static void BubbleSorting(std::vector<int>* point) {
        bool finish = false;
        while (finish == false) {
            finish = true;
            for (int i = 0; i < point->size() - 1; ++i) {
                if ((*point)[i] > (*point)[i+1]) {
                    finish = false;
                    int temp = (*point)[i];
                    (*point)[i] = (*point)[i + 1];
                    (*point)[i + 1] = temp;
                }
            }
        }
    }
};
#endif //EXERCISE_ARRAY_SORTING_H

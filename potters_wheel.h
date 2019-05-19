//
// Created by gate3 on 2019-05-18.
//

#ifndef EXERCISE_POTTERS_WHEEL_H
#define EXERCISE_POTTERS_WHEEL_H

#include <string.h>
#include <vector>
#include <assert.h>
class PottersWheel {
public:
    PottersWheel(int section_count, char* input) {
        section_count_ = section_count;
        numbers_.push_back(std::atoi(strtok(input, " ")));
        for (int i = 1; i < section_count_; ++i) {
            numbers_.push_back(std::atoi(strtok(NULL, " ")));
        }
    }

    std::vector<int>* numbers() { return &numbers_; }
    int section_count() { return section_count_; }

    int GetDistance(int direction, int step) {
        assert(direction == 1 || direction == 2);
        if (direction == 1) {
            int moving_count = (step % section_count_);
            last_index_ = (last_index_ + moving_count) % section_count_;
            return numbers_[last_index_];
        } else {
            int moving_count = ((section_count_ - (step % section_count_)) % section_count_);
            last_index_ = (last_index_ + moving_count) % section_count_;
            return numbers_[last_index_];
        }
    }

private:
    std::vector<int> numbers_;
    int section_count_;
    int last_index_ = 0;

};

#endif //EXERCISE_POTTERS_WHEEL_H

//
// Created by gate3 on 2019-05-20.
//
#include <iostream>
#include <string.h>
#include <assert.h>
#include <vector>

const int x_size = 6;
const int y_size = 6;
const int initial_x = 1;
const int initial_y = 1;
/*
int road[x_size+1][y_size+1] = {{0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 3, 1, 13, 7, 6},
                                {0, 17, 19, 2, 11, 1, 5},
                                {0, 5, 4, 3, 12, 2, 3},
                                {0, 6, 8, 7, 10, 7, 11},
                                {0, 10, 9, 15, 9, 3, 16},
                                {0, 11, 12, 13, 8, 17, 2}};
*/
int road[x_size+1][y_size+1] = {{0, 0, 0, 0, 0, 0, 0},
                                {0, 1, 3, 1, 13, 7, 6},
                                {0, 1, 2, 2, 11, 1, 5},
                                {0, 5, 4, 3, 12, 2, 3},
                                {0, 6, 8, 7, 10, 7, 11},
                                {0, 10, 9, 4, 9, 3, 2},
                                {0, 11, 12, 13, 8, 6, 2}};

class Result {
public:
    Result() {}
    void Clear() {
        path_number_ = 0;
        max_point_ = -1;
        path_.clear();
    }
    int path_number_;
    int max_point_;
    std::vector<int> path_;
};

void Calculate(Result* result, int cur_point, int current_x, int current_y, int max_x, int max_y, unsigned int* try_cnt, std::vector<int>* current_path) {
    assert(current_x <= max_x && current_x >= initial_x);
    assert(current_y <= max_y && current_y >= initial_y);

    if (max_x > current_x) {
        int next_place = road[current_x + 1][current_y];
        for (auto it = current_path->begin(); it != current_path->end(); ++it) {
            if (*it == next_place) {
                next_place = -1;
                break;
            }
        }
        if (next_place != -1) {
            std::vector<int> new_path = *current_path;
            new_path.push_back(next_place);
            Calculate(result, cur_point + next_place, current_x + 1, current_y, max_x, max_y, try_cnt, &new_path);
        }
    }
    if (max_y > current_y) {
        int next_place = road[current_x][current_y + 1];
        for (auto it = current_path->begin(); it != current_path->end(); ++it) {
            if (*it == next_place) {
                next_place = -1;
                break;
            }
        }
        if (next_place != -1) {
            std::vector<int> new_path = *current_path;
            new_path.push_back(next_place);
            Calculate(result, cur_point + next_place, current_x, current_y + 1, max_x, max_y, try_cnt, &new_path);
        }
    }
    if (current_x == max_x && current_y == max_y) {
        result->path_number_++;
        result->max_point_ = std::max(result->max_point_, cur_point);
        std::cout << result->path_number_ << " " << result->max_point_ << " " << cur_point << " ";
        for (int i = 0; i < current_path->size(); ++i) {
            std::cout << (*current_path)[i] << " ";
        }
        std::cout << std::endl;

    }
    *try_cnt += 1;
    return;
}

int main() {
    for (int i = 1; i < x_size + 1; ++i) {
        for (int j = 1; j < y_size + 1; ++j) {
            std::cout << road[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Result result;
    result.Clear();
    unsigned int try_cnt = 0;
    unsigned int try_max_cnt = x_size + y_size - 2;
    for (unsigned int i = try_max_cnt - x_size + 1; i < try_max_cnt; ++i) {
        try_max_cnt = try_max_cnt * i;
    }
    for (unsigned int i = 1; i <= x_size - 1; ++i) {
        try_max_cnt = try_max_cnt / i;
    }
    std::vector<int> initial_path;
    initial_path.push_back(road[1][1]);
    Calculate(&result, road[1][1], 1, 1, x_size, y_size, &try_cnt, &initial_path);
    std::cout << "#1 " << result.path_number_ << " " << result.max_point_ << std::endl;
    return 0;
}

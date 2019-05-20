//
// Created by gate3 on 2019-05-20.
//
#include <iostream>
#include <string.h>
#include <assert.h>
#include <vector>

const int x_size = 3;
const int y_size = 3;
const int initial_x = 1;
const int initial_y = 1;
int road[x_size][y_size] = {};
int TotalCount(int n, int m) {
    assert(n >= 1 && m >= 1);
    assert(n <= 10 && m <= 10);
    if (n == 1 || m == 1) return 1;
    return TotalCount(n-1, m) + TotalCount(n, m-1);
}
class Result {
public:
    int path_number_;
    int max_point_;
    std::vector<int> path_;
};

void Calculate(Result* result, int cur_point, int current_x, int current_y, int max_x, int max_y) {
    assert(current_x <= max_x && current_x >= initial_x);
    assert(current_y <= max_y && current_y >= initial_y);

    if (max_x > current_x) {
        int next_place = road[current_x + 1][current_y];
        for (auto it = result->path_.begin(); it != result->path_.end(); ++it) {
            if (*it == next_place) {
                next_place = -1;
                break;
            }
        }
        if (next_place != -1) {
            result->path_.push_back(next_place);
            return Calculate(result, cur_point + next_place, current_x + 1, current_y, max_x, max_y);
        }
    }
    if (max_y > current_y) {
        int next_place = road[current_x][current_y + 1];
        for (auto it = result->path_.begin(); it != result->path_.end(); ++it) {
            if (*it == next_place) {
                next_place = -1;
                break;
            }
        }
        if (next_place != -1) {
            result->path_.push_back(next_place);
            return Calculate(result, cur_point + next_place, current_x , current_y + 1, max_x, max_y);
        }
    }

    if (current_x == x_size && current_y == y_size) {
        result->path_number_++;
        result->max_point_ = std::max(result->max_point_, cur_point);
    }
    return;
}

void Calculate2(Result* result, int cur_point, int max_x, int max_y) {
    Calculate2(result, )
    return;
}

int main() {
    int total_count = TotalCount(6, 6);
    std::cout << total_count << std::endl;

    return 0;
}

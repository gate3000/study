//
// Created by Minho Lee on 2019-05-21.
//
#include "fibonacci.h"
extern int result_set[40];
int main() {
    int zero_count;
    int one_count;
    int test_count;
    int test_case;
    std::cin >> test_count;
    for (int i=0; i<test_count; ++i) {
        zero_count = 0;
        one_count = 0;
        std::cin >> test_case;
        std::cout << test_case << std::endl;
        fibonacci(test_case, &zero_count, &one_count);
        std::cout << zero_count << " " << one_count << std::endl;
    }
    return 0;
}
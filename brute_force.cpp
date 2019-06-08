//
// Created by Minho Lee on 2019-06-01.
//

#include <iostream>
#include <string.h>

//O(N^2)
int SevenDwarfs() {
    int a[9];
    int n = 9;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i< n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (sum - a[i] - a[j] == 100) {
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    std::cout << a[k] << std::endl;
                }
                return 0;
            }
        }
    }
    return 0;
}

int CalculateDays() {
    int e, s, m;

    std::cin >> e >> s >> m;

    if (e == 15) e = 0;
    if (m == 19) m = 0;
    int try_index = s;
    while (true) {
        if (try_index % 15 == e && try_index % 19 == m) return try_index;
        try_index += 28;
        if (try_index > e*s*m) {
            std::cout << "Something Wrong!" << std::endl;
            return -1;
        }
    }
}

int PlusOneTwoThree(int input) {
    int result_array[11] = {1, 2, 4, 0, 0, 0, 0, 0, 0, 0};
    int result;

    if (input == 1) return 1;
    if (input == 2) return 2;
    if (input == 3) return 4;
    if (result_array[input] != 0) {
        return result_array[input];
    } else {
        result = PlusOneTwoThree(input-1) + PlusOneTwoThree(input-2) + PlusOneTwoThree(input-3);
        result_array[input] = result;
        return result;
    }
}

int main(void) {
    int case_num;
    int input;
    std::cin >> case_num;
    for (int i = 0; i < case_num; ++i) {
        std::cin >> input;
        std::cout << PlusOneTwoThree(input) << std::endl;
    }
    return 0;
}


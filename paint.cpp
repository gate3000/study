//
// Created by gate3 on 2019-05-23.
//


#include <iostream>
#include <cstring>
int house_cnt;
int cost[1002][3];
int result[1002][3];
char input[20];

int main() {
    result[0][0] = result[0][1] = result[0][2] = 0;
    std::cin.getline(input, '\n');
    house_cnt = std::atoi(input);
    for (int i=1; i <= house_cnt; ++i) {
        std::cin.getline(input, '\n');
        cost[i][0] = std::atoi(strtok(input, " "));
        cost[i][1] = std::atoi(strtok(NULL, " "));
        cost[i][2] = std::atoi(strtok(NULL, " "));
        result[i][0] = std::min(result[i-1][1], result[i-1][2]) + cost[i][0];
        result[i][1] = std::min(result[i-1][2], result[i-1][0]) + cost[i][1];
        result[i][2] = std::min(result[i-1][0], result[i-1][1]) + cost[i][2];
    }

    int min_cost = std::min(std::min(result[house_cnt][0], result[house_cnt][1]), result[house_cnt][2]);
    std::cout << min_cost << std::endl;
    return 0;
}
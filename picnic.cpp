#include <iostream>
#include <cstring>
#include <assert.h>
/*
const int STUDENT_MAX_COUNT = 10;
const int MAX_TEST_COUNT = 5;
int student_count = 0;
int couple_count = 0;
int match_count = 0;
char input[128] = {};
char* new_testcase;
int couple_matrix[STUDENT_MAX_COUNT][STUDENT_MAX_COUNT] = {0};
bool is_coupled[STUDENT_MAX_COUNT] = {false};

int CouplePairing(int student_count) {
    int first_free = -1;
    for (int i = 0; i < student_count; ++i) {
        if (is_coupled[i] == false) {
            first_free = i;
        break;
        }
    }

    if (first_free == -1) {
        return 1;
    } else {
        int result = 0;
        for (int i = first_free + 1; i < student_count; ++i) {
            if (!is_coupled[i] && couple_matrix[first_free][i] == 1) {
                is_coupled[first_free] = true;
                is_coupled[i] = true;
                result += CouplePairing(student_count);
                is_coupled[first_free] = false;
                is_coupled[i] = false;
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Picnic Problem" << std::endl;
    int testcase_count;
    int round = 0;
    int student_count[MAX_TEST_COUNT];
    int couple_count[MAX_TEST_COUNT];
    int** couple_matrix_pointer[MAX_TEST_COUNT];
    int is_coupled[STUDENT_MAX_COUNT];


    std::cin >> testcase_count; //First row is the number of test cases.
    assert(testcase_count > 0);
    assert(testcase_count <= MAX_TEST_COUNT);
    while (round < testcase_count) {
        char temp_input[128];
        std::cin.getline(temp_input, 128, '\n');
        student_count[round] = std::atoi(std::strtok(temp_input, " "));
        couple_count[round] = std::atoi(std::strtok(NULL,  " "));


        int** temp_matrix = new int*[STUDENT_MAX_COUNT];
        temp_matrix[]
        couple_matrix_pointer[round] = temp_matrix;
        std::cin.getline(temp_input, 128, '\n');
        char student_number[128] = std::strtok(temp_input, " ");
        for (int i = 0; i < student_count[round]; ++i) {


        }

    }


    while (round < testcase_count) {
        std::cout << "Round " << round << std::endl;
        //Input Handling Part
        std::cin.getline(input, 128, '\n');
        new_testcase = std::strtok(input, " ");
        student_count = std::atoi(new_testcase);
        couple_count = std::atoi(std::strtok(NULL, " "));
        std::cin.getline(input, 128, '\n');
        new_testcase = std::strtok(input, " ");

        for (int i = 0; i < couple_count; ++i) {
            if (new_testcase == nullptr) {
                std::cout << "Input Is Wrong!!!" << std::endl;
                return -1;
            }
            int couple_student1 = std::atoi(new_testcase);
            new_testcase = std::strtok(NULL, " ");
            int couple_student2 = std::atoi(new_testcase);
            if (couple_student1 > couple_student2) {
                couple_matrix[couple_student2][couple_student1] = 1;
            } else {
                couple_matrix[couple_student1][couple_student2] = 1;
            }
            new_testcase = std::strtok(NULL, " ");
        }

        //Calculation Part
        match_count = CouplePairing(student_count);

        //Round Finished
        std::cout << match_count << std::endl;
        round++;
    }
    return 0;
}
*/

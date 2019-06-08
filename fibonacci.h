#include <iostream>

int result_set[40] = {0, 1, };
int fibonacci(int n, int* zero, int* one) {
    int result;
    if (n==0) {
        result = 0;
        *zero += 1;
        return result;
    } else if (n==1) {
        result = 1;
        *one += 1;
        return result;
    } else {
        result = fibonacci(n-1, zero, one) + fibonacci(n-2, zero, one);
        return result;
    }
}


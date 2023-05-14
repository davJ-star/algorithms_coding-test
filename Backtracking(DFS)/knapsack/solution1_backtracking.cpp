// solution1_backtracking.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// GPT

#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int* values, int* weights, int n, int capacity, int index, int current_value) {
    if (capacity == 0 || index == n) {
        return current_value;
    }
    if (weights[index] > capacity) {
        return knapsack(values, weights, n, capacity, index + 1, current_value);
    }
    else {
        return max(
            knapsack(values, weights, n, capacity, index + 1, current_value),
            knapsack(values, weights, n, capacity - weights[index], index + 1, current_value + values[index])
        );
    }
}

int main() {
    int values[] = { 65, 50, 140, 150 };
    int weights[] = { 15, 10, 20, 25 };
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int result = knapsack(values, weights, n, capacity, 0, 0);
    printf("Maximum value: %d", result);

    return 0;
}

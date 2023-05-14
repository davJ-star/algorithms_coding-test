// solution_branch_and_bound.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int level;
    int profit;
    int weight;
    float bound;
} node;

typedef struct {
    node arr[MAX_SIZE];
    int front, rear;
} queue_of_node;

void initialize(queue_of_node* Q) {
    Q->front = Q->rear = 0;
}

int empty(queue_of_node* Q) {
    return Q->front == Q->rear;
}

int full(queue_of_node* Q) {
    return Q->rear == MAX_SIZE - 1;
}

void insert(queue_of_node* Q, node x) {
    if (full(Q)) {
        printf("Error: queue is full\n");
        exit(1);
    }
    Q->arr[Q->rear++] = x;
}

void remove(queue_of_node* Q, node* x) {
    if (empty(Q)) {
        printf("Error: queue is empty\n");
        exit(1);
    }
    *x = Q->arr[Q->front++];
}

float bound(node u, const int w[], const int p[], int n, int W) {
    int j, k, totweight;
    float result;
    if (u.weight >= W)
        return 0;
    else {
        result = u.profit;
        j = u.level + 1;
        totweight = u.weight;
        while ((j <= n) && (totweight + w[j] <= W)) {
            totweight = totweight + w[j];
            result = result + p[j];
            j++;
        }
        k = j;
        if (k <= n)
            result = result + (W - totweight) * p[k] / w[k];
        return result;
    }
}

void knapsack3(int n, const int p[], const int w[], int W, int* maxprofit) {
    queue_of_node Q;
    node u, v;
    initialize(&Q);
    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v, w, p, n, W);
    *maxprofit = 0;
    insert(&Q, v);

    while (!empty(&Q)) {
        remove(&Q, &v);
        if (v.bound > *maxprofit) {
            u.level = v.level + 1;
            u.profit = v.profit + p[u.level];
            u.weight = v.weight + w[u.level];
            if ((u.weight <= W) && (u.profit > *maxprofit))
                *maxprofit = u.profit;
            u.bound = bound(u, w, p, n, W);
            if (u.bound > *maxprofit) insert(&Q, u);
            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u, w, p, n, W);
            if (u.bound > *maxprofit) insert(&Q, u);
        }
    }
}

int main() {
    int n = 4;
    int values[] = { 11, 25, 50, 10, 35 };
    int weights[] = { 3, 11, 7, 15, 31 };
    int W = 8;
    int maxprofit = NULL;
    knapsack3(n, values, weights, W, &maxprofit);
    printf("Max profit: %d\n", maxprofit);
    return 0;
}

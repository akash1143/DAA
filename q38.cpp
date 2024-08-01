#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4  // Number of jobs and workers

int min(int a, int b) {
    return (a < b) ? a : b;
}

void copyToSolution(int curr_assignment[], int final_assignment[]) {
    for (int i = 0; i < N; i++) {
        final_assignment[i] = curr_assignment[i];
    }
}

int calculateCost(int costMatrix[N][N], int curr_assignment[]) {
    int total_cost = 0;
    for (int i = 0; i < N; i++) {
        total_cost += costMatrix[i][curr_assignment[i]];
    }
    return total_cost;
}

void branchAndBound(int costMatrix[N][N], int curr_assignment[], int final_assignment[], bool assigned[], int worker, int *min_cost) {
    if (worker == N) {
        int curr_cost = calculateCost(costMatrix, curr_assignment);
        if (curr_cost < *min_cost) {
            *min_cost = curr_cost;
            copyToSolution(curr_assignment, final_assignment);
        }
        return;
    }

    for (int job = 0; job < N; job++) {
        if (!assigned[job]) {
            assigned[job] = true;
            curr_assignment[worker] = job;
            branchAndBound(costMatrix, curr_assignment, final_assignment, assigned, worker + 1, min_cost);
            assigned[job] = false;
        }
    }
}

void solveAssignmentProblem(int costMatrix[N][N]) {
    int curr_assignment[N];
    int final_assignment[N];
    bool assigned[N] = {false};
    int min_cost = INT_MAX;

    branchAndBound(costMatrix, curr_assignment, final_assignment, assigned, 0, &min_cost);

    printf("Minimum cost: %d\n", min_cost);
    printf("Assignment of jobs to workers:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Job %d\n", i, final_assignment[i]);
    }
}

int main() {
    int costMatrix[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };

    solveAssignmentProblem(costMatrix);
    return 0;
}


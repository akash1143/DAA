#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define MAX 100

// Function to find the minimum cost path using dynamic programming
int tsp(int graph[MAX][MAX], int dp[MAX][1 << MAX], int visited, int pos, int n) {
    if (visited == (1 << n) - 1) {
        return graph[pos][0]; // Return to the starting point
    }

    if (dp[pos][visited] != -1) {
        return dp[pos][visited];
    }

    int answer = INF;

    // Try to go to every other city
    for (int city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) {
            int newCost = graph[pos][city] + tsp(graph, dp, visited | (1 << city), city, n);
            if (newCost < answer) {
                answer = newCost;
            }
        }
    }

    dp[pos][visited] = answer;
    return answer;
}

int main() {
    int n;
    
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    
    printf("Enter the distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize DP table with -1
    int dp[MAX][1 << MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Starting the TSP from the first city
    int result = tsp(graph, dp, 1, 0, n);

    printf("The minimum cost of visiting all cities is %d\n", result);

    return 0;
}


#include<stdio.h>   

void kruskal(int cost[][10], int n) {
    int par[n], a, b, u, v, i, j, min, mincost = 0, ec = 0;

    for (i = 0; i < n; i++)
        par[i] = -1;

    while (ec < n - 1) {
        min = 999;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
        while (par[u] != -1)
            u = par[u];
        while (par[v] != -1)
            v = par[v];

        if (u != v) {
            printf("edge from %d to  %d with cost %d is selected\n", a, b, min);
            mincost += min;
            par[a] = b;
            ec++;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost = %d\n", mincost);
}

int main() {
    int n, cost[10][10], i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    kruskal(cost, n);
    return 0;
}
// Output:
// Enter the number of vertices: 5
// Enter the cost matrix:
// 0 10 999 999 999
// 999 0 999 999 5
// 999 999 0 3 999
// 999 999 999 0 1
// 999 999 999 999 0
// edge from 3 to  4 with cost 1 is selected
// edge from 2 to  3 with cost 3 is selected
// edge from 1 to  4 with cost 5 is selected
// edge from 0 to  1 with cost 10 is selected
// Minimum cost = 19
// Shortest path from source vertex 0
// 0 to 0 = 0
// 0 to 1 = 10
// 0 to 2 = 13
// 0 to 3 = 16
// 0 to 4 = 6
// Time Complexity: O(n^2)

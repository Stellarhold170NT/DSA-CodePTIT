#include<bits/stdc++.h>
using namespace std;
#define MAX 15
#define INF 1e9

int n, dist[MAX][MAX], dp[MAX][1 << MAX];

int tsp(int i, int mask) {
    if (mask == (1 << n) - 1) return dist[i][0]; // all cities have been visited, return to city 0
    if (dp[i][mask] != -1) return dp[i][mask]; // value already computed

    int ans = INF;
    for (int j = 0; j < n; j++) {
        if (i != j && !(mask & (1 << j))) { // if city j has not been visited
            ans = min(ans, dist[i][j] + tsp(j, mask | (1 << j)));
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    cout << tsp(0, 1) << endl; // start from city 0

    return 0;
}

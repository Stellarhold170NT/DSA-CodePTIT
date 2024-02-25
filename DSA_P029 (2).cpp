#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 200

#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

#define MAX 15
#define INF 1e9

int n, dist[MAX][MAX], dp[MAX][1 << MAX];

int tsp(int i, int mask) {
    if (mask == (1 << n) - 1) return 0; // all cities have been visited, return to city 0
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
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }

        memset(dp, -1, sizeof dp);
        int res = 100000000;
        for (int i = 0; i < n; i++) {
            res = min(res, tsp(i, 1 << i));
        }
        cout << res << endl; // start from city 0

    }
    return 0;
}

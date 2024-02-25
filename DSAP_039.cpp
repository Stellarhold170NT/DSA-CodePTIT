#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <unordered_set>
using namespace std;

#define ll long long
//#define MAX (long long) 1000000000000000000
//#define M 100 + 5
//#define N 5000000 + 11
#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

const int MAX = 20;
int dp[MAX][1 << MAX], a[MAX][MAX], n;

int solve(int i, int mask) {
    if (i == n) return 0;
    if (dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for (int j = 0; j < n; j++) {
        if ((mask >> j) & 1) continue;
        ans = max(ans, a[i][j] + solve(i + 1, mask | (1 << j)));
    }
    return dp[i][mask] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        memset(dp, -1, sizeof dp);
        cout << solve(0, 0) << endl;
    }
    return 0;
}


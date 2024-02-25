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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		int arr[1001];
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
		}

		bool check = false;

		for (int i = k; i >= 1; i--) {
			if (arr[i] - 1 > arr[i - 1]) {
				check = true;
				arr[i] -= 1;
				for (int j = i + 1; j <= k; j++) {
					arr[j] = n - k + j;
				}
				break;
			}
		}

		if (!check) {
			for (int i = 1; i <= k; i++) {
				cout << n - k + i << " ";
			}
		}
		else
			for (int i = 1; i <= k; i++) {
				cout << arr[i] << " ";
			}
		cout << endl;
	}
}
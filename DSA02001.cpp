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
#define N 200000

//#define MOD (ll) 1000000007
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)

int n;
int arr[N];

void print(int n) {
	cout << "[";
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[n - 1];
	cout << "]" << endl;
}

void Try(int i) {
	if (i == 0) return;

	print(i);

	for (int j = 0; j < i - 1; j++) {
		arr[j] = arr[j] + arr[j + 1];
	}

	Try(i - 1);

}
int main() {
	int t;
	cin >> t;

	while (t--) {

		cin >> n;


		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		Try(n);
	}

	return 0;
}
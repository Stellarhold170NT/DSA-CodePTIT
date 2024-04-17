#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <unordered_set>
using namespace std;

#define ll long long
// MAX (long long) 1000000000000000000
//#define M 100 + 5
#define N 600000

#define MOD (ll) 998244353
#define ld long double
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define zero(n) setw(n) << setfill('0')
#define stp(n) fixed << setprecision(n)
#define endl "\n"

struct Point {
	int x, y;
};

double distance(Point& a, Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double bruteForce(Point v[], int n) {
	double minDist = DBL_MAX;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			minDist = min(minDist, distance(v[i], v[j]));
		}
	}

	return minDist;
}

double stripClosest(Point strip[], int n, double d) {
	double minDist = d;
	sort(strip, strip + n, [](Point& a, Point& b) {
		return a.y < b.y;
		});

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n && (strip[j].y - strip[i].y) < minDist; j++) {
			minDist = min(minDist, distance(strip[i], strip[j]));
		}
	}
	return minDist;
}

double minPath(Point v[], int n) {
	if (n <= 3) return bruteForce(v, n);

	int mid = n / 2;
	double dl = minPath(v, mid);
	double dr = minPath(v + mid, n - mid);
	double d = min(dl, dr);

	Point strip[1001];
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (abs(v[i].x - v[mid].x) < d) {
			strip[idx] = v[i], idx++;
		}
	}


	return min(d, stripClosest(strip, idx, d));
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		Point p[1000];

		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
		}

		sort(p, p + n, [](Point& a, Point& b) {
			return a.x < b.x;
			});

		cout << stp(6) << minPath(p, n) << endl;
	}

	return 0;
}
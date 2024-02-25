#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int f[10000] = { 0 };
vector<int> nt;
vector<int> Next[10000];

void SNT() {
	for (int i = 2; i <= 9999; i++) {
		for (int j = i * i; j <= 9999; j += i) {
			f[j] = 1;
		}
	}

	for (int i = 1000; i <= 9999; i++) {
		if (f[i] == 0) {
			nt.push_back(i);
		}
	}
}

bool check(int x, int y) {
	int count = 0;

	while (x && y) {
		if (x % 10 != y % 10) count++;
		x /= 10;
		y /= 10;
	}

	return count == 1;
}

void init() {
	int len = nt.size();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (check(nt[i], nt[j])) {
				Next[nt[i]].push_back(nt[j]);
				Next[nt[j]].push_back(nt[i]);
			}
		}
	}
}

int search(int x, int y) {
	bool visited[10000] = { false };
	int count[10000] = { 0 };
	queue <int> iDex;
	iDex.push(x);
	visited[x] = true;

	while (!iDex.empty()) {
		int num = iDex.front();
		iDex.pop();
		if (num == y) return count[num];
		for (int i = 0; i < Next[num].size(); i++) {
			if (visited[Next[num][i]]) continue;
			visited[Next[num][i]] = true;
			count[Next[num][i]] = count[num] + 1;
			iDex.push(Next[num][i]);
		}
	}
}
int main() {
	SNT();
	init();
	int t;
	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		int res = search(x, y);
		cout << res << endl;
	}

	return 0;
}
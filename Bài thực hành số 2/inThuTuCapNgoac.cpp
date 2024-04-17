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
#include <bitset>
using namespace std;

#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main() {
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = s.length();
		s = " " + s;

		stack<int> st;
		vector<int> res;

		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (s[i] == '(') {
				st.push(cnt);
				res.push_back(cnt);
				cnt++;
			}
			else if (s[i] == ')') {
				int tmp = st.top();
				st.pop();
				res.push_back(tmp);
			}
		}

		for (auto x : res) {
			cout << x << " ";
		}
		cout << endl;
	}

	return 0;
}
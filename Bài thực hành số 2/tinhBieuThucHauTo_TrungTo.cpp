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

ll calc(ll a, ll b, string x) {
	if (x == "+") return a + b;
	else if (x == "-") return a - b;
	else if (x == "*") return a * b;
	else if (x == "/") return a / b;
	return 0;
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		cin.ignore();
		string s;
		getline(cin, s);

		stringstream ss(s);
		string tmp;
		vector<string> v;
		while (ss >> tmp) {
			v.push_back(tmp);
		}

		if (isdigit(v[0][v.size() - 1])) {
			stack<ll> st;
			for (int i = 0; i < v.size(); i++) {
				if (isdigit(v[i][v[i].size() - 1])) st.push(stoll(v[i]));
				else {
					ll b = st.top();
					st.pop();
					ll a = st.top();
					st.pop();
					ll c = calc(a, b, v[i]);
					st.push(c);
				}
			}
			cout << st.top() << endl;
		}
		else {
			stack<ll> st;
			for (int i = v.size() - 1; i >= 0; i--) {
				if (isdigit(v[i][v[i].size() - 1])) st.push(stoll(v[i]));
				else {
					ll b = st.top();
					st.pop();
					ll a = st.top();
					st.pop();
					ll c = calc(a, b, v[i]);
					st.push(c);
				}
			}
			cout << st.top() << endl;
		}
	}

	return 0;
}
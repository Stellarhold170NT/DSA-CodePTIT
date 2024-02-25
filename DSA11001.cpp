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

class Node {
public:
	Node* left;
	Node* right;
	char c;

	Node(char c) {
		this->c = c;
		this->left = nullptr;
		this->right = nullptr;
	}
};

Node* createNode(char c) {
	Node* node = new Node(c);
	return node;
}

void inOrder(Node* s) {
	if (s != nullptr) {
		inOrder(s->left);
		cout << s->c;
		inOrder(s->right);
	}
}

int main() {
	int t;
	cin >> t;

	string operation = "+-*/";

	while (t--) {
		string s;
		cin >> s;

		stack<Node*> st;

		int len = s.length();

		for (int i = 0; i < len; i++) {
			if (operation.find(s[i]) != string::npos) {
				Node* tmp = createNode(s[i]);
				tmp->right = st.top();
				st.pop();

				tmp->left = st.top();
				st.pop();

				st.push(tmp);
			}
			else st.push(createNode(s[i]));
		}

		inOrder(st.top());
		cout << endl;
	}

	return 0;
}
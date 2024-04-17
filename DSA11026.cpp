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
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int d = 0;
bool check = true;

int res = 0;

long long sum = 0;
int ans = -1e9;

class Node {
public:
	int x;
	Node* left;
	Node* right;

	Node(int x) {
		this->x = x;
		left = nullptr;
		right = nullptr;
	}
};

void connect(Node* r, int u, int v, char c) {
	if (r == nullptr) return;
	if (r->x == u) {
		Node* n = new Node(v);
		if (c == 'L') r->left = n;
		else r->right = n;
	}
	else {
		connect(r->left, u, v, c);
		connect(r->right, u, v, c);
	}
}

void postOrder(Node* root) {
	if (root != nullptr) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->x << " ";
	}
}

Node* buildTree(int arr[], int left, int right) {
	if (left <= right) {
		int mid = (left + right) / 2;
		Node* n = new Node(arr[mid]);

		n->left = buildTree(arr, left, mid - 1);
		n->right = buildTree(arr, mid + 1, right);

		return n;
	}
	else return nullptr;
}


int main() {
	faster();
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int arr[1001];

		Node* root = nullptr;


		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}

		sort(arr + 1, arr + n + 1);

		root = buildTree(arr, 1, n);

		res = 0;

		postOrder(root);
		cout << endl;
	}
	return 0;
}
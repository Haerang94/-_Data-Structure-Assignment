#include <iostream>
#define min(a,b)((a)<(b)?(a):(b))
using namespace std;


int a[100001][2];
bool b[100001] = { 1 };
int root;


int countNode(int x) {
	if (x == -1)return 0;
	return (1 + countNode(a[x][0]) + countNode(a[x][1]));
}

int cutting(int x, int n) {
	int cutted, left, sub, all;
	all = countNode(root);

	int m = all;

	for (int j = 1; j <= n; j++) {
		for (int k = 0; k < 2; k++) {
			cutted = countNode(a[j][k]);
			left = all - cutted;
			sub = left - cutted;

			if (sub < 0)sub *= -1;
			m = min(m, sub);
		}
	}
	return m;
}



int main() {
	int n;
	cin >> n;
	int count[10000] = { 0 };
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;


		if (y == 0) {
			a[x][0] = -1;
		}
		else {
			a[x][0] = y;
			count[y] = 1;

		}
		if (z == 0) {
			a[x][1] = -1;
		}
		else {
			a[x][1] = z;
			count[z] = 1;
		}
	}


	for (int j = 1; j <= n; j++) {
		if (count[j] == 0)root = j;
	}

	cout << cutting(root, n) << endl;


	return 0;
}
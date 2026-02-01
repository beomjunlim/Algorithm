#include <iostream>
using namespace std;

int arr[3] = { 1, 2, 3 };

void powerset(int n) {
	int max = 1 << n; // 2 ^ n
	for (int i = 0; i < max; i++) {
		cout << "{";
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))
				cout << arr[j];
		}
		cout << "}" << endl;
	}
}

int main() {
	powerset(3);

	return 0;
}
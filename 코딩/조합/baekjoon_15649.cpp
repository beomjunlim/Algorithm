#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }

    // next_permutation은 오름차순으로 정렬된 상태에서 시작해야 모든 경우를 다 찾습니다.
    sort(arr.begin(), arr.end());

    do {
        // n개 중 r개만 출력하여 nPr 구현
        for (int i = 0; i < r; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';

        // 뒷부분(r번째 이후)을 뒤집어서 중복된 앞부분(r개)의 출력을 건너뜁니다.
        reverse(arr.begin() + r, arr.end());

    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}
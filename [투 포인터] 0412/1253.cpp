#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) {  // left가 right보다 작을 동안(왼쪽에 위치)
        if (left == idx) {  // left와 idx번째 수가 같을 경우
            left++;  // left 증가
            continue;
        }
        if (right == idx) {  // right와 idx번째 수가 같을 경우
            right--;  // right 감소
            continue;
        }

        if (num[left] + num[right] == num[idx]) {  // left 수와 right 수 더한 값이 inx번째 수일 경우
            // 좋은 수 조건 만족
            return true;  // true 리턴
        }
        if (num[left] + num[right] > num[idx]) {  // left 수와 right 수 합이 더 크면
            right--;  // 제일 큰 수 감소
        } else {  // 작다면
            left++;  // 제일 작은 수 증가
        }
    }
    return false;  // false 리턴
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;  // 입력하는 수 개수 n, 좋은 수 개수

    //입력
    cin >> n;
    vector<int> num(n, 0);  // 수의 개수 n만큼 저장할 벡터 생성
    for (int i = 0; i < n; i++) {  // 수의 개수 n 만큼 반복
        cin >> num[i];  // 배열에 입력
    }

    //연산
    sort(num.begin(), num.end());  // 오름차순 정렬
    for (int i = 0; i < n; i++) {  // 수의 개수 n 만큼 반복
        if (isGood(num, 0, n - 1, i)) {  // 좋은 수인지 확인
            ans++;  // 좋은 수 개수 +1
        }
    }

    //출력
    cout << ans;
    return 0;
}
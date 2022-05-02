#include <iostream>
#include <vector>

using namespace std;

vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans;  // 정답 저장할 벡터 선언
    while (left < right) {    // left가 right보다 작을 동안 반복
        int diff = right * right - left * left; 
        //성원이의 현재 몸무게 제곱에서 기억하는 몸무게의 제곱을 뺀 값

        if (diff <= g) {  // 값이 g보다 작거나 같을 경우
            if (diff == g) {  // 값이 g와 같을 경우
                ans.push_back(right);  // right를 정답에 추가
            }
            right++; //값이 g보다 작은 경우라면 현재 몸무게(right) 증가
        } else {  // 값이 g보다 큰 경우
            left++;  // 기억하고 있던 몸무게(left)를 증가
        }
    }
    return ans;  // ans 리턴
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {
    int g;  // 성원이의 현재 몸무게의 제곱 - 성원이가 기억하고 있던 몸무게의 제곱 g

    //입력
    cin >> g;

    //연산
    vector<int> ans = possibleWeight(1, 2, g);

    //출력
    if (!ans.size()) {  // 가능한 몸무게가 없다면
        cout << "-1";  // -1 출력
        return 0;
    }
    for (int i = 0; i < ans.size(); i++) {  // ans 크기만큼 반복
        cout << ans[i] << '\n';    // ans 출력
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //배열 크기

int n, m;  // 자연수 n개, 길이 m개
vector<int> num(SIZE);  // SIZE개 원소를 가지는 num 벡터 생성
vector<int> ans(SIZE);  // SIZE개 원소를 가지는  ans 벡터 생성
vector<bool> check(SIZE);  // 중복 제거 위해 check 벡터 생성

void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {  // m번 반복
            cout << ans[i] << ' ';  // 수열 출력
        }
        cout << '\n';  // 줄바꿈
        return;
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {  // n번 반복
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i];  // num[i]는 이전에 선택한 값이 됨
            ans[cnt] = num[i];  //ans 배열에 넣기
            check[i] = true;   // check 배열 true로 해서 수 위치 중복
            backtracking(cnt + 1);
            check[i] = false;  // check 배열 false로 돌려놓음
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    //입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {  // n번 반복
        cin >> num[i];  // n개의 수 입력
    }

    //연산
    sort(num.begin(), num.begin() + n);  // 오름차순 정렬

    //백트래킹 & 출력
    backtracking(0);
    return 0;
}
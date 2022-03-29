#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int SIZE = 21;  // 크기 21

/**
 * [집합] - 단순 구현 문제
 *
 * ver1. 배열 사용 풀이
 * set()을 사용해서 매번 연산을 하면 시간이 굉장히 오래 걸려요.
 * 입력되는 x의 값이 1~20으로 범위가 매우 작기 때문에, 각 숫자가 집합에 들어있는 여부를 저장하는 배열을 이용합니다.
 *
 * 1. 집합에는 1~20의 숫자만 입력 or 제거됨 (=true or false)
 * 2. 크기 21의 bool 배열을 선언
 * 3. 입력은 true 처리, 제거는 false 처리
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, num;  // 수행 연산 수 m, 숫자 num
    string cmd;  // 연산
    vector<bool> s(SIZE, false);  // bool 타입 벡터 선언

    cin >> m;  // m 입력
    while (m--) {  // m번 반복
        cin >> cmd;  // 연산 입력
        if (cmd == "all") {  // all을 입력 했을 경우
            s.assign(SIZE, true);  // SIZE개의 원소 입력
            continue;
        }
        if (cmd == "empty") {  // empty을 입력 했을 경우
            s.assign(SIZE, false);  //  SIZE개의 원소 제거
            continue;
        }

        cin >> num;  // 숫자 입력
        if (cmd == "add") {  // add을 입력 했을 경우
            s[num] = true;  // num 입력
            continue;
        }
        if (cmd == "remove") {  // remove을 입력 했을 경우
            s[num] = false;  // num 제거
            continue;
        }
        if (cmd == "check") {  // check을 입력 했을 경우
            cout << s[num] << '\n'; //bool 형을 출력하면 true: 1, false: 0으로 출력
            continue;
        }
        if (cmd == "toggle") {  // toggle을 입력 했을 경우
            s[num] = !s[num];  // num이 있으면 제거, 없으면 추가
            continue;
        }
    }
    return 0;
}
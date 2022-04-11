#include <iostream>
#include <deque>

using namespace std;

string dqToString(deque<char>& dq) {
    string ans = "";   // 문자열
    while (!dq.empty()) {  // dq가 비어있지 않을 동안 반복
        ans += dq.front();  // ans에 dq의 첫 번째 원소 더함
        dq.pop_front();  // dq의 처음 원소를 삭제
    }
    return ans;  // ans 반환
}

string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {  // 문자열 길이만큼
        switch (s[i]) {
        case '-': //현재 커서 앞에 있는 글자를 지운다.
            if (!dq_left.empty()) {  // 커서 앞 글자가 있으면
                dq_left.pop_back();  // dq_left 의 마지막 원소 삭제
            }
            break;
        case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
            if (!dq_left.empty()) {  // 커서 이전 글자가 있으면
                dq_right.push_front(dq_left.back());  // dq_left 의 마지막 원소를 dq_right 앞에 삽입
                dq_left.pop_back();  // dq_left 의 마지막 원소 삭제
            }
            break;
        case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
            if (!dq_right.empty()) {  // 커서 이후 글자가 있으면
                dq_left.push_back(dq_right.front());  //q_right 의 처음 원소를 dq_left 의 마지막에 삽입
                dq_right.pop_front();  //dq_right 의 처음 원소를 삭제
            }
            break;
        default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
            dq_left.push_back(s[i]);  //dq_left의 마지막에 원소 삽입
            break;
        }
    }

    string pass = dqToString(dq_left);  // 커서 왼쪽 값 저장
    pass += dqToString(dq_right);  // 그 뒤에 커서 오른쪽 값 저장
    return pass;  // 비밀번호 반환
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;  // 테스트 케이스 개수
    string s;  // 문자열

    //입력
    cin >> t;
    while (t--) {  // 테스트 케이스만큼 반복
        cin >> s;

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;
}
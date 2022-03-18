#include <iostream>
#include <unordered_set>

using namespace std;

/*
 * ver1. set을 이요한 풀이입니다.
 * 정렬을 할 필요가 없이, 삽입과 검색만 일어나는 문제입니다.
 * 입력의 수가 최대 1,000,000으로 삽입과 탐색이 많이 일어납니다.
 * 따라서, O(log N)의 set이 아니라 O(1)인 unordered_set을 사용해서 풀어야 합니다.
 * */

int main() {
    // 입출력 처리 속도 향상을 위한 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t;  // 테스트케이스의 개수
    cin >> t;
    while (t--) {  // t만큼 반복
        int n, m, input;  
        unordered_set<int> note1;  // int 타입을 가지는 unordered_set 변수 note1 선언

        // 수첩1에 해당되는 원소들을 unordered_set에 삽입
        cin >> n;
        while (n--) {  // n만큼 반복
            cin >> input;
            note1.insert(input);  // insert 함수를 써서 셋에 삽입
        }
        cin >> m;
        while (m--) {  // m만큼 반복
            cin >> input;
            // 반복자를 이용해서 원소가 셋에 포함되어 있는지 확인
            auto iter = note1.find(input);  // find 함수로 셋에서 input이 들어있는 원소의 iterator를 반환받음
            if (iter == note1.end()) {  // 존재하지 않으면 (수첩1에 숫자가 없으면)
                cout << "0\n";   // 0 출력
            }
            else {  // 존재하면 (수첩1에 숫자가 있으면)
                cout << "1\n";  // 1 출력
            }
        }
    }
    return 0;
}
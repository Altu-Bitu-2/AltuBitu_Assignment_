#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;  // 거점지 방문 횟수 n, 충전 선물 개수 a, 선물 가치 input
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n;  
    while (n--) {  // n번 반복
        cin >> a;  // 충전할 선물 개수 입력
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) {  // 최대 힙이 비어있을 경우(줄 선물이 없을 경우)
                cout << "-1\n";  // -1 출력
            }
            else {  
                cout << pq.top() << '\n';  // 최대 힙의 최상단 값 출력
                pq.pop();  // 가장 큰 값 반환
            }
        }
        else { //선물을 충전하는 경우
            while (a--) {  // a번 반복
                cin >> input;  // 선물 가치 입력
                pq.push(input);  // 원소 삽입
            }
        }
    }
    return 0;
}
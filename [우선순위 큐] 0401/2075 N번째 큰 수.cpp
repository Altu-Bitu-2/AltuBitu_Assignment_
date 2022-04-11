#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;  // n번째 큰 수, 채워진 수 input
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n;  // n 입력
    int size = n * n;  // n * n의 표
    while (size--) {  // n * n의 표 채울 동안
        //입력
        cin >> input;

        //연산
        pq.push(input);  // 최소 힙에 원소 삽입
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면(최소 힙에 상위 n개만 저장) 가장 작은 값 삭제
            pq.pop();  // 최소 힙에서 최소값 삭제
        }
    }

    //출력
    cout << pq.top();
    return 0;
}
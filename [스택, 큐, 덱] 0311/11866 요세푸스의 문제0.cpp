#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> simulation(int k, queue<int>& q) {
    vector<int> result; //요세푸스 순열
    int cnt = 0; //카운트 변수

    while (!q.empty()) {  // q가 비어있지 않을 동안 
        int x = q.front();  // 최상위 데이터 
        q.pop();  // front 데이터 삭제
        cnt++;  // 카운트 변수 증가
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x);  // x 원소 추가
            cnt = 0;  // 카운트 변수 0으로 
            continue;
        }
        q.push(x); //pop한 원소 다시 push
    }
    return result;
}

/**
 * 1. 큐에 1 ~ N까지 값 초기화
 * 2. 이후 k 번째 사람 찾기 위해 pop, push 반복
 * 3. k번째 pop 일 경우 요세푸스 순열에 저장, 이후 원소 제거 (다시 push 하지 않음!)
 */

int main() {
    int n, k;  // n명의 사람, k번째 사람 제거
    queue<int> q;  // q 선언

    //입력
    cin >> n >> k;
    for (int i = 1; i <= n; i++) { // 1~n까지 큐 값 초기화
        q.push(i);  
    }
    //연산
    vector<int> result = simulation(k, q);  // 
    //출력
    cout << '<';  // '<' 출력
    for (int i = 0; i < result.size() - 1; i++) {  // result[0]부터 result[result.size()-2]까지 출력
        cout << result[i] << ", ";  // 결과값 출력 후 , 출력 반복
    }
    cout << result[result.size() - 1] << '>';  // result[result.size()-1] 출력 후 '>' 출력
    return 0;
}
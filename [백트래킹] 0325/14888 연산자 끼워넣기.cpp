#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;  // 10억
const int SIZE = 11;

int n;  // 수의 개수 n
vector<int> num(SIZE + 1);  // SIZE+1개의 원소 가지는 벡터 num 생성
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;  // 최댓값, 최솟값

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);  // max_value와 sum 중 최댓값
        min_value = min(min_value, sum);  // min_value와 sum 중 최솟값
        return;
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) { 
            expression[i]--;  // 연산자 수 감소
            int new_sum = 0;
            switch (i) { //연산자 종류에 따라
            case 0:  // 덧셈일 경우
                new_sum = sum + num[cnt + 1];  // 새로운 결과 = sum + 다음 숫자
                break;
            case 1:  // 뺄셈일 경우
                new_sum = sum - num[cnt + 1];  // 새로운 결과 = sum - 다음 숫자
                break;
            case 2:  // 곱셈일 경우
                new_sum = sum * num[cnt + 1];  // 새로운 결과 = sum * 다음 숫자
                break;
            case 3:  // 나눗셈일 경우
                new_sum = sum / num[cnt + 1];  // 새로운 결과 = sum / 다음 숫자
                break;
            }
            backtracking(cnt + 1, new_sum);  // 수 인덱스 1증가, 새로운 결과
            expression[i]++;  // 연산자 수 증가 
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {  // n번 반복
        cin >> num[i];  // 수열 입력
    }
    for (int i = 0; i < 4; i++) {  // 4번 입력
        cin >> expression[i];  // 연산자 개수 표시
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value;
    return 0;
}
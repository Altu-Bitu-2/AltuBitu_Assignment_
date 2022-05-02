#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(int n, int d, int k, int c, vector<int> &belt) {
    vector<int> sushi(d + 1, 0); //초밥 먹은 개수

    //쿠폰으로 먹은 초밥
    int section_sushi = 1;  // 쿠폰으로 먹는 초밥 1
    sushi[c]++;  // 초밥 개수 증가

    //윈도우 초기화
    for (int i = 0; i < k; i++) {  //연속해서 먹는 접시의 수 k만큼 반복
        if (!sushi[belt[i]]) { //벨트에 있는 초밥 종류 중 먹지 않은 초밥 종류일 경우
            section_sushi++; // 먹을 수 있는 초밥 종류 증가
        }
        sushi[belt[i]]++; //벨트에 있는 초밥 인덱스 증가
    }

    int ans = section_sushi;  // ans는 슬라이딩 윈도우에서 먹을 수 있는 초밥 종류
    for (int i = k; i < n + k; i++) { //슬라이딩 윈도우
        sushi[belt[i - k]]--;// 제외되는 초밥 종류는 먹은 개수 1 감소
        if (!sushi[belt[i - k]]) { // 제외되는 초밥 종류를 표시한 후에 먹은 개수가 0일 경우
            section_sushi--;   //먹을 수 있는 초밥 종류 인덱스 감소
        }
        if (!sushi[belt[i % n]]) { // 윈도우에 추가되는 초밥이 먹지 않은 종류일 경우
            section_sushi++;  //먹을 수 있는 초밥 종류 인덱스 증가
        }
        sushi[belt[i % n]]++;  // 초밥 개수 증가
        ans = max(ans, section_sushi);  // 최댓값 저장
    } 
    return ans;  // ans 리턴
} 

/**
 * [회전 초밥]
 *
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 각 종류별 먹은 초밥의 개수를 세어주기
 */

int main() {
    int n, d, k, c;  // 벨트에 놓인 접시 수 n, 초밥 가짓수 d, 연속해서 먹는 접시 수 k, 쿠폰 번호 c

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0);  // n개 저장할 belt 벡터 선언하고 0으로 초기화
    for (int i = 0; i < n; i++) {  // n번 반복
        cin >> belt[i];  // 초밥 종류 입력받아 배열에 저장
    }

    //연산 & 출력
    cout << chooseSushi(n, d, k, c, belt);
    return 0;
}
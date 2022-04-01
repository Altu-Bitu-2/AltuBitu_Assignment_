#include <iostream>
#include <vector>

using namespace std;

vector<int> findPattern(int num) {  // 일의 자리 패턴 찾기
    vector<int> pattern = {num};  // 벡터 선언

    int temp = num;
    while (num != (temp * num) % 10) {  // num이 (temp * num)을 10으로 나눈 나머지와 다를 경우 반복
        temp *= num;  // temp에 num을 곱한 값을 다시 temp에 대입
        temp %= 10;  // temp를 10으로 나눈 나머지 값을 temp에 대입
        pattern.push_back(temp);  // 마지막 원소 뒤에 원소 temp 삽입
    }
    return pattern;  // 벡터 pattern 리턴
}

/**
 * [분산처리]
 *
 * - a^b의 일의 자리를 구하는 문제
 * - 일의 자리는 0 ~ 9 중 하나 이므로, 어떤 수를 계속 곱해 나가면 일의 자리는 패턴을 가지게 되어 있음
 *     ex) 2 -> 4 -> 8 -> 6 -> 2 ...
 * - 0 ~ 9까지 일의 자리 패턴을 미리 구한 후, a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력하면 된다.
 * - 0이 나올 경우 10번 컴퓨터가 처리하므로, 0이 출력되지 않도록 예외처리
 */

int main() {
    int t, a, b;  // 테스트케이스 t, a^b

    //0 ~ 9까지 일의 자리 패턴 미리 구하기
    vector<vector<int>> last_digit(10, vector<int>(0));  // 10개 원소를 가진 2차원 vector 선언
    vector<int> pattern_size(10, 1);  // 벡터 선언
    for (int i = 0; i < 10; i++) {  // 0~9까지 반복
        last_digit[i] = findPattern(i);  // 0~9까지 일의 자리 패턴 구하기
        pattern_size[i] = last_digit[i].size();  // 패턴의 길이
    }

    //입력
    cin >> t;  // t 입력
    while (t--) {  // t번 반복
        cin >> a >> b;  // a, b 입력
        a %= 10;  // a를 10으로 나눈 나머지 값을 a에 대입

        if (a == 0) {  // a가 0일 경우
            cout << "10\n";  // 10번 컴퓨터가 처리
            continue;
        }
        //인덱스가 0부터 시작하므로 (b - 1)로 계산해야 함을 주의
        cout << last_digit[a][(b - 1) % pattern_size[a]] << '\n';  //a의 일의 자리에 대한 (b - 1 % 패턴의 길이)번째 수를 출력
    }
    return 0;
}
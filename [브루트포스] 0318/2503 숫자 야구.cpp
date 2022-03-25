#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<int, int> ci;

struct baseball {
    string num;       //서로 다른 세 자리 수
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string& s1, string& s2) {
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {
        if (s1[i] == s2[i]) { //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++;  // 스트라이크 개수 증가
        }
        else if (s1.find(s2[i]) != s1.npos) { //위치 다른데 수가 존재 -> 볼
            ball_cnt++;  // 볼 개수 증가
        }
    }

    return ci(strike_cnt, ball_cnt);  // 스트라이크 개수, 볼 개수를 하나의 객체로 반환
}

int game(int n, vector<baseball>& question) {
    int ans = 0; //정답 개수

    for (int i = 123; i <= 987; i++) {  // 서로 다른 세 자리수 123부터 987까지 
        bool check = true;
        string s1 = to_string(i);  //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') { //0이 하나라도 있다면
            continue;
        }
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) { //서로 같은 수 하나라도 있다면
            continue;
        }

        for (int j = 0; j < n; j++) {  // n번 반복
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //하나라도 다르면
                check = false;  // 가능성 있는 답 아님
                break;
            }
        }
         
        if (check) {  // check가 true이면 
            ans++;  // 가능성 있는 답 개수 증가
        }
    }

    return ans;  // ans 반환
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치 + 수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n;  // 질문 횟수 n

    //입력
    cin >> n;

    vector<baseball> question(n);  // 벡터 선언
    for (int i = 0; i < n; i++) {  // n번 반복
        cin >> question[i].num >> question[i].strike >> question[i].ball;  // 질문한 세 자리 수, 답한 스트라이크 개수, 답한 볼의 개수
    }

    //연산 + 출력
    cout << game(n, question);  // 가능성 있는 답 개수 출력

    return 0;
}
#include <iostream>
#include<string>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) {  // b가 0이면
        return a;  // a를 리턴
    }
    return gcdRecursion(b, a % b);  // b와 a를 b로 나눈 나머지의 최대공약수 리턴
}

int main() {
    string s;  // n:m 

    //입력
    cin >> s;

    //연산(입력으로부터 n, m 추출하기)
    int index = s.find(':'); //':' 위치 찾기
    int n = stoi(s.substr(0, index)); //: 이전의 문자를 숫자로 변경
    int m = stoi(s.substr(index + 1, s.length())); //: 이후 문자를 숫자로 변경

    //최대공약수 구하기
    int g = gcdRecursion(max(n, m), min(n, m));  // n과 m 중 큰 수가 먼저 

    //출력
    cout << n / g << ':' << m / g << '\n';  // n과 m을 최대공약수로 나눈 값 출력

    return 0;
}
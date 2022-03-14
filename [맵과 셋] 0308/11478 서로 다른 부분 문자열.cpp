#include <iostream>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;

    set<string> set;

    string str = "";
    for (int i = 0; i < s.size(); i++) {
        str = "";
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
    }

    cout << set.size();
}

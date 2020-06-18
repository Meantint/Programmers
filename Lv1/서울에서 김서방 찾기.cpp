#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> seoul)
{
        string answer = "";

        int idx = -1;
        int size = seoul.size();
        for (int i = 0; i < size; ++i) {
                if (seoul[i] == "Kim") {
                        idx = i;
                        break;
                }
        }

        answer = "김서방은 " + to_string(idx) + "에 있다";
        return answer;
}
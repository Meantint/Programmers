#include <bits/stdc++.h>

using namespace std;

int solution(string arrangement)
{
        int answer = 0;

        string str = "";
        int level = 0; // 몇 개 겹쳤는지
        int size = arrangement.size();
        for (int i = 0; i < size; ++i) {
                if (arrangement[i] == '(') {
                        if (i + 1 < size && arrangement[i + 1] == ')') {
                                answer += level;
                                ++i;
                        }
                        else {
                                ++level;
                                str.push_back(arrangement[i]);
                        }
                }
                else {
                        ++answer;
                        --level;
                        str.pop_back();
                }
        }

        return answer;
}
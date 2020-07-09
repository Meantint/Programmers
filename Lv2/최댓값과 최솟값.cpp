#include <bits/stdc++.h>

using namespace std;

string solution(string s)
{
        string answer = "";

        vector<int> vec;
        string str = "";
        int size = s.size();
        for (int i = 0; i < size; ++i) {
                if (s[i] == ' ') {
                        vec.push_back(stoll(str));
                        str = "";
                        continue;
                }
                str += s[i];
        }
        vec.push_back(stoi(str));
        sort(vec.begin(), vec.end());
        answer = to_string(vec[0]) + ' ' + to_string(vec.back());

        return answer;
}
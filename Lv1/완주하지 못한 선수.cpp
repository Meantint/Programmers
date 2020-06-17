#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int size = completion.size();
    for (int i = 0; i < size; ++i) {
        // 같은 index에 있는 원소 값이 다르다면
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }
    return participant.back();
}
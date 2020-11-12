#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    // answer가 갱신 안되면 마지막 참가자가 완주 못한 것
    // answer가 갱신 되면 갱신 된 참가자가 완주 못한 것
    answer = participant.back();

    // 항상 참가자가 한 명 더 많다.
    int cSize = completion.size();
    for (int i = 0; i < cSize; ++i) {
        if (completion[i] == participant[i]) continue;

        // 다른 경우
        answer = participant[i];
        break;
    }

    return answer;
}
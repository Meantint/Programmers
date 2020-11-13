#include <iostream>
#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cnt = 0;
    // (p or P)를 만나면 ++cnt, (y or Y)를 만나면 --cnt 해준다.
    for (auto &c : s) {
        if (c == 'p' || c == 'P') ++cnt;
        else if (c == 'y' || c == 'Y')
            --cnt;
    }
    // 개수의 균형이 맞지 않는다면 answer를 false로 바꿔준다.
    if (cnt != 0) answer = false;

    return answer;
}
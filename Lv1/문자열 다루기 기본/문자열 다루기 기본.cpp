#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    if (s.size() == 4 || s.size() == 6) {
        for (auto &c : s) {
            if (c < '0' || c > '9') {
                answer = false;
                break;
            }
        }
    }
    else {
        answer = false;
    }

    return answer;
}
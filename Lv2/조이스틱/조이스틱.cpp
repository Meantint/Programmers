#include <string>
#include <vector>

using namespace std;

int solution(string name)
{
    int st, ed, answer = 0;
    int move = name.size() - 1;

    for (int i = 1; i < name.size(); ++i) {
        if (name[i] == 'A') {
            ed = st = i;
            while (ed < name.size() && name[ed] == 'A') {
                ++ed;
            }
            int left = st - 1, right = name.size() - ed;
            if (left >= right) {
                right *= 2;
            }
            else {
                left *= 2;
            }
            if (left + right < move) {
                move = left + right;
            }
            i = ed - 1;
        }
    }
    for (auto& n : name) {
        if (n <= 'N') {
            answer += (n - 'A');
        }
        else {
            answer += 26 - (n - 'A');
        }
    }
    answer += move;

    return answer;
}
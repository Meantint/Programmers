#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void solve(string s)
{
    if (s == "1") {
        return;
    }
    else {
        ++answer[0];

        string new_s = "";
        int size = s.size();

        for (int i = 0; i < size; ++i) {
            if (s[i] == '0') {
                ++answer[1];
            }
            else {
                new_s += '1';
            }
        }

        s = "";
        int num = new_s.size();

        while (num != 0) {
            s = (char)((num % 2) + '0') + s;
            num /= 2;
        }

        solve(s);

        return;
    }
}

vector<int> solution(string s)
{
    solve(s);

    return answer;
}
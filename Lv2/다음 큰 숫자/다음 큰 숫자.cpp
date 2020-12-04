#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;

    string str = "";
    while (n != 0) {
        str += to_string(n % 2);
        n /= 2;
    }
    str += '0';
    int size = str.size() - 1;
    int cnt_0 = 0, cnt_1 = 0;
    bool isChange = false;
    for (int i = 0; i < size; ++i) {
        if (str[i] == '1' && str[i + 1] == '0') {
            swap(str[i], str[i + 1]);
            for (int j = 0; j < cnt_1; ++j) {
                str[j] = '1';
            }
            for (int j = 0; j < cnt_0; ++j) {
                str[cnt_1 + j] = '0';
            }
            isChange = true;
            break;
        }
        if (str[i] == '0') {
            ++cnt_0;
        }
        else {
            ++cnt_1;
        }
    }
    if (!isChange) {
        str.back() = '0';
        str.push_back('1');
    }
    size = str.size();
    for (int i = 0; i < size; ++i) {
        answer += pow(2, i) * (str[i] - '0');
    }

    return answer;
}
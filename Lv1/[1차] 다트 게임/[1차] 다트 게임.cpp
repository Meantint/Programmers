#include <string>
#include <vector>

using namespace std;

vector<int> total;

int solution(string dartResult)
{
    int answer = 0;

    int size = dartResult.size();
    for (int i = 0; i < size; ++i) {
        // 0 ~ 10 사이의 숫자
        if (dartResult[i] == '1') {
            // 숫자가 10이라면
            if (dartResult[i + 1] == '0') {
                total.push_back(10);
                ++i;  // 다음 인덱스까지 읽는 것과 같으므로 ++i 해줘야한다.
            }
            // 숫자가 1이라면
            else {
                total.push_back(1);
            }
        }
        else if (dartResult[i] >= '0' && dartResult[i] <= '9') {
            total.push_back(dartResult[i] - '0');
        }
        // S or D or T
        else if (dartResult[i] == 'S') {
        }
        else if (dartResult[i] == 'D') {
            total.back() *= total.back();
        }
        else if (dartResult[i] == 'T') {
            total.back() *= (total.back() * total.back());
        }
        // Option
        else if (dartResult[i] == '#') {
            total.back() *= -1;
        }
        else if (dartResult[i] == '*') {
            total.back() *= 2;
            // total 사이즈가 2이상이라면
            if (total.size() >= 2) {
                total[total.size() - 2] *= 2;
            }
        }
    }
    for (auto& point : total) {
        answer += point;
    }

    return answer;
}
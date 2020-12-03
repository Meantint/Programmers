#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int answer;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    answer = 0;

    string str = "ACFJMNRT";
    do {
        bool allTrue = true;
        for (auto& elem : data) {
            int idx1, idx2 = 0;
            for (int i = 0; i < 8; ++i) {
                if (str[i] == elem[0]) {
                    idx1 = i;
                    continue;
                }
                if (str[i] == elem[2]) {
                    idx2 = i;
                    continue;
                }
            }
            if (elem[3] == '=') {
                if (abs(idx1 - idx2) != (elem[4] - '0') + 1) {
                    allTrue = false;
                    break;
                }
            }
            else if (elem[3] == '<') {
                if (abs(idx1 - idx2) >= (elem[4] - '0') + 1) {
                    allTrue = false;
                    break;
                }
            }
            // elem[3] == '>'
            else {
                if (abs(idx1 - idx2) <= (elem[4] - '0') + 1) {
                    allTrue = false;
                    break;
                }
            }
        }
        // 모든 조건을 만족할 경우
        if (allTrue) {
            ++answer;
        }
    } while (next_permutation(str.begin(), str.end()));

    return answer;
}
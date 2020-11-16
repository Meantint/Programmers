#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2)
{
    vector<string> answer;

    int size = arr1.size();
    vector<int> merge(size);

    for (int i = 0; i < size; ++i) {
        merge[i] = (arr1[i] | arr2[i]);
    }
    for (auto &val : merge) {
        string tmp = "";
        while (val != 0) {
            // 나누어 떨어진다면
            if (val % 2 == 0) {
                tmp += ' ';
            }
            // 나누어 떨어지지 않는다면
            else {
                tmp += '#';
            }
            val >>= 1;
        }
        // 암호의 길이가 n보다 작다면
        while (tmp.size() != n) {
            tmp += ' ';
        }
        // 거꾸로 뒤집어준다.
        reverse(tmp.begin(), tmp.end());
        answer.push_back(tmp);
    }

    return answer;
}
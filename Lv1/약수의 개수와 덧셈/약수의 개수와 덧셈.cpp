#include <string>
#include <vector>

using namespace std;

vector<int> arr;

int solution(int left, int right)
{
    int answer = 0;

    for (int i = 1; i < 32; ++i) {
        arr.push_back(i * i);
    }
    int size = arr.size();

    bool isCal = false;
    for (int i = left; i <= right; ++i) {
        isCal = false;
        for (int j = 0; j < size; ++j) {
            if (arr[j] > i) {
                break;
            }
            if (arr[j] == i) {
                answer -= i;
                isCal = true;
                break;
            }
        }

        if (!isCal) {
            answer += i;
        }
    }

    return answer;
}
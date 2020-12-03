#include <string>
#include <vector>

using namespace std;

vector<int> global_numbers;
int global_target, nSize;
int answer = 0;

void solve(int pos, int val, bool isPlus)
{
    if (pos != nSize) {
        int num = global_numbers[pos];
        // 마이너스라면
        if (!isPlus) {
            num *= -1;
        }
        solve(pos + 1, val + num, 1);
        solve(pos + 1, val + num, 0);
    }
    else {
        if (val == global_target) {
            ++answer;
        }
    }
}

int solution(vector<int> numbers, int target)
{
    answer = 0;
    global_numbers = numbers;
    global_target = target;
    nSize = global_numbers.size();

    solve(0, 0, 1);
    solve(0, 0, 0);
    answer >>= 1;

    return answer;
}
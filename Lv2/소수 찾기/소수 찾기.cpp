#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> allNum = {1};
vector<bool> isPrime(10000000, true);

void pushAllNum(int length, string numbers)
{
    do {
        // 중복되는 경우가 아주 많기 때문에 마지막 원소와 같을 경우 다음 원소로 넘어가준다.
        if (allNum.back() == stoi(numbers.substr(0, length))) {
            continue;
        }
        allNum.push_back(stoi(numbers.substr(0, length)));
    } while (next_permutation(numbers.begin(), numbers.end()));
}

int solution(string numbers)
{
    int answer = 0;

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10000000; ++i) {
        if (isPrime[i] == false) {
            continue;
        }
        for (int j = i * 2; j < 10000000; j += i) {
            isPrime[j] = false;
        }
    }
    sort(numbers.begin(), numbers.end());
    for (int i = 1; i <= numbers.size(); ++i) {
        pushAllNum(i, numbers);
    }
    sort(allNum.begin(), allNum.end());
    allNum.erase(unique(allNum.begin(), allNum.end()), allNum.end());
    for (auto& num : allNum) {
        if (isPrime[num]) {
            ++answer;
        }
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr)
{
    double answer = 0;

    int sum = 0;
    for (auto& a : arr) {
        sum += a;
    }
    answer = (double)(sum) / (double)arr.size();

    return answer;
}
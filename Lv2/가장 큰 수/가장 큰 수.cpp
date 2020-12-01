#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool comp(const int& n1, const int& n2)
{
    string s1 = to_string(n1) + to_string(n2);
    string s2 = to_string(n2) + to_string(n1);

    return stoi(s1) > stoi(s2);
}

string solution(vector<int> numbers)
{
    string answer = "";

    sort(numbers.begin(), numbers.end(), comp);
    for (auto& number : numbers) {
        answer += to_string(number);
    }
    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}
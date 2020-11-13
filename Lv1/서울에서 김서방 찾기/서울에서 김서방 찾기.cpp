#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";

    for (auto &str : seoul) {
        if (str == "Kim") {
            answer = "김서방은 " + to_string(&str - &seoul[0]) + "에 있다";
            break;
        }
    }

    return answer;
}
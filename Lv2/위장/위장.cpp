#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;

int solution(vector<vector<string>> clothes)
{
    int answer = 1;

    for (auto& e : clothes) {
        if (m.find(e[1]) != m.end()) {
            ++m[e[1]];
        }
        else {
            m[e[1]] = 1;
        }
    }
    for (auto& e : m) {
        answer *= (e.second + 1);
    }
    --answer;

    return answer;
}
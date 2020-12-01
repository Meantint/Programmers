#include <algorithm>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
    set<string> s;
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (auto& num : phone_book) {
        int pSize = num.size();
        for (int i = 0; i < pSize; ++i) {
            // 접두어가 존재하는 경우
            if (s.find(num.substr(0, i + 1)) != s.end()) {
                return false;
            }
        }
        s.insert(num);
    }

    return answer;
}
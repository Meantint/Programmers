#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define pii pair<int, int>

using namespace std;

vector<int> solution(string s)
{
        vector<int> answer(0);

        vector<pii> vec(100001); // Pair Vector 배열 초기화
        for (int i = 0; i < 100001; ++i) {
                vec[i].second = i;
        }

        for (int i = 2; i < s.size() - 2; ++i) {
                int num = 0;
                if (s[i] < '0' || s[i] > '9')
                        continue;
                while (s[i] >= '0' && s[i] <= '9') { // s[i]가 숫자라면 몇 인지 다 읽는 while문
                        num *= 10;
                        num += (s[i] - '0');
                        i++;
                }
                vec[num].first++;
        }
        sort(vec.begin(), vec.end(), greater<pii>());
        for (int i = 0; i < vec.size(); i++) {
                if (vec[i].first == 0)
                        break;
                answer.push_back(vec[i].second);
        }

        return answer;
}

// Test!!
int main()
{
        // vector<int> vec = solution("{{123}}");
        vector<int> vec = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");
        for (int i = 0; i < vec.size() - 1; ++i) {
                cout << vec[i] << ", ";
        }
        cout << vec[vec.size() - 1] << endl;

        return 0;
}

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg)
{
        vector<int> answer;

        map<string, int> m;
        int next_idx = 26;

        for (int i = 0; i < 26; ++i) {
                string str = "A";
                str[0] += i;
                m.insert(make_pair(str, i + 1));
        }

        for (int i = 0; i < msg.size(); ++i) {
                int len = 1;
                while (i + len <= msg.size() && m.count(msg.substr(i, len)) != 0) { // 정의되어 있는 최대길이의 문자를 찾는다.
                        len++;
                }
                len--;
                answer.push_back(m.find(msg.substr(i, len))->second);
                if (i + len + 1 <= msg.size()) {
                        string str = msg.substr(i, len);
                        str += msg[i + len];
                        m.insert(make_pair(str, ++next_idx));
                }

                i += (len - 1);
        }

        return answer;
}

int main()
{
        vector<int> vec = solution("TOBEORNOTTOBEORTOBEORNOT");
        for (int i = 0; i < vec.size(); ++i) {
                cout << vec[i] << endl;
        }

        return 0;
}

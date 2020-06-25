#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
        bool answer = true;

        map<string, int> m;
        int size = phone_book.size();
        for (int i = 0; i < size; ++i) {
                m.insert(make_pair(phone_book[i], 1));
        }
        for (int i = 0; i < size; ++i) {
                int cnt = 0;
                int strSize = phone_book[i].size();

                // 같은 전화번호는 있을 수 없다.
                // j <= strSize를 했을 경우 자기 자신이 무조건 걸리기 때문에
                // j < strSize를 사용하였음.
                // 길이가 더 큰 A 전화번호는
                // 상대적으로 길이가 더 작은 B 전화번호의 접두사가 절대 될 수 없다.
                for (int j = 1; j < strSize; ++j) {
                        // map 원소 중에 있다면 false
                        if (m.count(phone_book[i].substr(0, j)) == 1) {
                                answer = false;
                                return answer;
                        }
                }
        }

        return answer;
}
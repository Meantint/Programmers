// 이 문제를 통해 알게된 것
// 1. 문자열도 lower_bound, upper_bound를 사용할 수 있다.
// 2. '?'를 lower_bound에는 'a', upper_bound에는 'z'로 모두 바꿔줘야 맞는 답을
// 구할 수 있다.
// 3. sort에 설정한 compare 함수가 있다면 lower_bound, upper_bound에도 compare
// 함수를 적용(4번째 인자로)시켜줘야 한다.
// 4. 이분 탐색은 꽤 다양하게 활용할 수 있다.
// 5. 양쪽 끝 부분 중 하나인 경우를 탐색하는 문제는 reverse를 생각해야할 수
// 있다.(이 문제 같은 경우 reverse 시킨 후 똑같이 탐색함)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(string a, string b)
{
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}

vector<int> solution(vector<string> words, vector<string> queries)
{
    vector<int> answer;

    vector<string> r_words = words;
    int rSize = r_words.size();
    for (int i = 0; i < rSize; ++i) {
        reverse(r_words[i].begin(), r_words[i].end());
    }
    sort(words.begin(), words.end(), comp);
    sort(r_words.begin(), r_words.end(), comp);

    int size = queries.size();
    for (int i = 0; i < size; ++i) {
        if (queries[i][0] == '?') {
            string tmp = queries[i];
            reverse(tmp.begin(), tmp.end());

            int idx = tmp.find('?');
            int tmpSize = tmp.size();

            for (int i = idx; i < tmpSize; ++i) {
                tmp[i] = 'a';
            }
            int lo = lower_bound(r_words.begin(), r_words.end(), tmp, comp) -
                     r_words.begin();
            for (int i = idx; i < tmpSize; ++i) {
                tmp[i] = 'z';
            }
            int hi = upper_bound(r_words.begin(), r_words.end(), tmp, comp) -
                     r_words.begin();
            answer.push_back(hi - lo);
        }
        else {
            string tmp = queries[i];

            int idx = tmp.find('?');
            int tmpSize = tmp.size();

            for (int i = idx; i < tmpSize; ++i) {
                tmp[i] = 'a';
            }
            int lo = lower_bound(words.begin(), words.end(), tmp, comp) -
                     words.begin();
            for (int i = idx; i < tmpSize; ++i) {
                tmp[i] = 'z';
            }
            int hi = upper_bound(words.begin(), words.end(), tmp, comp) -
                     words.begin();
            answer.push_back(hi - lo);
        }
    }
    return answer;
}

int main()
{
    vector<int> vec =
        solution({"frodo", "front", "frost", "frozen", "frame", "kakao"},
                 {"fro??", "????o", "fr???", "fro???", "pro?"});

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << ' ';
    }
    cout << '\n';

    return 0;
}
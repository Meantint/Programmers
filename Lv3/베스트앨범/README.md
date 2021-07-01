# 프로그래머스 - 베스트앨범

&nbsp;STL map을 이용해서 풀었다. 내가봐도 너무 난잡하게 코드를 짠 것 같다.

- Programmers - [베스트앨범](https://programmers.co.kr/learn/courses/30/lessons/42579)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `key : genre`, `value : (plays, index)`를 저장하는 `map<string, vector<pair<int, int>>>` 변수 `m`을 만들었다.

- `key : genre`, `value : sum of values`인 `map<string, int>` 변수 `sum`을 만들었다.

- 횟수가 같을 때 작은 인덱스가 먼저 오게끔 만들어야 하므로 `sort` 방식을 수정해주는 함수 `comp`를 만들었다.

- 

## Code

```cpp
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<pair<int, int>>> m;
map<string, int> sum;

bool comp(pair<int, int>& p1, pair<int, int>& p2)
{
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    int gSize = genres.size();
    // 같은 장르끼리 묶어서 (재생 횟수, 인덱스)를 넣어준다.
    // sum에는 같은 장르들의 모든 합을 저장
    for (int i = 0; i < gSize; ++i) {
        if (m.find(genres[i]) == m.end()) {
            sum[genres[i]] = plays[i];
        }
        else {
            sum[genres[i]] += plays[i];
        }
        m[genres[i]].push_back(make_pair(plays[i], i));
    }

    // 각 장르를 재생 횟수 내림차순, 재생 횟수가 같다면 인덱스 오름차순으로 정렬한다.
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        sort((*iter).second.begin(), (*iter).second.end(), comp);
    }
    vector<pair<int, string>> sum_info(sum.size());
    for (auto iter = sum.begin(); iter != sum.end(); ++iter) {
        sum_info.push_back(make_pair((*iter).second, (*iter).first));
    }
    // 정렬을 위해 vector<int>형 변수로 옮겨준 후 sort 실행한다.
    sort(sum_info.begin(), sum_info.end(), greater<>());

    int sSize = sum_info.size();
    // 재생 횟수가 가장 많은 장르부터 아까 정렬했던 순서대로 넣어준다.
    for (int i = 0; i < sSize; ++i) {
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if ((*iter).first == sum_info[i].second) {
                int index = (*iter).second.size();
                for (int j = 0; j < index && j < 2; ++j) {  // 최대 두 명 넘으면 안됨
                    answer.push_back((*iter).second[j].second);
                }
            }
        }
    }

    return answer;
}
```

# 프로그래머스 - 메뉴 리뉴얼

&nbsp;`map` 라이브러리와 `algorithm` 라이브러리를 사용하고 조합까지 사용해서 헷갈리는 문제였다.

- Programmers - [메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- (코스, 카운팅 횟수) 형태의 페어를 만들기 위해 `map`을 사용하였다.

- `next_permutation`과 `orders[i]` 크기만큼의 `vector<int>` 타입의 `comb` 변수를 선언해서 조합 알고리즘을 구성하였다. `course[j]`의 크기를 수용할 수 있는 `orders[i]` 크기일 때 나올 수 있는 모든 경우의 수를 `map<string, int>` 변수 `m`에 새로 생성하거나 값을 추가하는 방식으로 제작하였다.

- 현재 `maxCount[i]` 값에 따라 `saveInfo[i]` 값을 갱신해주었다.

  - 현재 방문하고 있는 `m`의 원소와 현재 탐색하는 `course[i]`의 값이 같은 경우에만 한 번 더 수행과정을 거친다.

    - `iter->second > maxCount[i]`인 경우 `course[i]` 길이의 코스 중 가장 많이 주문한 조합이 바뀌는 것이기 때문에 `saveInfo[i].clear()`를 해준 후 `saveInfo[i].push_back(iter->first)`로 `saveInfo[i]`를 갱신해주고 `maxCount`도 갱신해준다.

    - `iter->second == maxCount[i]`인 경우 `course[i]` 길이의 코스 중 가장 많이 주문한 조합이 두 개 이상이기 때문에 `saveInfo[i].push_back(iter->first)`로 값을 추가만 해준다.

- 위의 작업이 끝난 후 들어있는 `saveInfo` 값들이 정답이므로 모두 `answer`에 넣어주고 오름차순 리턴을 위해서 `sort()`를 해준다.

## Code

```cpp
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> m;

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    int oSize = orders.size();
    int cSize = course.size();
    for (int i = 0; i < oSize; ++i) {
        string thisOrder = orders[i];
        sort(thisOrder.begin(), thisOrder.end());

        vector<int> comb(thisOrder.size(), 1);
        int combSize = comb.size();

        for (int j = 0; j < cSize; ++j) {
            if (thisOrder.size() < course[j]) {
                break;
            }

            for (int k = 0; k < course[j]; ++k) {
                comb[k] = 0;
            }

            do {
                string tmp = "";
                for (int k = 0; k < combSize; ++k) {
                    if (comb[k] == 0) {
                        tmp += thisOrder[k];
                    }
                }

                // 있는 경우
                if (m.find(tmp) != m.end()) {
                    ++m[tmp];
                }
                else {
                    m[tmp] = 1;
                }
            } while (next_permutation(comb.begin(), comb.end()));
        }
    }

    vector<int> maxCount(cSize, 2);
    vector<vector<string>> saveInfo(cSize);
    map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter) {
        for (int i = 0; i < cSize; ++i) {
            if (iter->first.size() == course[i]) {
                if (iter->second > maxCount[i]) {
                    maxCount[i] = iter->second;
                    saveInfo[i].clear();
                    saveInfo[i].push_back(iter->first);
                    break;
                }
                else if (iter->second == maxCount[i]) {
                    saveInfo[i].push_back(iter->first);
                    break;
                }
            }
            else {
                continue;
            }
        }
    }

    for (int i = 0; i < saveInfo.size(); ++i) {
        for (int j = 0; j < saveInfo[i].size(); ++j) {
            answer.push_back(saveInfo[i][j]);
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
```

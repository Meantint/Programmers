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
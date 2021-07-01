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
    for (int i = 0; i < gSize; ++i) {
        if (m.find(genres[i]) == m.end()) {
            sum[genres[i]] = plays[i];
        }
        else {
            sum[genres[i]] += plays[i];
        }
        m[genres[i]].push_back(make_pair(plays[i], i));
    }

    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        sort((*iter).second.begin(), (*iter).second.end(), comp);
    }
    vector<pair<int, string>> sum_info(sum.size());
    for (auto iter = sum.begin(); iter != sum.end(); ++iter) {
        sum_info.push_back(make_pair((*iter).second, (*iter).first));
    }
    sort(sum_info.begin(), sum_info.end(), greater<>());

    int sSize = sum_info.size();
    for (int i = 0; i < sSize; ++i) {
        for (auto iter = m.begin(); iter != m.end(); ++iter) {
            if ((*iter).first == sum_info[i].second) {
                int index = (*iter).second.size();
                for (int j = 0; j < index && j < 2; ++j) {
                    answer.push_back((*iter).second[j].second);
                }
            }
        }
    }

    return answer;
}
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define PSI pair<string, int>

using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;

    map<string, string> m;

    vector<PSI> tmp;  // 0 : Enter, 1 : Leave
    int rSize = record.size();
    for (int i = 0; i < rSize; ++i) {
        string user_id = "";
        string nickname = "";
        string word = record[i].substr(0, 5);
        int st = -1;

        if (word == "Enter") {
            for (st = 6; record[i][st] != ' '; ++st) {
                user_id += record[i][st];
            }
            nickname = record[i].substr(st + 1);
            m[user_id] = nickname;
            // cout << "user_id : " << user_id << ", nickname : " << nickname << '\n';
            tmp.push_back(make_pair(user_id, 0));
        }
        else if (word == "Leave") {
            tmp.push_back(make_pair(record[i].substr(6), 1));
        }
        // Change
        else {
            for (st = 7; record[i][st] != ' '; ++st) {
                user_id += record[i][st];
            }
            nickname = record[i].substr(st + 1);
            m[user_id] = nickname;
            // cout << "user_id : " << user_id << ", nickname : " << nickname << '\n';
        }
    }
    // cout << tmp.size() << '\n';
    // for (int i = 0; i < tmp.size(); ++i) {
    //     cout << tmp[i].first << ", " << tmp[i].second << '\n';
    // }
    int tSize = tmp.size();
    for (int i = 0; i < tSize; ++i) {
        // Enter
        if (tmp[i].second == 0) {
            answer.push_back(m[tmp[i].first] + "님이 들어왔습니다.");
        }
        // Leave
        else {
            answer.push_back(m[tmp[i].first] + "님이 나갔습니다.");
        }
        // cout << m[tmp[i].first] << '\n';
    }

    return answer;
}

// int main()
// {
//     vector<string> ans = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"});
//     for (int i = 0; i < ans.size(); ++i) {
//         cout << ans[i] << '\n';
//     }

//     return 0;
// }
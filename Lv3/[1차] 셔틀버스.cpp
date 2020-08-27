#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define PII pair<int, int>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";

    vector<int> bus_time;
    vector<vector<int>> bus(n, vector<int>(m, 0)); // i : (i + 1)번째 버스, j : 들어오는 사람 순서대로 저장해놓음
    for (int i = 0; i < n; ++i) {
        bus_time.push_back(540 + i * t);
    }
    vector<int> new_table;
    vector<int> first(n, 0); // 버스에 처음 탑승한 사람의 대기열 도착시간
    int size = timetable.size();
    for (int i = 0; i < size; ++i) {
        int time = 60 * stoi(timetable[i].substr(0, 2)) + stoi(timetable[i].substr(3, 2));
        new_table.push_back(time);
    }
    sort(new_table.begin(), new_table.end());

    int idx = 0; // 버스 index
    for (int i = 0; i < size; ++i) {
        if (idx >= bus_time.size()) {
            break;
        }
        if (new_table[i] <= bus_time[idx]) { // 사원의 대기열 도착시간이 셔틀 버스 도착 시간과 같거나 더 빠르다면
            if (bus[idx].back() != 0) { // 셔틀 버스의 인원이 모두 찼다면
                ++idx;
                --i;
            }
            else {
                int index = 0;
                while (index < bus[0].size()) {
                    if (bus[idx][index] == 0) {
                        bus[idx][index] = new_table[i];
                        break;
                    }
                    ++index;
                }
            }
        }
        else {
            ++idx;
            --i;
        }
    }
    // cout << "n : " << n << ", t : " << t << ", m : " << m << '\n';
    // for (int i = 0; i < bus.size(); ++i) {
    //     for (int j = 0; j < bus[0].size(); ++j) {
    //         cout << bus[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if (bus[n - 1][m - 1] == 0) {
        int num = bus_time[n - 1];
        answer += to_string(num / 600);
        num %= 600;
        answer += to_string(num / 60);
        num %= 60;
        answer += ':';
        if (num < 10) {
            answer += '0';
        }
        answer += to_string(num);
    }
    else {
        int num = bus[n - 1][m - 1] - 1;
        answer += to_string(num / 600);
        num %= 600;
        answer += to_string(num / 60);
        num %= 60;
        answer += ':';
        if (num < 10) {
            answer += '0';
        }
        answer += to_string(num);
    }

    return answer;
}

int main()
{
    cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" }) << '\n';
    cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" }) << '\n';
    cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" }) << '\n';
    cout << solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" }) << '\n';
    cout << solution(1, 1, 1, { "23:59" }) << '\n';
    cout << solution(10, 60, 45, { "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59", "23:59" }) << '\n';
    return 0;
}
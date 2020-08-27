#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines)
{
    int answer = 0;

    int size = lines.size();
    // [0] : h, [1] : m, [2] : s, [3] : response
    // vector<vector<double>> time(size, vector<double>(4, 0));
    vector<int> changeSec(size, 0);
    vector<int> changeSec_start(size, 0);
    vector<int> rp(size, 0.0);
    for (int i = 0; i < size; ++i) {
        changeSec[i] += 3600000 * stoi(lines[i].substr(11, 2));
        changeSec[i] += 60000 * stoi(lines[i].substr(14, 2));
        changeSec[i] += (int)(1000 * stod(lines[i].substr(17, 6)));
        string tmp = lines[i].substr(24);
        tmp.pop_back();
        // rp[i] = stod(tmp);
        changeSec_start[i] = changeSec[i] - (int)(1000 * stod(tmp)) + 1;

        // test
        cout << i << '\n';
        cout << changeSec_start[i] << ", " << changeSec[i] << "\n\n";
    }

    for (int i = 0; i < size; ++i) {
        int cnt = 0;
        for (int j = i; j < size; ++j) {
            if (changeSec[j] - changeSec[i] >= 4000) {
                break;
            }
            if (changeSec_start[j] <= changeSec[i] + 999) {
                ++cnt;
            }
        }
        answer = max(answer, cnt);
    }

    return answer;
}

int main()
{
    // vector<string> vec = {
    //     "2016-09-15 01:00:04.001 2.0s",
    //     "2016-09-15 01:00:07.000 2s"
    // };
    // vector<string> vec = {
    //     "2016-09-15 01:00:04.002 2.0s",
    //     "2016-09-15 01:00:07.000 2s"
    // };
    vector<string> vec = {
        "2016-09-15 20:59:57.421 0.351s",
        "2016-09-15 20:59:58.233 1.181s",
        "2016-09-15 20:59:58.299 0.8s",
        "2016-09-15 20:59:58.688 1.041s",
        "2016-09-15 20:59:59.591 1.412s",
        "2016-09-15 21:00:00.464 1.466s",
        "2016-09-15 21:00:00.741 1.581s",
        "2016-09-15 21:00:00.748 2.31s",
        "2016-09-15 21:00:00.966 0.381s",
        "2016-09-15 21:00:02.066 2.62s"
    };
    cout << solution(vec) << '\n';

    return 0;
}
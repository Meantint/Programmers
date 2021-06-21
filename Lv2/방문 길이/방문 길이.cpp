#include <algorithm>
// #include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

pair<int, int> current_pos = make_pair(0, 0);
int find_index;
vector<tuple<int, int, int>> save_pos;

// URDL
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

bool canMove(int y, int x)
{
    if (y < -5 || y > 5 || x < -5 || x > 5) {
        return false;
    }
    return true;
}

void Push()
{
    if (canMove(current_pos.first + dy[find_index], current_pos.second + dx[find_index])) {
        int cy, cx, cd;
        if (find_index > 1) {
            cy = current_pos.first + dy[find_index];
            cx = current_pos.second + dx[find_index];
            cd = find_index - 2;
        }
        else {
            cy = current_pos.first;
            cx = current_pos.second;
            cd = find_index;
        }

        save_pos.push_back(make_tuple(cy, cx, cd));

        current_pos.first += dy[find_index];
        current_pos.second += dx[find_index];
    }
}

void Move(char ch)
{
    if (ch == 'U') {
        find_index = 0;
    }
    else if (ch == 'R') {
        find_index = 1;
    }
    else if (ch == 'D') {
        find_index = 2;
    }
    else if (ch == 'L') {
        find_index = 3;
    }
    Push();
}
int solution(string dirs)
{
    int answer = 0;
    int size = dirs.size();

    save_pos.clear();
    for (int i = 0; i < size; ++i) {
        Move(dirs[i]);
    }

    answer = 1;
    sort(save_pos.begin(), save_pos.end());
    int save_size = save_pos.size();
    tuple<int, int, int> prev = save_pos[0];

    // for (int i = 0; i < save_size; ++i) {
    //     cout << get<0>(save_pos[i]) << ", " << get<1>(save_pos[i]) << ", " << get<2>(save_pos[i]) << '\n';
    // }

    for (int i = 1; i < save_size; ++i) {
        if (prev == save_pos[i]) {
            continue;
        }
        else {
            ++answer;
            prev = save_pos[i];
        }
    }

    return answer;
}
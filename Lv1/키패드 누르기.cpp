#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> phone = {
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { -1, 0, -1 }
};

string solution(vector<int> numbers, string hand)
{
    string str = "";
    int lh_x = 3, lh_y = 0;
    int rh_x = 3, rh_y = 2;
    int size = numbers.size();
    for (int i = 0; i < size; ++i) {
        if (numbers[i] == 1) {
            lh_x = 0;
            lh_y = 0;
            str += 'L';
        }
        else if (numbers[i] == 4) {
            lh_x = 1;
            lh_y = 0;
            str += 'L';
        }
        else if (numbers[i] == 7) {
            lh_x = 2;
            lh_y = 0;
            str += 'L';
        }
        else if (numbers[i] == 3) {
            rh_x = 0;
            rh_y = 2;
            str += 'R';
        }
        else if (numbers[i] == 6) {
            rh_x = 1;
            rh_y = 2;
            str += 'R';
        }
        else if (numbers[i] == 9) {
            rh_x = 2;
            rh_y = 2;
            str += 'R';
        }
        else if (numbers[i] == 2) {
            int px = 0;
            int py = 1;
            int ld = abs(lh_x - px) + abs(lh_y - py);
            int rd = abs(rh_x - px) + abs(rh_y - py);
            if (ld > rd) {
                rh_x = px;
                rh_y = py;
                str += 'R';
            }
            else if (ld < rd) {
                lh_x = px;
                lh_y = py;
                str += 'L';
            }
            else {
                if (hand == "right") {
                    rh_x = px;
                    rh_y = py;
                    str += 'R';
                }
                else {
                    lh_x = px;
                    lh_y = py;
                    str += 'L';
                }
            }
        }
        else if (numbers[i] == 5) {
            int px = 1;
            int py = 1;
            int ld = abs(lh_x - px) + abs(lh_y - py);
            int rd = abs(rh_x - px) + abs(rh_y - py);
            if (ld > rd) {
                rh_x = px;
                rh_y = py;
                str += 'R';
            }
            else if (ld < rd) {
                lh_x = px;
                lh_y = py;
                str += 'L';
            }
            else {
                if (hand == "right") {
                    rh_x = px;
                    rh_y = py;
                    str += 'R';
                }
                else {
                    lh_x = px;
                    lh_y = py;
                    str += 'L';
                }
            }
        }
        else if (numbers[i] == 8) {
            int px = 2;
            int py = 1;
            int ld = abs(lh_x - px) + abs(lh_y - py);
            int rd = abs(rh_x - px) + abs(rh_y - py);
            if (ld > rd) {
                rh_x = px;
                rh_y = py;
                str += 'R';
            }
            else if (ld < rd) {
                lh_x = px;
                lh_y = py;
                str += 'L';
            }
            else {
                if (hand == "right") {
                    rh_x = px;
                    rh_y = py;
                    str += 'R';
                }
                else {
                    lh_x = px;
                    lh_y = py;
                    str += 'L';
                }
            }
        }
        else if (numbers[i] == 0) {
            int px = 3;
            int py = 1;
            int ld = abs(lh_x - px) + abs(lh_y - py);
            int rd = abs(rh_x - px) + abs(rh_y - py);
            if (ld > rd) {
                rh_x = px;
                rh_y = py;
                str += 'R';
            }
            else if (ld < rd) {
                lh_x = px;
                lh_y = py;
                str += 'L';
            }
            else {
                if (hand == "right") {
                    rh_x = px;
                    rh_y = py;
                    str += 'R';
                }
                else {
                    lh_x = px;
                    lh_y = py;
                    str += 'L';
                }
            }
        }
    }

    return str;
}
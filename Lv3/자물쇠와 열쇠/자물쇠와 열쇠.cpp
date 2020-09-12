#include <iostream>
#include <string>
#include <vector>

using namespace std;

int keySize;
int lockSize;
vector<vector<int>> map;

bool search(vector<vector<int>> key, int x, int y)
{
    vector<vector<int>> test = map;

    for (int i = 0; i < keySize; ++i) {
        for (int j = 0; j < keySize; ++j) {
            if (test[i + x][j + y] == 0 && key[i][j] == 1) {
                test[i + x][j + y] = 1;
            }
            else if (test[i + x][j + y] == 1 && key[i][j] == 0) {
                test[i + x][j + y] = 1;
            }
            // 자물쇠 돌기와 닿는 부분이 있으면
            else if (test[i + x][j + y] == 1 && key[i][j] == 1) {
                // cout << x << y << ", " << i << j << '\n';
                return false;
            }
        }
    }
    // for (int i = keySize - 1; i < keySize + lockSize - 1; ++i) {
    //     for (int j = keySize - 1; j < keySize + lockSize - 1; ++j) {
    //         cout << test[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "\n\n";
    for (int i = keySize - 1; i < keySize + lockSize - 1; ++i) {
        for (int j = keySize - 1; j < keySize + lockSize - 1; ++j) {
            if (test[i][j] == 1) {
                continue;
            }
            else {
                return false;
            }
        }
    }
    // 자물쇠 돌기와 닿는 부분이 없고 자물쇠를 모두 채웠다면

    // cout << x << y << '\n';
    return true;
}

vector<vector<int>> rotate(vector<vector<int>> key)
{
    int size = key.size();
    // 복사해 줄 vector<vector<int>> 배열
    vector<vector<int>> tmp(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp[j][size - i - 1] = key[i][j];
        }
    }

    return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    // 각각 90, 180, 270도 회전시킨 배열
    vector<vector<int>> key1 = rotate(key);
    vector<vector<int>> key2 = rotate(key1);
    vector<vector<int>> key3 = rotate(key2);
    keySize = key.size();
    lockSize = lock.size();
    map.resize(lockSize + 2 * (keySize - 1), vector<int>(lockSize + 2 * (keySize - 1), 0));
    for (int i = 0; i < lockSize; ++i) {
        for (int j = 0; j < lockSize; ++j) {
            map[keySize - 1 + i][keySize - 1 + j] = lock[i][j];
        }
    }
    for (int i = 0; i < keySize + lockSize - 1; ++i) {
        for (int j = 0; j < keySize + lockSize - 1; ++j) {
            if (search(key, i, j) || search(key1, i, j) || search(key2, i, j) || search(key3, i, j)) {
                return true;
            }
        }
    }

    return false;
}
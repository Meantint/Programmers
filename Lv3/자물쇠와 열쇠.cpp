#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate90(vector<vector<int>> key)
{
    vector<vector<int>> tmp = key;
    int row = key.size();
    int col = key[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tmp[i][j] = key[row - j - 1][i];
        }
    }
    return tmp;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = true;
    vector<vector<int>> key90 = rotate90(key);
    vector<vector<int>> key180 = rotate90(key90);
    vector<vector<int>> key270 = rotate90(key180);

    int keySize = key.size();
    int lockSize = lock.size();
    vector<vector<int>> new_map((key.size() - 1) * 2 + lock.size(), vector<int>((key.size() - 1) * 2 + lock.size(), 0));
    for (int i = keySize - 1; i < keySize + lockSize - 1; ++i) {
        for (int j = keySize - 1; j < keySize + lockSize - 1; ++j) {
            new_map[i][j] = lock[i - keySize + 1][j - keySize + 1]; // 새로운 배열 생성
        }
    }
    int row = new_map.size() - keySize + 1;
    int col = new_map[0].size() - keySize + 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            // key original
            bool isKey = true;
            vector<vector<int>> cp_map = new_map;
            for (int k = 0; k < keySize; ++k) {
                for (int l = 0; l < keySize; ++l) {
                    if (key[k][l] == 1) {
                        if (cp_map[i + k][j + l] == 1) {
                            isKey = false;
                            break;
                        }
                        cp_map[i + k][j + l] = 1;
                    }
                }
                if (!isKey) {
                    break;
                }
            }
            if (isKey) {
                for (int k = keySize - 1; k < keySize + lockSize - 1; ++k) {
                    for (int l = keySize - 1; l < keySize + lockSize - 1; ++l) {
                        if (cp_map[k][l] == 0) {
                            isKey = false;
                            break;
                        }
                    }
                    if (!isKey) {
                        break;
                    }
                }
            }
            if (isKey) {
                return true;
            }
            // key 90
            isKey = true;
            cp_map = new_map;
            for (int k = 0; k < keySize; ++k) {
                for (int l = 0; l < keySize; ++l) {
                    if (key90[k][l] == 1) {
                        if (cp_map[i + k][j + l] == 1) {
                            isKey = false;
                            break;
                        }
                        cp_map[i + k][j + l] = 1;
                    }
                }
                if (!isKey) {
                    break;
                }
            }
            if (isKey) {
                for (int k = keySize - 1; k < keySize + lockSize - 1; ++k) {
                    for (int l = keySize - 1; l < keySize + lockSize - 1; ++l) {
                        if (cp_map[k][l] == 0) {
                            isKey = false;
                            break;
                        }
                    }
                    if (!isKey) {
                        break;
                    }
                }
            }
            if (isKey) {
                return true;
            }
            // key 180
            isKey = true;
            cp_map = new_map;
            for (int k = 0; k < keySize; ++k) {
                for (int l = 0; l < keySize; ++l) {
                    if (key180[k][l] == 1) {
                        if (cp_map[i + k][j + l] == 1) {
                            isKey = false;
                            break;
                        }
                        cp_map[i + k][j + l] = 1;
                    }
                }
                if (!isKey) {
                    break;
                }
            }
            if (isKey) {
                for (int k = keySize - 1; k < keySize + lockSize - 1; ++k) {
                    for (int l = keySize - 1; l < keySize + lockSize - 1; ++l) {
                        if (cp_map[k][l] == 0) {
                            isKey = false;
                            break;
                        }
                    }
                    if (!isKey) {
                        break;
                    }
                }
            }
            if (isKey) {
                return true;
            }
            // key 270
            isKey = true;
            cp_map = new_map;
            for (int k = 0; k < keySize; ++k) {
                for (int l = 0; l < keySize; ++l) {
                    if (key270[k][l] == 1) {
                        if (cp_map[i + k][j + l] == 1) {
                            isKey = false;
                            break;
                        }
                        cp_map[i + k][j + l] = 1;
                    }
                }
                if (!isKey) {
                    break;
                }
            }
            if (isKey) {
                for (int k = keySize - 1; k < keySize + lockSize - 1; ++k) {
                    for (int l = keySize - 1; l < keySize + lockSize - 1; ++l) {
                        if (cp_map[k][l] == 0) {
                            isKey = false;
                            break;
                        }
                    }
                    if (!isKey) {
                        break;
                    }
                }
            }
            if (isKey) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cout << solution({ { 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 1 } }, { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } }) << '\n';

    return 0;
}
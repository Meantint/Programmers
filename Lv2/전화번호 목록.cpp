#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;

    map<string, int> m;
    int size = phone_book.size();
    for (int i = 0; i < size; ++i) {
        if (m.count(phone_book[i]) > 0) {
            ++m[phone_book[i]];
        }
        else {
            m[phone_book[i]] = 1;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (m[phone_book[i]] > 1) {
            return false;
        }
        int strSize = phone_book[i].size();
        for (int j = 1; j <= strSize; ++j) {
            --m[phone_book[i]];
            if (m[phone_book[i].substr(0, j)] > 0) {
                return false;
            }
            ++m[phone_book[i]];
        }
    }

    return true;
}

int main()
{
    cout << solution({ "123", "123", "111" }) << '\n';

    return 0;
}
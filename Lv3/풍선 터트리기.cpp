#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a)
{
    int answer = 2;

    vector<int> left(a.size());
    vector<int> right(a.size());
    left[0] = a[0];
    right.back() = a.back();
    for (int i = 1; i < left.size(); ++i) {
        if (a[i] < left[i - 1]) {
            left[i] = a[i];
        }
        else {
            left[i] = left[i - 1];
        }
    }
    for (int i = right.size() - 2; i >= 0; --i) {
        if (a[i] < right[i + 1]) {
            right[i] = a[i];
        }
        else {
            right[i] = right[i + 1];
        }
    }
    // cout << '\n';
    // for (int i = 0; i < left.size(); ++i) {
    //     cout << setw(4) << a[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < left.size(); ++i) {
    //     cout << setw(4) << left[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < right.size(); ++i) {
    //     cout << setw(4) << right[i] << ' ';
    // }
    // cout << '\n';
    // cout << '\n';
    for (int i = 1; i < a.size() - 1; ++i) {
        if (a[i] < left[i - 1] || a[i] < right[i + 1]) ++answer;
    }

    return answer;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); ++i) {
        cin >> arr[i];
    }
    cout << solution(arr) << endl;

    return 0;
}
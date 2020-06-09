#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool alphabetCheck(char ch) {
    if (ch >= 'a' && ch <= 'z') return true;
    if (ch >= 'A' && ch <= 'Z') return true;

    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    // str1과 str2 문자를 모두 대문자로 바꿔준다.
    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] = str1[i] - 'a' + 'A';
        }
    }
    for (int i = 0; i < str2.size(); ++i) {
        if (str2[i] >= 'a' && str2[i] <= 'z') {
            str2[i] = str2[i] - 'a' + 'A';
        }
    }

    vector<string> vec1, vec2;
    for (int i = 0; i < str1.size() - 1; ++i) {
        if (alphabetCheck(str1[i]) && alphabetCheck(str1[i + 1])) {  // 둘 다 true 라면
            vec1.push_back(str1.substr(i, 2));
        }
    }
    for (int i = 0; i < str2.size() - 1; ++i) {
        if (alphabetCheck(str2[i]) && alphabetCheck(str2[i + 1])) {  // 둘 다 true 라면
            vec2.push_back(str2.substr(i, 2));
        }
    }
    if (vec1.size() == 0 && vec2.size() == 0) { // vec1, vec2 둘 다 공집합일 때 유사도 1
        answer = 1 * 65536;
        return answer;
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    int cntSame = 0;    // 교집합 개수 세는 int 변수
    int idx1 = 0;       // vec1 index
    int idx2 = 0;       // vec2 index
    while (1) {
        if (idx1 == vec1.size() || idx2 == vec2.size()) break;
        else {
            if (vec1[idx1] == vec2[idx2]) {
                cntSame++;
                idx1++; idx2++;
            }
            else {
                (vec1[idx1] < vec2[idx2]) ? idx1++ : idx2++;
            }
        }
    }

    answer = (int)((cntSame / (float)(vec1.size() + vec2.size() - cntSame)) * 65536);

    return answer;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << solution(str1, str2) << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string word, vector<string> pages)
{
    int answer = 0;

    for (int i = 0; i < word.size(); ++i) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 'a' + 'A';
        }
    }
    int size = pages.size();
    // 모두 대문자로 바꿔줌
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < pages[i].size(); ++j) {
            if (pages[i][j] >= 'a' && pages[i][j] <= 'z') {
                pages[i][j] = pages[i][j] - 'a' + 'A';
            }
        }
    }

    // [0] : basePoint, [1] : link
    vector<vector<int>> newsite(size, vector<int>(2, 0));
    vector<double> allPoints(size, 0);
    vector<string> linkName(size, "");

    // linkName 저장 & 단어 개수 찾기 위한 for문
    for (int i = 0; i < size; ++i) {
        int strSize = pages[i].size();
        for (int j = 0; j < strSize; ++j) {
            // ;;;; 문제가 너무 헷갈린다. (META)
            if (pages[i].substr(j, 5) == "<META") {
                for (int k = j + 5; k < strSize; ++k) {
                    if (pages[i].substr(k, 7) == "CONTENT") {
                        string str = "";
                        int index = k + 9;
                        while (pages[i][index] != '\"') {
                            str += pages[i][index];
                            ++index;
                        }
                        linkName[i] = str;
                        // cout << str << '\n';
                        break;
                    }
                    else if (pages[i][k] == '>') {
                        break;
                    }
                }
            }
            else if (pages[i].substr(j, word.size()) == word) {
                if ((pages[i][j - 1] < 'A' || pages[i][j - 1] > 'Z') &&
                    (pages[i][j + word.size()] < 'A' ||
                     pages[i][j + word.size()] > 'Z')) {
                    ++newsite[i][0];
                }
            }
            else if (pages[i].substr(j, 7) == "<A HREF") {
                ++newsite[i][1];
            }
        }
        allPoints[i] = (double)newsite[i][0];
    }
    // 외부 링크에 점수를 더해주는 for문
    for (int i = 0; i < size; ++i) {
        int strSize = pages[i].size();
        for (int j = 0; j < strSize; ++j) {
            if (pages[i].substr(j, 7) == "<A HREF") {
                string str = "";
                int index = j + 9;
                while (pages[i][index] != '\"') {
                    str += pages[i][index];
                    ++index;
                }
                for (int k = 0; k < size; ++k) {
                    // linkName[k]가 i의 외부 링크라면
                    if (linkName[k] == str) {
                        allPoints[k] +=
                            (double)newsite[i][0] / (double)newsite[i][1];
                        break;
                    }
                }
            }
        }
    }
    double max_num = -1;
    for (int i = 0; i < allPoints.size(); ++i) {
        if (allPoints[i] > max_num) {
            max_num = allPoints[i];
            answer = i;
        }
    }

    return answer;
}

// int main()
// {
//     cout << solution(
//                 "blind",
//                 {"<html lang=\"ko\" xml:lang=\"ko\" "
//                  "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
//                  "charset=\"utf-8\">\n  <meta property=\"og:url\" "
//                  "content=\"https://a.com\"/>\n</head>  \n<body>\nBlind "
//                  "Lorem "
//                  "Blind "
//                  "ipsum dolor Blind test sit amet, consectetur adipiscing "
//                  "elit. "
//                  "\n<a "
//                  "href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
//                  "<html lang=\"ko\" xml:lang=\"ko\" "
//                  "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
//                  "charset=\"utf-8\">\n  <meta property=\"og:url\" "
//                  "content=\"https://b.com\"/>\n</head>  "
//                  "\n<body>\nSuspendisse "
//                  "potenti. "
//                  "Vivamus venenatis tellus non turpis bibendum, \n<a "
//                  "href=\"https://a.com\"> Link to a </a>\nblind sed congue "
//                  "urna "
//                  "varius. Suspendisse feugiat nisl ligula, quis malesuada "
//                  "felis "
//                  "hendrerit ut.\n<a href=\"https://c.com\"> Link to c "
//                  "</a>\n</body>\n</html>",
//                  "<html lang=\"ko\" xml:lang=\"ko\" "
//                  "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
//                  "charset=\"utf-8\">\n  <meta property=\"og:url\" "
//                  "content=\"https://c.com\"/>\n</head>  \n<body>\nUt "
//                  "condimentum urna "
//                  "at felis sodales rutrum. Sed dapibus cursus diam, non "
//                  "interdum nulla "
//                  "tempor nec. Phasellus rutrum enim at orci consectetu "
//                  "blind\n<a "
//                  "href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"})
//          << '\n';
//     cout << solution(
//                 "Muzi",
//                 {"<html lang=\"ko\" xml:lang=\"ko\" "
//                  "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
//                  "charset=\"utf-8\">\n  <meta property=\"og:url\" "
//                  "content=\"https://careers.kakao.com/interview/list\"/>\n</"
//                  "head>  "
//                  "\n<body>\n<a "
//                  "href=\"https://programmers.co.kr/learn/courses/4673\"></"
//                  "a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
//                  "<html lang=\"ko\" xml:lang=\"ko\" "
//                  "xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta "
//                  "charset=\"utf-8\">\n  <meta property=\"og:url\" "
//                  "content=\"https://www.kakaocorp.com\"/>\n</head>  "
//                  "\n<body>\ncon%\tmuzI92apeach&2<a "
//                  "href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</"
//                  "html>"})
//          << '\n';

//     return 0;
// }
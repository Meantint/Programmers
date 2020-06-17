/* 
	2020.06.15 16:44 작성
	
	알고리즘 작성 시 주의사항 :
		1. 검사하는 문자의 길이가 다른게 있을때는 치환을 잘 해서 처리한다.
		2. 시간복잡도가 충분히 남으면 케이스 하나하나를 다 검사하도록 만드는 것도 나쁘지 않다.
			(이 문제의 경우 test case 12번 때문에 엄청 오래걸림. 틀린 이유는 당연히 놓치고 탐색하지 않는 부분이 있었기 때문.)
			(오히려 다 검사하게 만드는게 코드의 길이는 엄청나게 짧아졌음. 이 문제의 주석만 90줄..)
*/

#include <bits/stdc++.h>

using namespace std;

struct musicInfo {
        int startTime;
        int endTime;
        string music_name;
        string melody;
};

string solution(string m, vector<string> musicinfos)
{
        string answer = "";

        string cp = m;
        m = "";
        for (int i = 0; i < cp.size(); ++i) {
                if (cp[i] != '#')
                        m.push_back(cp[i]);
                else
                        m[m.size() - 1] = m[m.size() - 1] + 32;
        }

        vector<musicInfo> mi;
        int infoSize = musicinfos.size();
        for (int i = 0; i < infoSize; ++i) {
                // 구조체에 정보 저장
                musicInfo tmp;
                tmp.startTime = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
                tmp.endTime = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));

                int j;
                for (j = 12; musicinfos[i][j] != ','; ++j) {
                        tmp.music_name.push_back(musicinfos[i][j]);
                }

                //melody 넣는 코드
                ++j;
                for (; j < musicinfos[i].size(); ++j) {
                        if (musicinfos[i][j] != '#')
                                tmp.melody.push_back(musicinfos[i][j]);
                        else
                                tmp.melody[tmp.melody.size() - 1] = tmp.melody[tmp.melody.size() - 1] + 32;
                }

                mi.push_back(tmp);
        }

        int answerIdx = -1;
        for (int i = 0; i < mi.size(); ++i) {
                int time = mi[i].endTime - mi[i].startTime;
                if (time < m.size())
                        continue; // time안에 m을 다 못보는 경우 넘어간다.
                string str;
                for (int j = 0; j < time; ++j) {
                        str.push_back(mi[i].melody[j % mi[i].melody.size()]);
                }

                for (int j = 0; j < (str.size() - m.size() + 1); ++j) {
                        if (m.compare(str.substr(j, m.size())) == 0) { // 같다면
                                if (answerIdx == -1)
                                        answerIdx = i;
                                else
                                        answerIdx = ((mi[answerIdx].endTime - mi[answerIdx].startTime) >= (mi[i].endTime - mi[i].startTime) ? answerIdx : i);
                                break;
                        }
                }
        }
        if (answerIdx == -1)
                return "(None)"; // '(None)' -> (None) 으로 바꿨음 --> test case 4개 추가 정답
        answer = mi[answerIdx].music_name;
        return answer;
}

int main()
{
        cout << solution("ABCDEFG", { "12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF" }) << endl;
        cout << solution("CC#BCC#BCC#BCC#B", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" }) << endl;
        cout << solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF" }) << endl;
        cout << solution("CDCDF", { "12:00,12:14,HELLO,CDCDCDF", "13:00,13:05,WORLD,ABCDEF" }) << endl;
        return 0;
}

#include <bits/stdc++.h>

using namespace std;

// strict weak ordering을 만족하도록 작성해야함! (개고생함)
bool compare(vector<string> s1, vector<string> s2) {
	if (s1[3].compare(s2[3]) == 0) {    // s1과 s2의 head가 같다면
		return stoi(s1[1]) < stoi(s2[1]);
	}
	else if (s1[3].compare(s2[3]) < 0) {
		return true;
	}
	else return false;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;

	vector<vector<string>> div(0, vector<string>(4, ""));   // head, num, tail, head의 문자 모두 소문자로 바꿈
	for (int i = 0; i < files.size(); ++i) {
		vector<string> vec(4, "");

		for (int j = 0; j < files[i].size(); ++j) {
			if (files[i][j] < '0' || files[i][j] > '9') {
				vec[0].push_back(files[i][j]);
			}
			else if (files[i][j] >= '0' && files[i][j] <= '9') {
				vec[1].push_back(files[i][j]);
				++j;
				while (files[i][j] >= '0' && files[i][j] <= '9') { // 숫자 부분이라면
					vec[1].push_back(files[i][j]);
					++j;
				}
				vec[2] = files[i].substr(j);
				break;
			}
		}
		for (int i = 0; i < vec[0].size(); ++i) {
			if (vec[0][i] >= 'A' && vec[0][i] <= 'Z')
				vec[3].push_back((vec[0][i]) + 32);
			else
				vec[3].push_back(vec[0][i]);
		}
		div.push_back(vec);
	}
	
	// stable_sort가 필요한지 잘 생각해봐야함.. (개고생함)
	stable_sort(div.begin(), div.end(), compare);

	for (int i = 0; i < div.size(); ++i) {
		answer.push_back(div[i][0] + div[i][1] + div[i][2]);
	}

	return answer;
}

int main()
{
	vector<string> str = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
	vector<string> vec = solution(str);

	for (int i = 0; i < vec.size(); ++i) {
		cout << vec[i] << endl;
	}

	return 0;
}

#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
	int answer = 0;

	vector<int> score;
	int num = 0;
	for (int i = 0; i < dartResult.size(); ++i) {
		if (dartResult[i] - '0' > 1 && dartResult[i] - '0' < 10) {  // 2 ~ 9 사이의 숫자일 때(
			num = dartResult[i] - '0';
			continue;
		}
		else if (dartResult[i] - '0' == 1) {        	// 1일 때
			if (dartResult[i + 1] - '0' == 0) {     // 10일 때
				num = 10;
				continue;
			}
			else {
				num = dartResult[i] - '0';
				continue;
			}
		}
		else if (dartResult[i] == 'S') {
			score.push_back(num);
			num = 0;
		}
		else if (dartResult[i] == 'D') {
			num = pow(num, 2);
			score.push_back(num);
			num = 0;
		}
		else if (dartResult[i] == 'T') {
			num = pow(num, 3);
			score.push_back(num);
			num = 0;
		}
		else if (dartResult[i] == '*') {
			score[score.size() - 1] *= 2;
			if (score.size() >= 2) {
				score[score.size() - 2] *= 2;
			}
		}
		else if (dartResult[i] == '#') {
			score[score.size() - 1] *= -1;
		}
	}

	for (int i = 0; i < score.size(); ++i) {
		answer += score[i];
	}
	return answer;
}

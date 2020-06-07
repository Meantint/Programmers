#include <string>
#include <vector>
#include <iostream>

using namespace std;

string change(string p) {
	bool goodStr = true;
	string newStr = "";
	string u = "";
	string v = "";

	int cnt = 0;
	u += p[0];
	if (p[0] == '(') cnt++;
	else {
		goodStr = false;
		cnt--;
	}

	for (int i = 1; i < p.size(); ++i) {
		u += p[i];
		if (p[i] == '(') cnt++;
		else cnt--;

		if (cnt == 0 && i + 1 < p.size()) {
			v = p.substr(i + 1, p.size() - i);
			break;
		}
	}

	if (goodStr == true) {
		newStr += u;
		if (v != "") // v가 빈 문자열이 아니라면
			newStr += change(v);
	}
	else if (goodStr == false) {
		newStr += '(';
		if (v != "") // v가 빈 문자열이 아니라면
			newStr += change(v);
		newStr += ')';
		for (int i = 1; i < u.size() - 1; ++i) {
			if (u[i] == '(')    newStr += ')';
			else                newStr += '(';
		}
	}

	/*if (v != "") // v가 빈 문자열이 아니라면
		newStr += change(v);*/

	return newStr;
}

string solution(string p) {
	string answer = "";

	answer = change(p);

	return answer;
}

int main()
{
	string str;
	while (1) {
		cin >> str;
		if (str == "-1")	break;
		cout << solution(str) << endl;
	}

	return 0;
}

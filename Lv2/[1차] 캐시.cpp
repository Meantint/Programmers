#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
        int answer = 0;

        if (cacheSize == 0) {
                return cities.size() * 5;
        }

        for (int i = 0; i < cities.size(); ++i) {
                for (int j = 0; j < cities[i].size(); ++j) {
                        if (cities[i][j] >= 'A' && cities[i][j] <= 'Z') {
                                cities[i][j] += 32;
                        }
                }
        }
        vector<string> vec(0);
        for (int i = 0; i < cities.size(); ++i) {
                bool check = false;

                for (int j = 0; j < vec.size(); ++j) {
                        if (vec[j] == cities[i]) { // cache hit
                                check = true;
                                answer++;
                                for (int k = j; k < vec.size() - 1; ++k) {
                                        vec[k] = vec[k + 1];
                                }
                                vec[vec.size() - 1] = cities[i];
                                break;
                        }
                }
                if (check == false) { // cache miss
                        answer += 5;
                        if (vec.size() < cacheSize) { // 가특 차있지 않을 때
                                vec.push_back(cities[i]);
                        }
                        else { // 가득 차있을 때
                                for (int i = 0; i < cacheSize - 1; ++i) {
                                        vec[i] = vec[i + 1];
                                }
                                vec[cacheSize - 1] = cities[i];
                        }
                }
        }

        return answer;
}

int main()
{
        cout << solution(3, { "1", "2", "3", "4", "5", "1", "2", "3", "4", "5" }) << endl;

        return 0;
}

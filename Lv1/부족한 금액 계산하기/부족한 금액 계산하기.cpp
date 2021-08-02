using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = (long long)(((1 + count) * count) / 2) * (long long)price - (long long)money;

    return (answer < 0 ? 0 : answer);
}
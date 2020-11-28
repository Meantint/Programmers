using namespace std;

int gcd(int a, int b)
{
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a % b == 0) {
        return b;
    }
    // 재귀
    else {
        return gcd(b, a % b);
    }
}

long long solution(int w, int h)
{
    long long answer = 1;

    int g = gcd(w, h);
    answer = (long long)w * (long long)h - (long long)(w + h - g);

    return answer;
}
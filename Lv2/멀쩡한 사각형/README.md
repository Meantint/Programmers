# 프로그래머스 - 멀쩡한 사각형

&nbsp;가로 길이 + 세로 길이 - (가로 길이와 세로 길이의 최대공약수)가 안 멀쩡한 사각형의 개수인 것을 알아야 풀 수 있다.

- Programmers - [멀쩡한 사각형](https://programmers.co.kr/learn/courses/30/lessons/62048)

- My Programmers Code : [https://github.com/Meantint/Programmers](https://github.com/Meantint/Programmers)

## 풀이

- `a`와 `b`의 최대공약수를 구해주는 함수 `gcd`를 만든다.

- `w + h - gcd(w, h)`가 멀쩡하지 않은 사각형의 개수이므로 전체 개수 `w * h`에서 빼준다.

- `w`와 `h`가 `int` 타입 변수이기 때문에 형 변환을 해줘야 한다.

## Code

```cpp
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
```

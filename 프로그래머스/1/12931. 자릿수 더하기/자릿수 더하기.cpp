#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    while(n>0) //n이 0보다 클때 반복을 한다
    {
        answer += n%10; // 10으로 나눴을때 남는 나머지를 계속 더한다
        n /= 10;
    }
    return answer;
}
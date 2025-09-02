#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int y = x;
    
    while(x > 0)  //자릿수 합 구하기
    {
         sum += x % 10;
        x /= 10;
    }
    
    if(y % sum == 0)
    {
        answer = true;
    
    }
    else
    {
        answer = false;
    
    }
        return answer;
}
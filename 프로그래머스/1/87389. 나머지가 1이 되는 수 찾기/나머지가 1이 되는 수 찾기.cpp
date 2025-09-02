#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
     int y = n;
    
    for(int x = 1; x <= n; x++) // x는 1, x는 n보다 같거나 작을때, x 는 1 씩 증가
    {
        if(n % x == 1) // n 나누기 x 를 했을때 나머지가 1인 정수
        {
            answer = x; 
            return answer;
        }
        
    }
    
}
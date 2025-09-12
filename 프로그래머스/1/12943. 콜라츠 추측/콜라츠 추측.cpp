#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int count = 0;
    
    while(n != 1) // num 이 1이 아닐때 반복
    {    
        if(count >= 500) //count가 500보다 크다면
        {
            return -1;
        }
        
        if ( n % 2 == 0) //짝수일때
        {
            n /= 2;
        }
        else //홀수일때
        {
            n = n * 3 + 1;
            
        }
        
        count++;       
     
    }
    
    return count;
}
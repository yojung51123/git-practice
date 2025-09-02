#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
  
    for(int i = 1; i <= n; i++) // i 는 1 , i 는 n 보다 작거나 같을때, i는 1씩증가
   {
       if(n % i == 0) // n / i 한 나머지가 0 일때 
       {   
        answer += i; // answer에 누적하면서 i 더하기
       }  
    }
    
    return answer;
}
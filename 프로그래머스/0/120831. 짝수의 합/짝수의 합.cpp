#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
     
    
   for (int num1 = 1;num1 <= n;num1++) //num1이 n보다 작을때 반복한다
    {
        if(num1 % 2 == 0) // n을 2로 나눴을때 나머지가 0
        {
              answer += num1; //답을 반환해라
        }
        
    }
 
 
    return answer;
}
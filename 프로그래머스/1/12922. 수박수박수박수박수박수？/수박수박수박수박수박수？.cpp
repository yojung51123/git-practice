#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
 
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0) //짝수
        {
            answer += "박";
        }
        else // 홀수
        {
            answer += "수";
        }
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int num = phone_number.size();
    
    for(int i = 0; i < num; i++)
    {
        if( i < num - 4 ) // 4자리가 아닐때
        {
             answer += "*";  
        }
        else
        {
           answer += phone_number[i]; 
        }
    }
    return answer;
}
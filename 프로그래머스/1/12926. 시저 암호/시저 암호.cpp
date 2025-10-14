#include <string>
#include <vector>
#include <cctype> //isupper

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(char Password : s)
    {
        if(isalpha(Password)) //s가 알파벳일때
        {
            char base = isupper(Password) ? 'A' : 'a'; //대소문자인지 확인
            answer += (Password - base + n) %26 + base;
        }
        else //공백일때
        {
            answer += Password;
        }
    }
    return answer;
}
#include <string>
#include <vector>
#include <cctype> //헤더

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(index % 2 == 0) //짝수
        {
            answer += (char)toupper(s[i]);
            index++;
        }
        else
        {
            answer += (char)tolower(s[i]);
            index++;
        }
        if(s[i] == ' ') //공백
        {
            index = 0;
        }
    }
    return answer;
}
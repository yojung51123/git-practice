#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    //참이면 양수
    
    for(int i = 0; i < absolutes.size(); i++)
    {
        if(signs[i]) //true 라면
        {
            answer += absolutes[i];
        }
        else //false
        {
            answer -= absolutes[i];
        }
    }
    
    return answer;
}
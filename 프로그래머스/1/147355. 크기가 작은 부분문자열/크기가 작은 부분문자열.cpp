#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long num2 = stoll(p);//숫자로 변환
    
    
    for(int i = 0; i + p.size() <= t.size(); i++) // i + p.size() 의 값이 t.size()보다 작거나 같게
    {
        string str(t.begin() + i, t.begin() + i + p.size());
        long long num1 = stoll(str);
        
        //값이 p보다 작거나 같으면 answer++
        if(num1 <= num2)
        {
            answer++;
        }
    }
   
 
    return answer;
}
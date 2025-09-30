#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
  
    vector<int>vec;
    
    while(n > 0)
    {
        vec.push_back(n % 3); // 나머지 저장
        n /= 3; // 3진법
    }
    
    for(int sam : vec)
    {
        answer = answer * 3 + sam;
    }
    
    
    
    return answer;
}
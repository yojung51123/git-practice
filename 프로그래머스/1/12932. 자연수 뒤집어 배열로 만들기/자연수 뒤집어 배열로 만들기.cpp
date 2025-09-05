#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while(n > 0)
    {    
       answer.push_back(n % 10); //나머지 벡터에 추가하기 
       n /= 10;
        
    }

    return answer;
}
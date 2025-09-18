#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    vector<int>l;

    for(int i = left; i <= right; i++) //left~right까지 반복
    {
        for(int j = 1; j <= i; j++) // left까지
        {
            if(i % j == 0) // 약수라면
            {
                l.push_back(j);
            }
        }
        
        if(l.size() % 2 == 0) //짝수
        {
        answer += i;
        }
        else
        {
        answer -= i;
        }
        l.clear();
    }
    
    return answer;
}
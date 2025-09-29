#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
 
    
    for(int i = 0; i < number.size(); i++) // 학생1
    {
       for(int j = i + 1; j < number.size(); j++) // 학생2
       {
           for(int k = j + 1; k < number.size(); k++) // 학생3
           {
                if(number[i] + number[j] + number[k] == 0)
                {
                    answer++;
                } 
           }
         
       }
        
    }
    return answer;
}
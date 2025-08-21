#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) 
{
    int i = 0;
    double sum = 0;
    double answer = 0;
    int* p = &numbers[0];
  
    for(i = 0;i < numbers.size(); i++) // 배열 길이 보다 작을때 .size() : ~의 
    {
    sum += *(p + i); // sum에 배열의 인덱스 0번째  값부터 계속 더한다 
    }
    answer = sum / i; // sum / i
    
    return answer;
    
}
#include <string>
#include <vector>
#include <climits> //INT_MAX 사용시 필요헤더

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int a = INT_MAX;
    int b = 0;
   for(int i = 0; i < arr.size(); i++)
   {
       if(a > arr[i]) // 작다면
       {
           a = arr[i]; // 값 복사
           b = i; // i인덱스 복사
       }
   }
    arr.erase(arr.begin() + b); // 해당 인덱스 위치 삭제
    
    if(arr.empty())
    {
        answer.push_back(-1);
    }
    else
    {
        return arr;
    }
    
    
    return answer;
}
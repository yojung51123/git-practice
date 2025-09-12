#include <string>
#include <vector>
#include <algorithm> //sort 함수

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int>vec;
 
    while( n > 0)
    {
        vec.push_back(n % 10);
       n = n / 10;
    }
    
    sort(vec.begin(), vec.end(), greater<int>()); //내림차순 , 크기비교
    
    for(int a: vec)
        answer = answer * 10 + a; // 자릿수 만들기 
    return answer;
}
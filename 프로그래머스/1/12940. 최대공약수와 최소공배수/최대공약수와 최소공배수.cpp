#include <string>
#include <vector>
#include <numeric> // 함수 사용 필요헤더

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
        answer.push_back(gcd(n, m)); // 최대공약수
        answer.push_back(lcm(n, m)); //최소공배수 
   
    return answer;
}
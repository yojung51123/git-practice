#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    float num3 = 0.0f;
    float num4 = 0.0f;
    
    num3 = num1;
    num4 = num2;
    
    answer = (num3 / num4) * 1000;
    
    return answer;
}
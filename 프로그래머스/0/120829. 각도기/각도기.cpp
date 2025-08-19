#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    if (angle > 0)
    {
        if (angle < 90) // 예각 1
        {
            answer = 1;
        }
        else if (angle == 90) // 직각 2
        {
            answer = 2;
        }
        else if (angle < 180) // 둔각 3
        {
            answer = 3;
        }
        else {
            answer = 4; // 평각 4
        }
    }
    return answer;
}
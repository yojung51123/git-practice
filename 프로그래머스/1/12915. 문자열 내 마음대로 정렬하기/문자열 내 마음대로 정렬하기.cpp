#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {

    sort(strings.begin(),strings.end(), [n](const string &a, const string &b) //람다함수로 n 을 사용
    {
        if(a[n] == b[n])
        {
            return a < b; // 문자열 순서 비교
        }
        return a[n] < b[n]; // n번째 문자로 순서 비교
          
    });
    

    return strings;
}
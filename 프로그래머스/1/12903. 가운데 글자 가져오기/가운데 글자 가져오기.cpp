#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<char>vec;
    
    for(int i = 0; i < s.size(); i++)
    {
        vec.push_back(s[i]);
    }
    
    while(vec.size() >= 3)
    {
        vec.erase(vec.begin());
        vec.erase(vec.end()-1); 
    }
    
    for(int j = 0; j < vec.size(); j++)
    {
        answer += vec[j];
    }
    return answer;
}
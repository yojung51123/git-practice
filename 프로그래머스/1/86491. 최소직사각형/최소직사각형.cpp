#include <string>
#include <vector>
#include <algorithm> // 크기비교

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int MaxWidth = 0;  // 최대 가로
    int MaxHeight = 0; 
    
    for(int i = 0; i < sizes.size(); i++)
    {
        int Width = max(sizes[i][0],sizes[i][1]); //가로
        int Height = min(sizes[i][0],sizes[i][1]); //세로
        
        MaxWidth = max(Width, MaxWidth);
        MaxHeight = max(Height, MaxHeight);
    }
 
    answer = MaxWidth * MaxHeight;
    return answer;
}
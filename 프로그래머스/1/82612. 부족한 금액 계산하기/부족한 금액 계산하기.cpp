using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    long long price1 = 0;
    long long money1 = 0;
    
    for(int i = 1; i <= count ;i++)
    {
        price1 += price * i; // 가격 * 횟수 만큼 반복해서 더한다
    }
    
    money1 = money - price1; // 20-80
    
    if(money1 >= 0) // 돈이 부족하지 않다면
    {
        answer = 0;
    }
    else if(money1 < 0) //부족하다면
    {
        price1 = price1 - money;
        answer = price1;
    }

    return answer;
}
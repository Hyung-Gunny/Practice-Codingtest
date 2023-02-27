#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    int lefthand = 10;//왼손의 위치를 지정하여준다
    int righthand = 12;//오른손의 위치를 지정하여준다

    for (int i = 0; i < numbers.size(); i++)//반복문을 사용하여 
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)//만약 배열의 넘버가 1,4,7이라면 
        {
            answer += "L";//왼손으로 번호를 누른다
            lefthand = numbers[i];//그 후 왼손의 위치를 지정하여준다
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)//만약 배열의 넘버가 3,6,9라면
        {
            answer += "R";//오른손으로 번호를 누른다
            righthand = numbers[i];//그 후 오른손의 위치를 지정하여 준다.
        }

        else//넘버가 1,3,4,6,7,9가 아니라면
        {
            if (numbers[i] == 0)//우선 0번의 위치를 지정하여 준다
                numbers[i] = 11;

            //그 후 넘버가 2,5,8,0이면 그 값들이 위치 이동 값들을 계산하여 준다.
            int leftlen = abs(numbers[i] - lefthand) / 3 + abs(numbers[i] - lefthand) % 3;
            int rightlen = abs(numbers[i] - righthand) / 3 + abs(numbers[i] - righthand) % 3;

            if (leftlen < rightlen)//만약 오른쪽 길이가 왼쪽 길이보다 길다면
            {
                answer += "L";//왼손으로 키패드를 누른다
                lefthand = numbers[i];//그 후 왼손의 위치를 지정하여 준다.

            }
            else if (rightlen < leftlen)//만약 왼쪽 길이가 오른쪽 길이보다 길다면
            {
                answer += "R";//오른손으로 키패드를 누른다
                righthand = numbers[i];//그 후 오른손의 위치를 지정하여 준다.
            }
            else//그 후
            {
                if (hand == "left")//만약 손이 왼손이라면
                {
                    answer += "L";//왼손으로 키패드를 누른다
                    lefthand = numbers[i];//그 후 왼손의 위치를 지정하여 준다
                }
                else//아니라면
                {
                    answer += "R";//오른손으로 키패드를 누른다
                    righthand = numbers[i];//그 후 오른손으로 위치를 지정하여 준다.
                }
            }
        }
    }



    return answer;
}
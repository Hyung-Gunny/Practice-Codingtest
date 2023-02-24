#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;
    long long sum = 0;
    long long q1sum = 0;
    long long q2sum = 0;
    int q1start = 0;
    int q2start = 0;


    for (int i = 0; i < queue1.size(); i++)
    {
        sum += queue1[i];//값들을 넣어준다
        sum += queue2[i];//값들을 넣어준다.

        q1sum += queue1[i];//큐1의 합을 만들어준다
        q2sum += queue2[i];//큐2의 합을 만들어준다
    }

    if ((sum % 2) == 1)//홀수면 원소합을 같게 만들 수 없기 때문에 
        return -1;//-1을 반환한다
    int size = queue1.size() * 4;//처음으로 돌아간다
    while (1)
    {
        if (answer > size)//만약 answer가 처음사이즈와 같다면
            break;//멈춘다.

        if (q1sum > q2sum)//만약 큐1의 합이 큐2의 합보다 크다면
        {
            q1sum -= queue1[q1start];//큐의 첫번째 스택을 빼준다
            q2sum += queue1[q1start];//큐1의 스택의 첫번째를 큐2의 넣어준다
            queue2.push_back(queue1[q1start]);//그 후 push_back을 사용하여 배열 끝에 값을 추가 시켜준다
            q1start++;//과정 후에 값을 1 증가 시킨다
        }

        else if (q1sum < q2sum)//만약 큐1의 합이 큐2의 합보다 작다면
        {//위의 방법과 동일하게 진행하여준다.-대신 큐1이 아닌 큐2로 진행하여 준다.-
            q2sum -= queue2[q2start];
            q1sum += queue2[q2start];
            queue1.push_back(queue2[q2start]);
            q2start++;
        }
        else//만약 큐의 합들이 같다면 
            return answer;//답을 출력하여준다
        answer++;//답을 계속하여 증가시켜준다
    }




    return -1;
}
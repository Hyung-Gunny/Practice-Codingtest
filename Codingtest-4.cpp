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
        sum += queue1[i];//������ �־��ش�
        sum += queue2[i];//������ �־��ش�.

        q1sum += queue1[i];//ť1�� ���� ������ش�
        q2sum += queue2[i];//ť2�� ���� ������ش�
    }

    if ((sum % 2) == 1)//Ȧ���� �������� ���� ���� �� ���� ������ 
        return -1;//-1�� ��ȯ�Ѵ�
    int size = queue1.size() * 4;//ó������ ���ư���
    while (1)
    {
        if (answer > size)//���� answer�� ó��������� ���ٸ�
            break;//�����.

        if (q1sum > q2sum)//���� ť1�� ���� ť2�� �պ��� ũ�ٸ�
        {
            q1sum -= queue1[q1start];//ť�� ù��° ������ ���ش�
            q2sum += queue1[q1start];//ť1�� ������ ù��°�� ť2�� �־��ش�
            queue2.push_back(queue1[q1start]);//�� �� push_back�� ����Ͽ� �迭 ���� ���� �߰� �����ش�
            q1start++;//���� �Ŀ� ���� 1 ���� ��Ų��
        }

        else if (q1sum < q2sum)//���� ť1�� ���� ť2�� �պ��� �۴ٸ�
        {//���� ����� �����ϰ� �����Ͽ��ش�.-��� ť1�� �ƴ� ť2�� �����Ͽ� �ش�.-
            q2sum -= queue2[q2start];
            q1sum += queue2[q2start];
            queue1.push_back(queue2[q2start]);
            q2start++;
        }
        else//���� ť�� �յ��� ���ٸ� 
            return answer;//���� ����Ͽ��ش�
        answer++;//���� ����Ͽ� ���������ش�
    }




    return -1;
}
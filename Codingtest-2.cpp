#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int denum1, int num1, int denum2, int num2)
{
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(1);//�����Ҵ��� �����ش�.(�迭�� �����ؾ��ϱ� �����̴�.)
    int num3 = 1;//���� ����

    for (int i = 1; i <= (denum1 * num2 + denum2 * num1); i++)//�ݺ����� ����Ͽ� �и��� �ִ������� �����ش�
    {
        if ((denum1 * num2 + denum2 * num1) % i == 0 && (num1 * num2) % i == 0)//�ִ������� ���� ��
        {
            num3 = i;//�������ٰ� �ִ������� �־��ش�
        }
    }

    answer[0] = (denum1 * num2 + denum2 * num1) / num3;//�迭�� ���� ���� �ִ´�
    answer[1] = (num1 * num2) / num3;//�迭�� �и� ���� �ִ´�.

    return answer;
}
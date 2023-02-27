#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = "";

    int lefthand = 10;//�޼��� ��ġ�� �����Ͽ��ش�
    int righthand = 12;//�������� ��ġ�� �����Ͽ��ش�

    for (int i = 0; i < numbers.size(); i++)//�ݺ����� ����Ͽ� 
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)//���� �迭�� �ѹ��� 1,4,7�̶�� 
        {
            answer += "L";//�޼����� ��ȣ�� ������
            lefthand = numbers[i];//�� �� �޼��� ��ġ�� �����Ͽ��ش�
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)//���� �迭�� �ѹ��� 3,6,9���
        {
            answer += "R";//���������� ��ȣ�� ������
            righthand = numbers[i];//�� �� �������� ��ġ�� �����Ͽ� �ش�.
        }

        else//�ѹ��� 1,3,4,6,7,9�� �ƴ϶��
        {
            if (numbers[i] == 0)//�켱 0���� ��ġ�� �����Ͽ� �ش�
                numbers[i] = 11;

            //�� �� �ѹ��� 2,5,8,0�̸� �� ������ ��ġ �̵� ������ ����Ͽ� �ش�.
            int leftlen = abs(numbers[i] - lefthand) / 3 + abs(numbers[i] - lefthand) % 3;
            int rightlen = abs(numbers[i] - righthand) / 3 + abs(numbers[i] - righthand) % 3;

            if (leftlen < rightlen)//���� ������ ���̰� ���� ���̺��� ��ٸ�
            {
                answer += "L";//�޼����� Ű�е带 ������
                lefthand = numbers[i];//�� �� �޼��� ��ġ�� �����Ͽ� �ش�.

            }
            else if (rightlen < leftlen)//���� ���� ���̰� ������ ���̺��� ��ٸ�
            {
                answer += "R";//���������� Ű�е带 ������
                righthand = numbers[i];//�� �� �������� ��ġ�� �����Ͽ� �ش�.
            }
            else//�� ��
            {
                if (hand == "left")//���� ���� �޼��̶��
                {
                    answer += "L";//�޼����� Ű�е带 ������
                    lefthand = numbers[i];//�� �� �޼��� ��ġ�� �����Ͽ� �ش�
                }
                else//�ƴ϶��
                {
                    answer += "R";//���������� Ű�е带 ������
                    righthand = numbers[i];//�� �� ���������� ��ġ�� �����Ͽ� �ش�.
                }
            }
        }
    }



    return answer;
}
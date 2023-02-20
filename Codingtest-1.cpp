#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> stack;//������ �����Ͽ��ش�

    for (int i = 0; i < moves.size(); i++)//�ݺ����� �̿��Ͽ�
    {
        int c = moves[i] - 1;//moves�迭�� �ִ� ������ üũ�ؾ��Ѵ�
        for (int j = 0; j < board.size(); j++)//���� �����ŭ �ݺ����� ����Ͽ�
        {
            if (board[j][c] != 0)//�迭 �ȿ� 0�� ������ �Ǵ��Ѵ�
            {
                if (!stack.empty() && stack.top() == board[j][c])//������ top�� �־�� �ϴ� ������ ���� ��� ���� �ʰ�
                {
                    stack.pop();//���ÿ� �����͸� �����ϰ�
                    answer += 2;//2�� ������Ų��.

                }
                else//�ƴ϶��
                    stack.push(board[j][c]);//�����͸� �׾��ش�
                board[j][c] = 0;//�ش���ǥ�� 0���� ������ش�
                break;//�� ���� �ȵ��ٸ� break�����ش�
            }
        }
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "fail";//�ƹ��͵� ���� �ʴ� ��� ���и� ����Ͽ��ش�.

    for (int i = 0; i < db.size(); i++)//�ݺ����� ����Ͽ� db�� �迭��ŭ �ݺ� �����ش�
    {
        if (id_pw[0] == db[i][0])//���̵�� �迭�� �ִ� ���̵� ��ġ�Ѵٸ�
        {
            if (id_pw[1] == db[i][1])//�׸��� ��й�ȣ�� �迭�� �ִ� ���̴ٿ� ��ġ�ϴٸ�
                answer = "login";//�α��� �Ѵ�
            else//��й�ȣ�� ���� �ʴٸ�
                answer = "wrong pw";//��й�ȣ�� �� ���Ǿ��ٰ� ����Ѵ�
        }
    }

    return answer;
}
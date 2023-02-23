#include <string>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    string answer = "fail";//아무것도 맞지 않는 경우 실패를 출력하여준다.

    for (int i = 0; i < db.size(); i++)//반복문을 사용하여 db의 배열만큼 반복 시켜준다
    {
        if (id_pw[0] == db[i][0])//아이디와 배열의 있는 아이디가 일치한다면
        {
            if (id_pw[1] == db[i][1])//그리고 비밀번호가 배열의 있는 아이다와 일치하다면
                answer = "login";//로그인 한다
            else//비밀번호가 같지 않다면
                answer = "wrong pw";//비밀번호가 잘 못되었다고 출력한다
        }
    }

    return answer;
}
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> stack;//스택을 생성하여준다

    for (int i = 0; i < moves.size(); i++)//반복문을 이용하여
    {
        int c = moves[i] - 1;//moves배열의 있는 인형을 체크해야한다
        for (int j = 0; j < board.size(); j++)//보드 사이즈만큼 반복문을 사용하여
        {
            if (board[j][c] != 0)//배열 안에 0과 같은지 판단한다
            {
                if (!stack.empty() && stack.top() == board[j][c])//스택의 top과 넣어야 하는 인형이 같은 경우 넣지 않고
                {
                    stack.pop();//스택에 데이터를 삭제하고
                    answer += 2;//2를 증가시킨다.

                }
                else//아니라면
                    stack.push(board[j][c]);//데이터를 쌓아준다
                board[j][c] = 0;//해당좌표를 0으로 만들어준다
                break;//더 깊이 안들어간다면 break시켜준다
            }
        }
    }

    return answer;
}
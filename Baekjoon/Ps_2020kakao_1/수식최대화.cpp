#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
/*대안
    1. 그냥 숫자, 연산자 분리해서 우선순위별로 따로따로 계산하기
    2. 후순위로 변환후 계산(지금건 변환과 계산이 동시에 진행됨)
*/
using namespace std;
/*6가지 경우 In Priority[3]
    0:* 1:+ 2:-
    0:* 1:- 2:+
    0:+ 1:* 2:-
    0:+ 1:- 2:*
    0:- 1:* 2:+
    0:- 1:+ 2:*
*/
int Priority[6][3] =
{
    {'*','+','-'},
    {'*','-','+'},
    {'+','*','-'},
    {'+','-','*'},
    {'-','*','+'},
    {'-','+','*'}
};


long long sum(long long a, long long b, char op)
{
    if (op == '+')
    {
        return a + b;
    }
    if (op == '-')
    {
        return b - a;
    }
    if (op == '*')
    {
        return a * b;
    }
    return -1;
}

long long calculate(vector<long long> expression, int p_idx)
{
    vector<long long> nums;
    vector<int> ops;
    int i = 0;
    long long result;
    long long num1, num2;
    char op;

    while (i < expression.capacity())
    {
        if (expression[i] > 47)
        {
            nums.push_back(expression[i++]-47);
        }
        else
        {
            if (ops.size() == 0)
            {
                ops.push_back(expression[i++]);
            }
            else
            {
                while (true) 
                {
                    if (ops.size() == 0) 
                    {
                        ops.push_back(expression[i++]);
                        break;
                    }
                    else if (ops.back() == Priority[p_idx][0])
                    {
                        num1 = nums.back();
                        nums.pop_back();
                        num2 = nums.back();
                        nums.pop_back();
                        op = ops.back();
                        ops.pop_back();
                        nums.push_back(sum(num1, num2, op));
                    }
                    else if (ops.back() == Priority[p_idx][1])
                    {
                        if (expression[i] != Priority[p_idx][0])
                        {
                            num1 = nums.back();
                            nums.pop_back();
                            num2 = nums.back();
                            nums.pop_back();
                            op = ops.back();
                            ops.pop_back();
                            nums.push_back(sum(num1, num2, op));   
                        }
                        else
                        {
                            ops.push_back(expression[i++]);
                            break;
                        }
                    }
                    else if (ops.back() == Priority[p_idx][2])
                    {
                        if (expression[i] != Priority[p_idx][2])
                        {
                            ops.push_back(expression[i++]);
                            break;
                        }
                        else
                        {
                            num1 = nums.back();
                            nums.pop_back();
                            num2 = nums.back();
                            nums.pop_back();
                            op = ops.back();
                            ops.pop_back();
                            nums.push_back(sum(num1, num2, op));    
                        }
                    }
                }
            }
        }
    }
    if (nums.size() == 1) 
    {
        result = nums.back();
        cout << nums.back() << endl;
    }
    else {
        while(nums.size() != 1) 
        {
            num1 = nums.back();
            nums.pop_back();
            num2 = nums.back();
            nums.pop_back();
            op = ops.back();
            ops.pop_back();
            nums.push_back(sum(num1, num2, op));
        }
    }
    result = nums.back();
    if (result < 0)
        result = -result;
    return result;
}


long long solution(string expression) {

    string word;
    char op;
    vector<long long> result;
    expression.erase(remove(expression.begin(), expression.end(), ' '), expression.end());
    int textLength = expression.length();
    vector<long long> _expression;
    long long answer = 0;
    int i = 0;
    word = "";

    while (i < textLength)
    {
        if (expression[i] > 47)
            word += expression[i++];
        else
        {
            op = expression[i++];
            _expression.push_back(stoll(word)+47);
            _expression.push_back(op);
            word = "";
        }
    }
    _expression.push_back(stoll(word)+47);

    for (int i = 0; i < 6; i++)
    {
        long long temp = calculate(_expression, i);
        result.push_back(temp);
    }
    answer = *max_element(result.begin(), result.end());
    return answer;
}

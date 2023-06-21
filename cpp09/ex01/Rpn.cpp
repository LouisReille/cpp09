#include "Rpn.hpp"
#include <stack>
#include <sstream>
Rpn::Rpn()
{
}

Rpn::Rpn(const Rpn &p)
{
}

Rpn &Rpn::operator=(const Rpn &p)
{
	  	return *this;
}

Rpn::~Rpn()
{
}

int Rpn::countTok(const std::string& expression)
{
    std::istringstream iss(expression);
    std::string token;
    int tok = 0;
    int n = 0;
    while (iss >> token) 
    {
	    if (token == "+" || token == "-" || token == "*" || token == "/")
		    tok++;
	else
			n++;

    }
       if (n - tok != 1)
	    return -1;
	return 0;
}
int Rpn::evaluateRPN(const std::string& expression) {

    std::istringstream iss(expression);
    std::string token;
    int tok = 0;
    int n = 0;
    while (iss >> token) 
    {
	if (isdigit(token[0])) 
	{
            operands.push(stoi(token));
        } 
	else 
	{
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } 
	    else if (token == "-") {
                result = operand1 - operand2;
            }
	    else if (token == "*") {
                result = operand1 * operand2;
            }
	    else if (token == "/") {
                result = operand1 / operand2;
            }
	    else 
                return 0;
            operands.push(result);
        }
    }
    return operands.top();
}

int Rpn::check_f_value(std::string argv)
{
	int i = 0;
	int n = 0;

	while (argv[i])
	{
		if (argv[i] == ' ')
			i++;
		if (argv[i] >= '0' && argv[i] <= '9')
			n = 1;
		if ((argv[i] == '+' || argv[i] == '-' || argv[i] == '/'
					|| argv[i] == '*' ) && n == 0)
			return -1;
		i++;
	}
	return 0;
}

int Rpn::check_error(std::string argv)
{
	for (int i = 0; argv[i]; i++)
	{
		if (isdigit(argv[i]) == false)
		{
			if (argv[i] == '+' || argv[i] == '-' || argv[i] == '/'
					|| argv[i] == '*' || argv[i] == ' ')
				continue ;
			else
				return (-1);
		}
	}
	return (0);
}


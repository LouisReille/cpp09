/*#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	int n = 1;
	int s = 1;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			i++;
		if (argv[1][i] > '0' && argv[1][i] < '9')
			n *= -1;
		if (argv[1][i] == '+' && n > 0)
			std::cout << "cant do" << std::endl;
		i++;
		
	}
}*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int evaluateRPN(const string& expression) {
    stack<int> operands;

    istringstream iss(expression);
    string token;
    while (iss >> token) {
        if (isdigit(token[0])) {
            operands.push(stoi(token));
        } else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();

            int result;
            if (token == "+") {
                result = operand1 + operand2;
            } else if (token == "-") {
                result = operand1 - operand2;
            } else if (token == "*") {
                result = operand1 * operand2;
            } else if (token == "/") {
                result = operand1 / operand2;
            } else {
                cerr << "Error: Invalid operator '" << token << "'" << endl;
                return 0;
            }

            operands.push(result);
        }
    }

    if (operands.size() != 1) {
        cerr << "Error: Invalid expression" << endl;
        return 0;
    }

    return operands.top();
}

int main(int argc, char **argv) {

    string expression = argv[1];
   // cout << "Enter an expression in Reverse Polish Notation: ";
    //getline(cin, expression);

    int result = evaluateRPN(expression);
    cout << "Result: " << result << endl;

    return 0;
}

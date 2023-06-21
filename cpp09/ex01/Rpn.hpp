#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class Rpn {

	private:
	std::stack<int>operands;

	public:
	Rpn();
	Rpn(const Rpn &p);
	Rpn &operator=(const Rpn &p);
	~Rpn();

	int countTok(const std::string &expression);
	int evaluateRPN(const std::string &rpn);
	int check_f_value(std::string argv);
	int check_error(std::string argv);
};

#endif

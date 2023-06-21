#include "Rpn.hpp"

int main(int argc, char **argv)
{

	Rpn Rpn;

	if (argc != 2)
	{
		std::cout << "Error, Wrong amount of arguments!" << std::endl;
		exit(0);
	}
	else if (Rpn.check_f_value(argv[1]) == -1)
	{
		std::cout << "Error, Should start with a number!" << std::endl;
		exit(0);
	}
	else if (Rpn.check_error(argv[1]))
	{
		std::cout << "Error, Wrong Argument!" << std::endl;
		exit(0);
	}
	else if (Rpn.countTok(argv[1]) == -1)
	{
		std::cout << "something wrong" << std::endl;
		exit (0);
	}
	std::string rpn = argv[1];
	std::cout << Rpn.evaluateRPN(rpn) << std::endl;
}

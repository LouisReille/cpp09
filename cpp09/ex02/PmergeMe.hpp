

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>

class PmergeMe
{
	private:
	std::vector<int>vector;
	std::deque<int>deque;

	public:
	PmergeMe();
	PmergeMe(const PmergeMe &p);
	PmergeMe &operator=(const PmergeMe &p);
	~PmergeMe();
	
	void insertValue(char **argv);
	void sortValue(int argc);
	int  checkError(std::string argv);
};

#endif

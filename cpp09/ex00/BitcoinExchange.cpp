#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{
}

Bitcoin::Bitcoin(const Bitcoin &p)
{
}

Bitcoin &Bitcoin::operator=(const Bitcoin &p)
{
	return *this;
}

Bitcoin::~Bitcoin()
{
}

void Bitcoin::DataBase(std::string dataBase)
{
	std::ifstream file(dataBase);
	std::string string;
	int check = 0;

	while(getline(file, string))
	{
		if (check != 0)
		{
			int pos = string.find(",");
			std::string str1 = string.substr(pos + 1);
			std::string str2 = string.substr(0, pos);
			m_DataBase.insert(make_pair(str2, std::atof(str1.c_str())));
		}
		check++;
	}
}

bool Bitcoin::isLeapYear(int year) 
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

bool Bitcoin::isValidDate(int day, int month, int year) 
{
    if (year < 1 || month < 1 || month > 12 || day < 1) 
    {

        return false;
    }

    int daysInMonth;

    if (month == 2)
    {
        daysInMonth = isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) 
    {
        daysInMonth = 30;
    } 
    else
    {
        daysInMonth = 31;
    }

    return (day <= daysInMonth);
}

int Bitcoin::Checkdate(std::string date)
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 9);

	int _year = std::atoi(year.c_str());
	int _month = std::atoi(month.c_str());
	int _day = std::atoi(day.c_str());
	if (isValidDate(_day, _month, _year))
 		return 0;
	else
		return -1;
}

void Bitcoin::Input(std::string Input)
{
	std::ifstream file(Input);
	std::string string;
	int check = 0;

	while(42)
	{
		getline(file, string);
		if (string.size() == 0)
			break ;
		if (check != 0)
		{
			int pos = string.find("|");

			std::string str1 = string.substr(pos + 2);
			std::string str2 = string.substr(0, pos - 1);

			float value = std::atof(str1.c_str());

			if (value < 0)
				std::cout << "Error: not a positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else if (Checkdate(str2))
				std::cout << "Error: bad input => " << str2 << std::endl;
			else
				std::cout << str2 << " => " << str1 << " = " << std::fixed << std::setprecision(2) << value * SearchDate(str2) << std::endl;
		}
		check++;
	}
}

float Bitcoin::SearchDate(std::string date)
{
	std::map<std::string, float>::iterator it;

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8,9);

	for(it=m_DataBase.begin(); it!=m_DataBase.end(); ++it){
		if (date == it->first)
			return (it->second);
   	}

	for(it=m_DataBase.begin();it!=m_DataBase.end();++it)
	{
		if (year == it->first.substr(0,4) && month == it->first.substr(5,2))
		{
			float float1 = std::stof(it->first.substr(8,9));
			float float2 = std::stof(day);
			if (float1 > float2)
			{
				it--;
				return (it->second);
			}
		}
	}
	return (0);
}

#include "utils.hpp"
#include <algorithm>
#include <cctype>

std::vector<std::string>	lexe(char *equation)
{
	std::vector<std::string>	tokens;
	std::string					tmp;
	
	tmp == "";
	for (int i = 0; equation[i]; i++)
	{
		if (is_sign(equation[i])) {
			tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
			if(!tmp.empty())
				tokens.push_back(tmp);
			tmp = "";
			tmp += equation[i];
		}
		else
			tmp += equation[i];
	}
	tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());
	tokens.push_back(tmp);
	return (tokens);
}

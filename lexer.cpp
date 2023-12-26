#include "utils.hpp"

std::vector<std::string>	lexe(char *equation)
{
	std::vector<std::string>	tokens;
	std::string					tmp;
	
	tmp == "";
	for (int i = 0; equation[i]; i++)
	{
		if (is_sign(equation[i])) {
			if(!tmp.empty())
				tokens.push_back(tmp);
			tmp = "";
			tmp += equation[i];
		}
		else
			tmp += equation[i];
	}
	tokens.push_back(tmp);
	return (tokens);
}

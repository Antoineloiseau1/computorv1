#include "lexer.hpp"
#include "Term.hpp"
#include "utils.hpp"

std::vector<Term> parse(char *equation) 
{
	std::vector<std::string> 			tokens = lexe(equation);
	std::vector<std::string>::iterator	it;
	std::vector<Term>					terms;
	bool								equal = false;

	for(it = tokens.begin(); it != tokens.end(); it++) {
		if((*it).find("=") != std::string::npos)
		{
			(*it).erase((*it).find("="), 1);
			equal = true;
		}
		terms.push_back(Term(*it, equal));
	}
	return terms;
}	

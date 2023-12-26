#ifndef TERM_HPP
# define TERM_HPP

# include <iostream>

class Term {


		public:

		int		exponent;
		float	coefficient;
		bool 	isRhs;
		
		
		Term(std::string token, bool rhs);
		~Term(void);
		
};

std::ostream &operator<<(std::ostream &out, Term &term);

#endif

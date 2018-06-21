
#include	<iostream>
#include	<sstream>
#include	<string>
#include	<cstdlib>
#include	"Fixed.hpp"

Fixed	eval(std::istringstream & str_in)
{
	float				f;
	Fixed				left;
	std::string			s;

	while (!str_in.eof() && str_in >> s)
	{
		if (s[0] == '(')
			left = eval(str_in);
		else if (s[0] == ')')
			return left;
		else if (std::isalnum(s[0]))
		{
			std::istringstream	flt_in(s);
			flt_in >> f;
			left = Fixed(f);
		}
		else if (s[0] == '+')
			left = left + eval(str_in);
		else if (s[0] == '-')
			left = left - eval(str_in);
		else if (s[0] == '*')
			left = left * eval(str_in);
		else if (s[0] == '/')
			left = left / eval(str_in);
	}
	return left;
}

int		main(int argc, char **argv)
{
	std::string			str(argv[argc - 1]);
	std::istringstream	str_in(str);

	std::cout << eval(str_in) << std::endl;
}
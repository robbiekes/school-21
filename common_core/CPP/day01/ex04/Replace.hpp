#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

class Replace
{
	std::string filename;
	std::string s1;
	std::string s2;
public:
	Replace();
	Replace(std::string &filename, std::string &s1, std::string &s2);
	~Replace();

	void rewrite();
	void replace_line(std::string &line);
};

#endif
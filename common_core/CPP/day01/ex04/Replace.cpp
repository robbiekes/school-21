#include "Replace.hpp"

Replace::Replace() : filename(""), s1(""), s2("") {};
Replace::~Replace() {}
Replace::Replace(std::string &filename, std::string &s1, std::string &s2) : filename(filename), s1(s1), s2(s2) {}

void Replace::replace_line(std::string &str)
{
	std::string::size_type start = str.find(s1);
	while (start != std::string::npos)
	{
		str.erase(start, s1.length());
		str.insert(start, s2);
		start = str.find(s1);
	}
}

void Replace::rewrite()
{
	std::ifstream inStream(filename);
	std::string line, tmpBuf;
	if (inStream.is_open())
    {
		while (getline(inStream, line))
		{
			replace_line(line);
			tmpBuf.append(line);
			tmpBuf.append("\n");
		}
    }
	else
		std::cout << "Could not access file." << std::endl;
	std::ofstream outStream;
	outStream.open(filename.append(".replace"), std::ios::out);
	if (outStream.is_open())
    {
		outStream << tmpBuf;
		inStream.close();
		outStream.close();
    }
    else
		std::cout << "Could not open file." << std::endl;
}

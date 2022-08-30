#include <iostream>
#include <fstream>

void	filehandler(std::ifstream& in, std::ofstream& out, char **argv)
{
	in.open(argv[1]);
	if (!in.good())
	{
		std::cerr << argv[0] << ": bad input file" << std::endl;
		exit(1);
	}
	out.open(std::string(argv[1]) + ".replace");
	if (!out.good())
	{
		in.close();
		std::cerr << argv[0] << ": bad output file" << std::endl;
		exit(1);
	}
}

void	lineWriter(std::ofstream& out, std::string const & buf, std::string const & ref, std::string const & rep)
{
	std::size_t		oldpos = 0;
	std::size_t		pos = 0;

	while (pos < buf.length())
	{
		oldpos = pos;
		pos = buf.find(ref, pos);
		out << buf.substr(oldpos, pos - oldpos);
		if (pos == std::string::npos)
			break ;
		pos += rep.length();
		out << rep;
	}
}

void	writer(std::ifstream& in, std::ofstream& out, char **argv)
{
	std::string		buf;
	std::string		s1;
	std::string		s2;

	s1 = std::string(argv[2]);
	s2 = std::string(argv[3]);
	std::getline(in, buf);
	lineWriter(out, buf, s1, s2);
	while (!in.eof())
	{
		out << std::endl;
		std::getline(in, buf);
		lineWriter(out, buf, s1, s2);
	}
}

int	main(int argc, char **argv)
{
	std::ifstream	in;
	std::ofstream	out;

	if (argc != 4)
	{
		std::cout << argv[0] << ": usage: [filename], [string1], [string2]" << std::endl;
		return (0);
	}
	filehandler(in, out, argv);
	writer(in, out, argv);
	in.close();
	out.close();
	return (0);
}

#include <iostream>
#include <string>

int	floatAndDoubleHandler(std::string & buf, bool isNan)
{
	if (isNan)
	{
		
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::string	buf;
	bool		isNan = false;

	if (argc != 2)
	{
		std::cout << *argv << ": only 2 args allowed" << std::endl;
		return (0);
	}

	buf = static_cast<std::string>(*(++argv));
	if (buf.find('.') != std::string::npos
		|| (buf.find("nan", 0) != std::string::npos && (isNan = true)))
		return (floatAndDoubleHandler(buf, isNan));
	std::cout << buf << std::endl;
	return (0);
}
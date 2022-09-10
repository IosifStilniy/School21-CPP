#include <iostream>

struct Data {
	float	a;
	int		b;
	char	c;
	double	e;
};

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main(void)
{
	Data		puk;

	std::cout << "origin: " << &puk << std::endl;
	std::cout << "deserialized: " << deserialize(serialize(&puk)) << std::endl;
}
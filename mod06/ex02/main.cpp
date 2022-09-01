#include <iostream>
#include <random>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base *	generate(void)
{
	std::random_device	rd;

	switch (rd() % 3)
	{
		case 0:
			std::cout << "A" << std::endl;
			return (new A());

		case 1:
			std::cout << "B" << std::endl;
			return (new B());

		case 2:
			std::cout << "C" << std::endl;
			return (new C());
	}

	return (new A());
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

int	main(void)
{
	Base*	rnd;

	rnd = generate();
	identify(rnd);
	identify(*rnd);
	return (0);
}
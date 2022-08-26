#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	int const static	_numFract = 8;

public:
	Fixed(/* args */);
	~Fixed();

	int		getRawBits(void)			const;
	void	setRawBits(int const raw);
};

#endif

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;

	static int const	_numFract;

public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed();

	Fixed &	operator=(Fixed const & src);
	
	int		getRawBits(void)			const;
	void	setRawBits(int const raw);
	float	toFloat(void)				const;
	int		toInt(void)					const;
	
	static int	getNumFract(void);
};

std::ostream & operator<<(std::ostream & out, Fixed const & fpnum);

#endif

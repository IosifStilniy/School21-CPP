#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_value;
	int const static	_numFract;

public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed();

	Fixed &	operator=(Fixed const & src);
	
	int		getRawBits(void)			const;
	void	setRawBits(int const raw);
};

#endif

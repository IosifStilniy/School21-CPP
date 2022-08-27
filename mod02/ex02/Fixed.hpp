#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;

	static int const	_numFract;
	static int const	_fractMask;

public:
	Fixed(void);
	Fixed(Fixed const & src);
	Fixed(int const i);
	Fixed(float const f);
	~Fixed();

	Fixed &	operator=(Fixed const & src);

	Fixed	operator+(Fixed const & rhd)	const;
	Fixed	operator-(Fixed const & rhd)	const;
	Fixed	operator*(Fixed const & rhd)	const;
	Fixed	operator/(Fixed const & rhd)	const;

	Fixed &	operator++(void);
	Fixed	operator++(int i);
	Fixed &	operator--(void);
	Fixed	operator--(int i);

	bool	operator>(Fixed const & rhd)	const;
	bool	operator>=(Fixed const & rhd)	const;
	bool	operator<(Fixed const & rhd)	const;
	bool	operator<=(Fixed const & rhd)	const;
	bool	operator==(Fixed const & rhd)	const;
	bool	operator!=(Fixed const & rhd)	const;
	
	int		getRawBits(void)			const;
	void	setRawBits(int const raw);
	float	toFloat(void)				const;
	int		toInt(void)					const;
	
	static int				getNumFract(void);
	static Fixed &			min(Fixed & n1, Fixed & n2);
	static Fixed const &	min(Fixed const & n1, Fixed const & n2);
	static Fixed &			max(Fixed & n1, Fixed & n2);
	static Fixed const &	max(Fixed const & n1, Fixed const & n2);
};

std::ostream & operator<<(std::ostream & out, Fixed const & fpnum);

#endif

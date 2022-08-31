#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>

class Converter
{
	private:
		std::string	_str;
		char		_c;
		int			_i;
		float		_f;
		double		_d;
		bool		_handled;
		bool		_possibility[4];

		bool		_checkForFloat(bool & isNan, bool & isFloat)	const;
		bool		_handleFloat(bool isNan, bool isFloat)			const;
		void		_print(void)									const;

	public:
		Converter(void);
		Converter(Converter const & src);
		~Converter();

		Converter &	operator=(Converter const & rhd);

		void	handleIt(std::string const & str);
};

#endif
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

		std::size_t	_skipSpaces(std::string const & str)		const;
		bool		_checkForFloat(bool & isNanOrInf, bool & isFloat);
		bool		_checkForInt(void);
		bool		_checkForChar(void);
		void		_handleFloat(bool isNanOrInf, bool isFloat);
		void		_handleInt(void);
		void		_handleChar(void);
		void		_print(void)						const;

	public:
		Converter(void);
		Converter(Converter const & src);
		~Converter();

		Converter &	operator=(Converter const & rhd);

		void	handleIt(std::string const & str);
};

#endif
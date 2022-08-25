#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void				_debug(void)			const;
		void				_info(void)				const;
		void				_warning(void)			const;
		void				_error(void)			const;
		void				(Harl::*_cmpl[4])(void)	const;
		
		std::string static	_levels[4];

	public:
		Harl();
		~Harl();

		void	complain(std::string level)	const;
};

#endif

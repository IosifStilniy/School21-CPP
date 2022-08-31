#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat	boris("Boris", 19);
	Bureaucrat	doris("Doris", 1);
	Bureaucrat	poris("Poris", 150);
	AForm*		f3;
	Intern 		someRandomIntern;
	AForm* rrf;

	f3 = new PresidentialPardonForm("Popuch");
	f3->beSigned(boris);
	boris.signForm(*f3);
	doris.signForm(*f3);
	boris.executeForm(*f3);
	delete f3;
	f3 = new RobotomyRequestForm("kaka");
	poris.signForm(*f3);
	doris.signForm(*f3);
	f3->execute(poris);
	delete f3;
	f3 = new ShrubberyCreationForm("ass");
	doris.executeForm(*f3);
	boris.signForm(*f3);
	poris.executeForm(*f3);
	f3->execute(poris);
	doris.executeForm(*f3);
	delete f3;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	boris.executeForm(*rrf);
	doris.signForm(*rrf);
	poris.executeForm(*rrf);
	boris.executeForm(*rrf);
	delete rrf;
	return (0);
}

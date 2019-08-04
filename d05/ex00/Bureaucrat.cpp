
#include     "Bureaucrat.hpp"


const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is Too Hig";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is Too Low";
}

Bureaucrat::Bureaucrat(): _name("-"), _grade(150){}

Bureaucrat::Bureaucrat(int grade, std::string name): _name(name), _grade(grade){}

Bureaucrat::Bureaucrat(Bureaucrat const & b)
{
    *this = b;
}


Bureaucrat &				Bureaucrat::operator=(Bureaucrat const & b)
{
    this->_grade = b._grade;

    return (*this);
}

void            Bureaucrat::isGradeHight()
{
    if (this->_grade < 1)
        throw GradeTooHighException();
}

void            Bureaucrat::isGradeLow()
{
    if (this->_grade > 150)
        throw GradeTooLowException();
}

bool            Bureaucrat::isGradeOk()
{
    this->isGradeHight();
    this->isGradeLow();
    return true;
}

std::string		Bureaucrat::getName() const
{
    return (_name);
}

short			Bureaucrat::getGrade() const
{
    return (_grade);
}

void			Bureaucrat::upgrade()
{
    this->_grade++;
}

void			Bureaucrat::downgrade()
{

}

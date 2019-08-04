/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afokin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 15:10:11 by afokin            #+#    #+#             */
/*   Updated: 2018/06/26 15:10:13 by afokin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     BUREAUCRAT_HPP
# define    BUREAUCRAT_HPP

#include    <string>
#include    <exception>

class   Bureaucrat
{
	class   GradeTooHighException: public std::exception
	{
		virtual const char * what() const throw();

		public:
			GradeTooHighException();
			~GradeTooHighException();
			GradeTooHighException(GradeTooHighException const & g);

			GradeTooHighException &			operator=(GradeTooHighException const & g);
	};

	class   GradeTooLowException: public std::exception
	{
		virtual const char * what() const throw();

		public:
			GradeTooLowException();
			~GradeTooLowException();
			GradeTooLowException(GradeTooLowException const & g);

			GradeTooLowException &			operator=(GradeTooLowException const & g);
	};

	private:
		std::string const	     _name;
		short					_grade;

		void			isGradeHight();
		void			isGradeLow();
		bool			isGradeOk();

	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(Bureaucrat const & b);
		Bureaucrat(int	grade, std::string name);

		Bureaucrat &				operator=(Bureaucrat const & b);

		std::string		getName() const;
		short			getGrade() const;

		void			upgrade();
		void			downgrade();

};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:57:39 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 09:54:34 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACT_HPP__
# define __CONTACT_HPP__

#include <iostream>
#include <iomanip>
#include <string>

typedef struct s_contact {
	int			i_;
	std::string	fname_;
	std::string	lname_;
	std::string	nname_;
	std::string	phone_;
	std::string	secret_;
}	t_contact;

class	Contact {
	public:
		/* CONSTR & DESTR */
		Contact();
		~Contact();

		/* GET & SET */
		void		setContact( int );
		void		setField( std::string *, int );
		t_contact	getContact( void ) const;
		bool		isSet;

		/* DISPLAY */
		void				displayContact( void ) const;
		static void			displayRow( std::string[4] );
		static std::string	headerRow[4];
		static std::string	emptyRow[4];
		static std::string	contactList[5];
	private:
		t_contact	data_;
};

#endif /* __CONTACT_HPP__ */

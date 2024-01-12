/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncasteln <ncasteln@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:57:39 by ncasteln          #+#    #+#             */
/*   Updated: 2024/01/12 10:03:30 by ncasteln         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();
		void		addContact( void );
		void		getAllContact( void ) const;

	private:
		static int	isValidIndex( std::string, int );
		static int	isValidZero( std::string );
		void		getContactByIndex( void ) const;
		int			i_;
		Contact		c_[8];
};

#endif /* __PHONEBOOK_HPP__ */

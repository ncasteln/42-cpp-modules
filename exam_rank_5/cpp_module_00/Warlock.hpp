#ifndef __WARLOCK_HPP__
# define __WARLOCK_HPP__

#include <string>
#include <iostream>

class Warlock
{
	public:
		~Warlock( void );
		Warlock( std::string name, std::string title );

		const std::string& getName( void ) const;
		const std::string& getTitle( void ) const;

		void setTitle( const std::string& );

		void introduce() const;
		Warlock( const Warlock& );
	private:
		std::string _name;
		std::string _title;

		Warlock( void );
		Warlock& operator=( const Warlock& );

};

#endif /* __WARLOCK_HPP__ */
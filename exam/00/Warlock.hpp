#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>

class Warlock {
	public:
		Warlock( std::string name, std::string title );
		~Warlock( void );
	
		const std::string& getName( void ) const;
		const std::string& getTitle( void ) const;
		void setTitle( std::string title ); 
	
		void introduce() const;
	private:
		std::string _name;
		std::string _title;

		Warlock( void );
		Warlock( const Warlock& );
		Warlock& operator=( const Warlock& );

};

#endif

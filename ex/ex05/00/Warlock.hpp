#pragma once

#include <iostream>

class Warlock{
	private:
		std::string _name;
		std::string _title;
		Warlock();
		Warlock(const Warlock &copy);
		Warlock &operator=(const Warlock &obj);

	public:
		Warlock(std::string name, std::string title);
		~Warlock();
		std::string getName() const;
		std::string getTitle() const;
		void setTitle(std::string const &str);
		void introduce() const;
};

#ifndef RPN_H
# define RPN_H
# include <iostream>
# include <stack>
# include <cstring>

class RPN{
	private:
        std::stack<int> _data;
	
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();

		RPN					&operator=(const RPN &obj);
		void				calc(char c);
		void				run(char *input);

};

#endif
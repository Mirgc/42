#include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(const RPN &copy){
	*this = copy;
}

RPN::~RPN(void){
}

RPN &RPN::operator=(const RPN &obj){
	if (this != &obj)
		this->_data = obj._data;
	return *this;
}

void    RPN::calc(char c){
    int num1;
	int num2;
	num2 = _data.top();
	_data.pop();
	num1 = _data.top();
	_data.pop();
	if (c == '+')
		_data.push(num1 + num2);
	else if (c == '-')
		_data.push(num1 - num2);
	else if (c == '*')
		_data.push(num1 * num2);
	else if (c == '/')
	{
		if (num2 == 0)
            std::cout << "ERROR: can't divided by 0." << std::endl;
		_data.push(num1 / num2);
	}
}

void    RPN::run(char *input){
    int len = std::strlen(input);

    for (int i = 0; len > i; i++){ 
        if (std::isdigit(input[i])){
            int dig = input[i] - '0';
            if (dig > 10){
                std::cout << "ERROR: We only accept integers under 10." << std::endl;
                return ;
            }
            _data.push(dig);
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*'){
	        if (_data.size() < 2){
                std::cout << "ERROR" << std::endl;
                return ;
            }
            calc(input[i]);
        }
        else if (input[i] != ' '){
            std::cout << "ERROR: Invalid character." << std::endl;
            return ;
        }
    }
    if (_data.size() != 1)
        std::cout << "ERROR: Invalid operations." << std::endl;
    else
        std::cout << _data.top() << std::endl;
}
#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):_amount(initial_deposit){
	(void) _amount;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std:: cout << "created" << std::endl;
	_totalAmount+=initial_deposit;
	_nbAccounts++;
}

Account::~Account(void){
	return;
}

Account::Account(){
}

int Account::getNbAccounts(){
	return(_nbAccounts);
}

int Account::getTotalAmount(){
	return(_totalAmount);
}

int Account::getNbDeposits(){
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(){
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos(){
}

void Account::_displayTimestamp(){
}

void Account::makeDeposit(int deposit){
	(void)deposit;
}

bool Account::makeWithdrawal(int withdrawal){
	(void)withdrawal;
	return 0;
}

int Account::checkAmount(void) const{
	return 0;
}

void Account::displayStatus() const{
}


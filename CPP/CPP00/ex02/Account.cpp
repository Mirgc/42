#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit){
        _amount = initial_deposit;
        _displayTimestamp();
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
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "amount:" << _amount << ";";
        std:: cout << "closed" << std::endl;
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
        _displayTimestamp();
        std::cout << "accounts:" << _nbAccounts << ";";
        std::cout << "total:" << Account::getTotalAmount() << ";";
        std::cout << "deposits:" << Account::getNbDeposits() << ";";
        std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";";
        std::cout << std::endl;
}

void Account::_displayTimestamp(){
        time_t  now = time(0);
        tm      *date = localtime(&now);

        std::cout << "[";
        std::cout << 1900 + date->tm_year;
        std::cout << std::setfill('0') << std::setw(2) << 1 + date->tm_mon;
        std::cout << std::setfill('0') << std::setw(2) << date->tm_mday;
        std::cout << "_";
        std::cout << std::setfill('0') << std::setw(2) << date->tm_hour;
        std::cout << std::setfill('0') << std::setw(2) << date->tm_min;
        std::cout << std::setfill('0') << std::setw(2) << date->tm_sec;
        std::cout << "] ";
}

void Account::makeDeposit(int deposit){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        std::cout << "deposits:" << deposit << ";";
        _amount += deposit;
        _totalAmount += deposit;
        std::cout << "amount:" << _amount << ";";
        _nbDeposits++;
        _totalNbDeposits++;
        std::cout << "nb_deposits:" << _nbDeposits << ";";
        std::cout << std::endl;
}
bool Account::makeWithdrawal(int withdrawal){
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << _amount << ";";
        std::cout << "withdrawal:";
        if (_amount < withdrawal){
                std::cout << "refused" << std::endl;
                return (false);
        }
        std::cout << withdrawal << ";";
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << "amount:" << _amount << ";";
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << "nb_withdrawals:" << _nbWithdrawals << ";";
        std::cout << std::endl;
        return (true);
}

int Account::checkAmount(void) const{
        return 0;
}

void Account::displayStatus() const{
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "amount:" << _amount << ";";
        std::cout << "deposits:" << _nbDeposits << ";";
        std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}


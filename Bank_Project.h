#pragma once
#ifndef BANK_PROJECT_H
#define BANK_PROJECT_H
#include <iostream>
#include <string>

namespace BankProject {
	class BankAccount {
	private:
		std::string accountName;
		double balance{ 0 };
		int accountNumber;
	public:
		BankAccount(std::string accountName, double balance, int accountNumber) {
			this->accountName = accountName;
			this->balance = balance;
			this->accountNumber = accountNumber;
		}
		std::string get_accountName()const {
			return accountName;
		}
		int get_accountNumber()const {
			return accountNumber;
		}
		double get_balance()const {
			return balance;
		}
		void show_account_info(const BankAccount& account) {
			std::cout << "-------------Account Information-------------" << std::endl;
			std::cout << "Account Name: " << account.get_accountName() << std::endl;
			std::cout << "Account Number: " << account.get_accountNumber() << std::endl;
			std::cout << "Balance: " << account.get_balance() << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
		}
		double deposit(double amount) {
			if (amount > 0) {
				balance += amount;
				std::cout << "Deposited: " << amount << std::endl;
			}
			std::cout << "Current Balance: " << balance << std::endl;
			return balance;
		}
		double withdraw(double amount) {
			if (amount > 0 && amount <= balance) {
				balance -= amount;
				std::cout << "Withdrawn: " << amount << std::endl;
			}
			else if (amount > balance){
				std::cout << "Insufficient funds." << std::endl;
			}
			std::cout << "Now,Your Current Balance: " << balance << std::endl;
			return balance;
		}
	};
}
#endif



			


	
			

	

		
		




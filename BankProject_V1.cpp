#include <iostream>
#include <string>
#include "Bank_Project.h"

int main() {
	std::cout << "-------------------- Welcome to the Bank Menu --------------------" << std::endl;
	std::cout << " 1. Create Account" << std::endl;
	std::cout << " 5. Exit" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "Enter your choice: ";
	int choice;
	std::cin >> choice;

	if (choice == 1) {
		std::cout << "Creating a new account..." << std::endl;
		std::cout << "Enter account name: ";
		std::string accountName;
		std::cin >> accountName;
		std::cout << "Enter initial balance: ";
		double balance;
		std::cin >> balance;
		std::cout << "Enter account number: ";
		int accountNumber;
		std::cin >> accountNumber;
		std::cout << std::endl;
		if (accountName.empty() || balance < 0 || accountNumber <= 0) {
			std::cout << "Invalid input. Please provide valid account details." << std::endl;
			return 1; // Exit the program with an error code
		}
		BankProject::BankAccount account(accountName, balance, accountNumber);
		std::cout << "Account created successfully!" << std::endl;
		std::cout << "-------------------- Welcome " << accountName << "! ------------------------" << std::endl;
		std::cout << " 2. Deposit" << std::endl;
		std::cout << " 3. Withdraw" << std::endl;
		std::cout << " 4. Show Account Information" << std::endl;
		std::cout << " 5. Exit" << std::endl;
		std::cout << "-----------------------------------------------------------" << std::endl;
		std::cout << "Enter your choice again for your account: ";
		int choice_after_created;
		std::cin >> choice_after_created;
		if (choice_after_created == 1) {
			std::cout << "You have already created an account. Please choose another option." << std::endl;
		}
		else if (choice_after_created == 5) {
			std::cout << "Thank you for using the Bank Menu. Goodbye!" << std::endl;
		}
		else if (choice_after_created < 5 && choice_after_created>1) {
			double amount;
			std::string option = "Y";
			while (option == "Y" || option == "y") {
				switch (choice_after_created) {
				case 2:
					std::cout << "Enter amount to deposit: ";
					if (!(std::cin >> amount)) {
						std::cout << "Invalid input! Please enter a number, not letters." << std::endl;
						std::cin.clear();            
						std::cin.ignore(10000, '\n'); 
					}
					else if (amount > 0) { 
						account.deposit(amount);
					}
					else {
						std::cout << "Invalid amount. Please enter a positive value." << std::endl;
					}
					break;
				case 3:
					std::cout << "Enter amount to withdraw: ";
					if(!(std::cin >> amount)){
						std::cout << "Invalid input! Please enter a number, not letters." << std::endl;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}

					else if (amount >= 0) {
						account.withdraw(amount);
					}
					else {
						std::cout << "Invalid amount. Please enter a positive value." << std::endl;
					}
					break;
				case 4:
					account.show_account_info(account);
					break;
				case 5:
					std::cout << "Thank you for using the Bank Menu. Goodbye!" << std::endl;
					return 0;
				default:
					std::cout << "Invalid choice. Please try again." << std::endl;
					break;
				}
				std::cout << "Do you want to perform another operation? (\'Y\' for yes / \'N\'for no): " << std::endl;
				std::cin >> option;
				if (option == "N" || option == "n") {
					std::cout << "Thank you for using the Bank Menu. Goodbye!" << std::endl;
					break;
				}
				else if (option == "Y" || option == "y") {
					std::cout << "-------------------- Welcome to the Bank Menu --------------------" << std::endl;
					std::cout << " 2. Deposit" << std::endl;
					std::cout << " 3. Withdraw" << std::endl;
					std::cout << " 4. Show Account Information" << std::endl;
					std::cout << " 5. Exit" << std::endl;
					std::cout << "------------------------------------------------------------------" << std::endl;
					std::cin >> choice_after_created;
				}
				else {
					std::cout << "Invalid input, Please choose appropriately. Exiting the program..." << std::endl;
					break;
				}
			}
		}
		else {
			std::cout << "Invalid input provided, Please do not enter letters. Exiting the program..." << std::endl;
		}

	}
	else if (choice == 5) {
		std::cout << "Thank you for using the Bank Menu. Goodbye!" << std::endl;

	}
	else {
		std::cout << "Invalid input, you must create an account first." << std::endl;
	}
	return 0;
}

BankProject::BankAccount create_account(std::string accountName, double balance, int accountNumber) {
	std::cout << "Enter account name: ";
	std::cin >> accountName;
	std::cout << "Enter initial balance: ";
	std::cin >> balance;
	std::cout << "Enter account number: ";
	std::cin >> accountNumber;
	BankProject::BankAccount account(accountName, balance, accountNumber);
	std::cout << "Account created successfully!" << std::endl;
	return account;
}
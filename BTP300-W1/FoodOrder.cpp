#define _CRT_SECURE_NO_WARNINGS
#include "FoodOrder.h"
#include <iostream> // Standard io
#include <fstream> // File management module
#include <string> // String module
#include <iomanip> // std::cout formatting module

double g_taxrate;
double g_dailydiscount;

namespace seneca {

	// Default Constructor
	FoodOrder::FoodOrder() {
		m_customerName[0] = '\0';
		m_foodDescription = nullptr;
		m_price = 0.0;
		m_orderSpecial = false;
	}

	// Copy Constructor
	FoodOrder::FoodOrder(const FoodOrder& in) {
        m_foodDescription = nullptr;
		*this = in;
	}

	// Copy Assignment
	FoodOrder& FoodOrder::operator=(const FoodOrder& in) {
		// 1. Self Assignment Guard
		if (this != &in) {

			// 2. Reset Memory
            delete[] m_foodDescription;
            
			// 3. Shallow Copy
			strcpy(this->m_customerName, in.m_customerName);
			m_price = in.m_price;
			m_orderSpecial = in.m_orderSpecial;

			// 4. Deep Copy
			if (in.m_foodDescription != nullptr) {
				std::string tmp(in.m_foodDescription);
				this->m_foodDescription = new char[tmp.length() + 1];
				strcpy(this->m_foodDescription, tmp.c_str());
            } else {
                m_foodDescription = nullptr;
            }
		}
		return *this;
	}

	// Default Destructor
	FoodOrder::~FoodOrder() {
		delete[] this->m_foodDescription;
	}

	// Read from csv file
	void FoodOrder::read(std::ifstream &in) {
		if (in.good()) {
			// Copying Name
			std::string nameInput;
			std::getline(in, nameInput, ',');
			strcpy(m_customerName, nameInput.c_str());

			// Copying description
			std::string descriptionInput;
			std::getline(in, descriptionInput, ',');
			m_foodDescription = new char[descriptionInput.length() + 1];
			strcpy(m_foodDescription, descriptionInput.c_str());

			// Copying Price
			in >> this->m_price;
			in.ignore();
			// Copying Daily Special
			char tmp;
			in >> tmp;
			m_orderSpecial = (tmp == 'Y') ? true : false;
		}
	}

	/// A query that displays to the screen the content of an FoodOrder instance in the following format:
	/// COUNTER. Name          |Order Description        |Price w/Tax |Special Price
	/// 
	/// If no customer name has been stored in the current object, this query should print:
	/// COUNTER. No Order
	void FoodOrder::display() const {
		static int counter = 1;
		
		if (this->m_customerName[0] != '\0') {
			// If customer has name enter full print statement
			std::cout << std::setw(2) << std::left << counter << ". "
				<< std::setw(10) << this->m_customerName
				<< "|" << std::setw(25) << this->m_foodDescription
				<< "|" << std::setw(12) << std::fixed << std::setprecision(2) << this->m_price * ( 1 + g_taxrate)
				<< "|" << std::setw(13) << std::right;
			if (this->m_orderSpecial) {
				// If Daily Special == True
				std::cout << (this->m_price * ( 1 + g_taxrate)) - g_dailydiscount << std::endl;
			}
			else {
				// Daily Special == False
				std::cout << std::endl;
            }
        } else {
            std::cout << std::setw(2) << std::left << counter << ". No Order" << std::endl;
        }
        ++counter;
	}
};

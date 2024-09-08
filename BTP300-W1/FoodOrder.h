#ifndef SENECA_FOODORDER_H
#define SENECA_FOODORDER_H
#include <fstream> // File management module

extern double g_taxrate;
extern double g_dailydiscount;

namespace seneca {

	/// <summary>
	/// A FoodOrder object containing relevant data for a single food order.
	/// </summary>
	class FoodOrder {
		/// <summary>
		/// Static array of chars (length 10 including terminator) holding customers name.
		/// </summary>
		char m_customerName[10];
		/// <summary>
		/// Dynamic array of chars holding the foods description.
		/// </summary>
		char* m_foodDescription;
		/// <summary>
		///	A float of precision double holding the price of the order.
		/// </summary>
		double m_price;
		/// <summary>
		/// A boolean holding whether the order is a daily special (T) or if it is not (F).
		/// </summary>
		bool m_orderSpecial;

	public:

		/// <summary>
		/// Default contructor {['\0'], nullptr, 0.0, False}.
		/// </summary>
		FoodOrder();

		/// <summary>
		/// Copy constructor.
		/// </summary>
		/// <param name="in">A reference to a FoodOrder to be copied from.</param>
		FoodOrder(const FoodOrder& in);

		/// <summary>
		/// Self Assignment operator.
		/// </summary>
		/// <param name="in">A reference to a FoodOrder to be copied from.</param>
		/// <returns>A reference of the FoodOrder newly assigned.</returns>
		FoodOrder& operator=(const FoodOrder& in);

		/// <summary>
		/// Destructor handling the dynamic array(s):
		///    - m_foodDescription
		/// </summary>
		~FoodOrder();

		/// <summary>
		/// If the istream is in a good state, this function will attempt to read 
		/// from the istream and store the information read into current object. 
		///   - The daily special status can be of two values: 'Y' for it is a 
		///     special and 'N' for it is not.
		/// 
		/// If the istream object is not in a good state then this function will 
		/// do nothing.
		/// </summary>
		/// <param name="in">A csv file that contains a list of food orders to be inputted.</param>
		void read(std::ifstream& in);

		/// <summary>
		/// A query that displays to the screen the content of an FoodOrder instance in the following format:
		/// COUNTER. Name          |Order Description        |Price w/Tax |Special Price
		/// 
		/// If no customer name has been stored in the current object, this query should print:
		/// COUNTER. No Order
		/// </summary>
		void display() const;

	};
};
#endif //!SENECA_FOODORDER_H

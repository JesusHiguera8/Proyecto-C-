#include "ExpenseRecord.h"
#include <sstream> // For stringstream

// Constructor
ExpenseRecord::ExpenseRecord(string date, string description, double amount, string paymentMethod, BudgetCategory* category)
    : FinancialRecord(date, description, amount), paymentMethod(paymentMethod), category(category) {
    // When an expense record is created, also add the amount to the category's spent amount
    if (this->category) {
        this->category->addExpense(amount);
    }
}

// Getter
string ExpenseRecord::getPaymentMethod() const {
    return paymentMethod;
}

string ExpenseRecord::getCategoryName() const {
    if (category) {
        return category->getCategoryName();
    }
    return "N/A"; // Or throw an exception if category is null
}

// Override display method
string ExpenseRecord::displayRecordDetails() const {
    stringstream ss;
    ss << FinancialRecord::displayRecordDetails() << ", Payment: " << paymentMethod;
    if (category) {
        ss << ", Category: " << category->getCategoryName();
    }
    return ss.str();
}

// Override type method
string ExpenseRecord::getRecordType() const {
    return "Expense Record";
}
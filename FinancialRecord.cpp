#include "FinancialRecord.h"
#include <sstream> // For stringstream in displayRecordDetails
#include <iomanip>

// Constructor
FinancialRecord::FinancialRecord(string date, string description, double amount)
    : date(date), description(description), amount(amount) {}

// Getters
string FinancialRecord::getDate() const {
    return date;
}

string FinancialRecord::getDescription() const {
    return description;
}

double FinancialRecord::getAmount() const {
    return amount;
}

// Display method
string FinancialRecord::displayRecordDetails() const {
    stringstream ss;
    ss << "Date: " << date << ", Description: " << description << ", Amount: $" << fixed << setprecision(2) << amount;
    return ss.str();
}

// Virtual method for type
string FinancialRecord::getRecordType() const {
    return "Financial Record";
}
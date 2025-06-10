#include "IncomeRecord.h"
#include <sstream> // For stringstream

// Constructor
IncomeRecord::IncomeRecord(string date, string description, double amount, string incomeSource)
    : FinancialRecord(date, description, amount), incomeSource(incomeSource) {}

// Getter
string IncomeRecord::getIncomeSource() const {
    return incomeSource;
}

// Override display method
string IncomeRecord::displayRecordDetails() const {
    stringstream ss;
    ss << FinancialRecord::displayRecordDetails() << ", Source: " << incomeSource;
    return ss.str();
}

// Override type method
string IncomeRecord::getRecordType() const {
    return "Income Record";
}
#ifndef EXPENSERECORD_H
#define EXPENSERECORD_H

#include "FinancialRecord.h" // Inherits from FinancialRecord
#include "BudgetCategory.h"  // Has a BudgetCategory
#include <string>

using namespace std;

class ExpenseRecord : public FinancialRecord {
private:
    string paymentMethod;
    BudgetCategory* category; // For simplicity and common practice, let's make it a pointer or pass the name

public:
    ExpenseRecord(string date, string description, double amount, string paymentMethod, BudgetCategory* category);

    string getPaymentMethod() const; 
    string getCategoryName() const; // Helper to get category name

    string displayRecordDetails() const override;
    string getRecordType() const override;
};

#endif // EXPENSERECORD_H
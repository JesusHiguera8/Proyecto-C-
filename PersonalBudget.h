#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "FinancialRecord.h"
#include "IncomeRecord.h"
#include "ExpenseRecord.h"
#include "BudgetCategory.h"
#include <string>
#include <vector>
#include <algorithm> // For find_if or other algorithms

using namespace std;

class PersonalBudget {
private:
    string userName;
    vector<FinancialRecord*> records; // Using pointers for polymorphism
    vector<BudgetCategory> categories; // Storing BudgetCategory objects directly

public:
    PersonalBudget(string user);
    ~PersonalBudget(); // Destructor to clean up dynamically allocated FinancialRecord objects

    void addFinancialRecord(FinancialRecord* record); // Takes a pointer for polymorphism

    // Implementation would search for BudgetCategory and add/remove
    bool addBudgetCategory(string categoryName, double allocatedAmount);
    bool recordExpense(string date, string description, double amount, string method, string categoryName);
    bool recordIncome(string date, string description, double amount, string source);

    double getTotalIncome() const;
    double getTotalExpenses() const;
    double getCurrentBalance() const;

    string generateFinancialReport() const; 
    string displayAllCategoryStatus() const;
};

#endif
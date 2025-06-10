#include "PersonalBudget.h"
#include <iostream>
#include <sstream> // For stringstream
#include <iomanip> // For fixed and setprecision
#include <numeric> // For std::accumulate

// Constructor
PersonalBudget::PersonalBudget(string user)
    : userName(user) {}

// Destructor
PersonalBudget::~PersonalBudget() {
    // Delete dynamically allocated FinancialRecord objects to prevent memory leaks
    for (FinancialRecord* record : records) {
        delete record;
    }
    records.clear();
    // BudgetCategory objects are stored directly in the vector, so no manual deletion needed here
}

// Add financial record (takes ownership of the pointer)
void PersonalBudget::addFinancialRecord(FinancialRecord* record) {
    if (record) {
        records.push_back(record);
    }
}

// Add budget category
bool PersonalBudget::addBudgetCategory(string categoryName, double allocatedAmount) {
    // Check if category already exists
    for (const auto& cat : categories) {
        if (cat.getCategoryName() == categoryName) {
            cout << "Error: Category '" << categoryName << "' already exists." << endl;
            return false;
        }
    }
    categories.emplace_back(categoryName, allocatedAmount);
    return true;
}

// Record an expense
bool PersonalBudget::recordExpense(string date, string description, double amount, string method, string categoryName) {
    // Find the budget category
    BudgetCategory* targetCategory = nullptr;
    for (auto& cat : categories) { // Use auto& to modify the category if needed
        if (cat.getCategoryName() == categoryName) {
            targetCategory = &cat;
            break;
        }
    }

    if (targetCategory) {
        // Create an ExpenseRecord and add it to records
        ExpenseRecord* newExpense = new ExpenseRecord(date, description, amount, method, targetCategory);
        addFinancialRecord(newExpense);
        cout << "Expense recorded: " << newExpense->displayRecordDetails() << endl;
        return true;
    } else {
        cout << "Error: Budget category '" << categoryName << "' not found for expense." << endl;
        return false;
    }
}

// Record income
bool PersonalBudget::recordIncome(string date, string description, double amount, string source) {
    IncomeRecord* newIncome = new IncomeRecord(date, description, amount, source);
    addFinancialRecord(newIncome);
    cout << "Income recorded: " << newIncome->displayRecordDetails() << endl;
    return true;
}

// Calculate total income
double PersonalBudget::getTotalIncome() const {
    double total = 0.0;
    for (const FinancialRecord* record : records) {
        if (record->getRecordType() == "Income Record") { // Check type dynamically
            total += record->getAmount();
        }
    }
    return total;
}

// Calculate total expenses
double PersonalBudget::getTotalExpenses() const {
    double total = 0.0;
    for (const FinancialRecord* record : records) {
        if (record->getRecordType() == "Expense Record") { // Check type dynamically
            total += record->getAmount();
        }
    }
    return total;
}

// Calculate current balance
double PersonalBudget::getCurrentBalance() const {
    return getTotalIncome() - getTotalExpenses();
}

// Generate financial report
string PersonalBudget::generateFinancialReport() const {
    stringstream ss;
    ss << "--- Financial Report for " << userName << " ---" << endl;
    ss << "Total Income: $" << fixed << setprecision(2) << getTotalIncome() << endl;
    ss << "Total Expenses: $" << fixed << setprecision(2) << getTotalExpenses() << endl;
    ss << "Current Balance: $" << fixed << setprecision(2) << getCurrentBalance() << endl;
    ss << "\n--- All Records ---" << endl;
    if (records.empty()) {
        ss << "No records available." << endl;
    } else {
        for (const FinancialRecord* record : records) {
            ss << "[" << record->getRecordType() << "] " << record->displayRecordDetails() << endl;
        }
    }
    ss << "-----------------------------------" << endl;
    return ss.str();
}

// Display all category status
string PersonalBudget::displayAllCategoryStatus() const {
    stringstream ss;
    ss << "--- Budget Category Status ---" << endl;
    if (categories.empty()) {
        ss << "No budget categories defined." << endl;
    } else {
        for (const auto& cat : categories) {
            ss << cat.displayCategoryStatus() << endl;
        }
    }
    ss << "------------------------------" << endl;
    return ss.str();
}
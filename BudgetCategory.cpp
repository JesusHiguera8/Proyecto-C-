#include "BudgetCategory.h"
#include <sstream> // For stringstream
#include <iomanip> // For fixed and setprecision

// Constructor
BudgetCategory::BudgetCategory(string categoryName, double allocatedAmount)
    : categoryName(categoryName), allocatedAmount(allocatedAmount), spentAmount(0.0) {}

// Getters
string BudgetCategory::getCategoryName() const {
    return categoryName;
}

double BudgetCategory::getAllocatedAmount() const {
    return allocatedAmount;
}

double BudgetCategory::getSpentAmount() const {
    return spentAmount;
}

// Methods
void BudgetCategory::addExpense(double expenseAmount) {
    if (expenseAmount > 0) {
        spentAmount += expenseAmount;
    }
}

double BudgetCategory::getRemainingBudget() const {
    return allocatedAmount - spentAmount;
}

bool BudgetCategory::isOverBudget() const {
    return spentAmount > allocatedAmount;
}

// Display method
string BudgetCategory::displayCategoryStatus() const {
    stringstream ss;
    ss << "Category: " << categoryName
       << ", Allocated: $" << fixed << setprecision(2) << allocatedAmount
       << ", Spent: $" << fixed << setprecision(2) << spentAmount
       << ", Remaining: $" << fixed << setprecision(2) << getRemainingBudget();
    if (isOverBudget()) {
        ss << " (OVER BUDGET!)";
    }
    return ss.str();
}
BudgetCategory BudgetCategory::operator+(const BudgetCategory& other) const {
    // Create a new BudgetCategory with a combined name and sum of allocated/spent amounts
    BudgetCategory combined("Combined Categories", this->allocatedAmount + other.allocatedAmount);
    combined.spentAmount = this->spentAmount + other.spentAmount; // Directly set spentAmount for the new object
    return combined;
} 
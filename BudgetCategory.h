#pragma once
#include <string>

class BudgetCategory {
private:
    std::string categoryName;
    double allocatedAmount;
    double spentAmount;

public:
    BudgetCategory(const std::string& name, double allocated);
    ~BudgetCategory();

    std::string getCategoryName() const;
    double getAllocatedAmount() const;
    double getSpentAmount() const;

    void addExpense(double amount);
    double getRemainingBudget() const;
    bool isOverBudget() const;

    void displayCategoryStatus() const;
};

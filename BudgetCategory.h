#ifndef BUDGETCATEGORY_H
#define BUDGETCATEGORY_H

#include <string>

using namespace std;

class BudgetCategory {
private:
    string categoryName;
    double allocatedAmount;
    double spentAmount;

public:
    BudgetCategory(string categoryName, double allocatedAmount);

    string getCategoryName() const;
    double getAllocatedAmount() const;
    double getSpentAmount() const;

    void addExpense(double expenseAmount);
    double getRemainingBudget() const;
    bool isOverBudget() const;
    string displayCategoryStatus() const;

    BudgetCategory operator+(const BudgetCategory& other) const;
};

#endif
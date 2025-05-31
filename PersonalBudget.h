#pragma once
#include <string>
#include <vector>

class FinancialRecord;
class BudgetCategory;

class PersonalBudget {
private:
    std::string userName;
    std::vector<FinancialRecord*> records;
    std::vector<BudgetCategory*> categories;

public:
    PersonalBudget(const std::string& user);
    ~PersonalBudget();

    void addFinancialRecord(FinancialRecord* record);
    bool addBudgetCategory(const std::string& name, double allocatedAmount);
    BudgetCategory* getBudgetCategory(const std::string& name);

    void recordExpense(const std::string& date, const std::string& description, double amount,
                       const std::string& method, const std::string& categoryName);
    void recordIncome(const std::string& date, const std::string& description, double amount,
                      const std::string& source);

    double getTotalIncome() const;
    double getTotalExpenses() const;
    double getCurrentBalance() const;

    void generateFinancialReport() const;
    void displayAllCategoryStatus() const;
};

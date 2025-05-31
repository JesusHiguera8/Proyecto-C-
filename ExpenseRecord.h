#pragma once
#include "FinancialRecord.h"

class BudgetCategory; // Forward declaration

class ExpenseRecord : public FinancialRecord {
private:
    std::string paymentMethod;
    BudgetCategory* category;

public:
    ExpenseRecord(const std::string& date, const std::string& description,
                  double amount, const std::string& method, BudgetCategory* category);
    ~ExpenseRecord();

    std::string getPaymentMethod() const;
    BudgetCategory* getCategory() const;
    std::string getCategoryName() const;

    void displayRecordDetails() const override;
    std::string getRecordType() const override;
};

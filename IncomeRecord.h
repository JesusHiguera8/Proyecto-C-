#pragma once
#include "FinancialRecord.h"

class IncomeRecord : public FinancialRecord {
private:
    std::string incomeSource;

public:
    IncomeRecord(const std::string& date, const std::string& description, double amount, const std::string& source);
    ~IncomeRecord();

    std::string getIncomeSource() const;
    void displayRecordDetails() const override;
    std::string getRecordType() const override;
};

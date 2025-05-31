#pragma once
#include <string>

class FinancialRecord {
protected:
    std::string date;
    std::string description;
    double amount;

public:
    FinancialRecord(const std::string& date, const std::string& description, double amount);
    virtual ~FinancialRecord();

    std::string getDate() const;
    std::string getDescription() const;
    double getAmount() const;

    virtual void displayRecordDetails() const = 0;
    virtual std::string getRecordType() const = 0;
};

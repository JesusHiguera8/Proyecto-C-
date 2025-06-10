#ifndef INCOMERECORD_H
#define INCOMERECORD_H

#include "FinancialRecord.h" // Inherits from FinancialRecord
#include <string>

using namespace std;

class IncomeRecord : public FinancialRecord {
private:
    string incomeSource;

public:
    IncomeRecord(string date, string description, double amount, string incomeSource);

    string getIncomeSource() const;

    string displayRecordDetails() const override; // Changed to string, override
    string getRecordType() const override;
};

#endif
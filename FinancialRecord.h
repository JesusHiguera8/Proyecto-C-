#ifndef FINANCIALRECORD_H
#define FINANCIALRECORD_H

#include <string>
#include <vector> // This might be needed for other classes, good to include early

using namespace std;

class FinancialRecord {
protected: // Attributes are protected as they are inherited
    string date;
    string description;
    double amount;

public:
    FinancialRecord(string date, string description, double amount);
    virtual ~FinancialRecord() {} // Virtual destructor as it's a base class

    string getDate() const;
    string getDescription() const;
    double getAmount() const;

    virtual string displayRecordDetails() const; // Changed to string
    virtual string getRecordType() const;
};

#endif
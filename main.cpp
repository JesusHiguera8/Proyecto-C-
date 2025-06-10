#include <iostream>
#include <string>
#include "PersonalBudget.h"
#include "IncomeRecord.h"
#include "ExpenseRecord.h"
#include "BudgetCategory.h"
#include <iomanip>
using namespace std;

int main() {
    cout << "Starting Personal Budget Application" << endl;

    // Create a personal budget for a user
    PersonalBudget myBudget("Alice Smith");

    // Add budget categories
    cout << "\n--- Setting Up Budget Categories ---" << endl;
    myBudget.addBudgetCategory("Groceries", 300.00);
    myBudget.addBudgetCategory("Utilities", 150.00);
    myBudget.addBudgetCategory("Entertainment", 100.00);
    myBudget.addBudgetCategory("Transportation", 80.00);
    myBudget.addBudgetCategory("Savings", 200.00);
    myBudget.addBudgetCategory("Groceries", 50.00); // This should fail as category already exists

    cout << myBudget.displayAllCategoryStatus() << endl;

    // Record some income
    cout << "\n--- Recording Income ---" << endl;
    myBudget.recordIncome("2025-06-01", "Monthly Salary", 2500.00, "Employer");
    myBudget.recordIncome("2025-06-05", "Freelance Work", 250.00, "Client X");

    // Record some expenses
    cout << "\n--- Recording Expenses ---" << endl;
    myBudget.recordExpense("2025-06-02", "Grocery Shopping", 75.50, "Credit Card", "Groceries");
    myBudget.recordExpense("2025-06-03", "Electricity Bill", 65.00, "Bank Transfer", "Utilities");
    myBudget.recordExpense("2025-06-04", "Movie Tickets", 25.00, "Debit Card", "Entertainment");
    myBudget.recordExpense("2025-06-06", "Gas Fill-up", 40.00, "Cash", "Transportation");
    myBudget.recordExpense("2025-06-07", "Restaurant Dinner", 55.00, "Credit Card", "Entertainment"); // Over budget for entertainment?
    myBudget.recordExpense("2025-06-08", "Weekly Groceries", 85.25, "Debit Card", "Groceries");
    myBudget.recordExpense("2025-06-09", "Shopping", 120.00, "Credit Card", "Shopping"); // This category doesn't exist, should show error

    // Display updated category status
    cout << "\n--- Updated Budget Category Status ---" << endl;
    cout << myBudget.displayAllCategoryStatus() << endl;

    // --- Demonstrate Operator Overloading ---
    cout << "\n--- Demonstrating Operator Overloading (BudgetCategory + BudgetCategory) ---" << endl;
    BudgetCategory* groceriesCat = nullptr;
    BudgetCategory* entertainmentCat = nullptr;
    BudgetCategory testGroceries("Test Groceries", 0); // Allocated amount doesn't matter for sum of spent
    testGroceries.addExpense(75.50);
    testGroceries.addExpense(85.25); 

    BudgetCategory testEntertainment("Test Entertainment", 0);
    testEntertainment.addExpense(25.00);
    testEntertainment.addExpense(55.00); 

    cout << "Test Groceries status: " << testGroceries.displayCategoryStatus() << endl;
    cout << "Test Entertainment status: " << testEntertainment.displayCategoryStatus() << endl;

    // Use the overloaded + operator
    BudgetCategory combinedCategory = testGroceries + testEntertainment;

    cout << "\nResult of combining 'Test Groceries' and 'Test Entertainment' categories:" << endl;
    cout << combinedCategory.displayCategoryStatus() << endl; // Should show combined spent amount

    cout << "Total spent from Groceries and Entertainment: $" << fixed << setprecision(2) << (testGroceries.getSpentAmount() + testEntertainment.getSpentAmount()) << endl;


    // Generate final financial report
    cout << "\n--- Final Financial Report ---" << endl;
    cout << myBudget.generateFinancialReport() << endl;

    cout << "Application finished." << endl;

    return 0;
}
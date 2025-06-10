# Personal Budget Manager
In today’s complex financial world, managing personal finances has become a fundamental life skill. People of all ages often face challenges when trying to track how they spend their money, how much they earn, and how well they stick to a monthly budget. This is particularly important for young adults and students, who may be managing money on their own for the first time.

Inspired by real-world personal finance tools and educational initiatives on financial literacy, the Personal Budget Manager aims to simulate a simplified financial planner using C++ and Object-Oriented Programming (OOP). The main goal is to help users become aware of their income and expenses by categorizing them and monitoring their monthly financial balance.

This console-based application allows users to input their earnings and expenses, organize spending into categories (like rent, food, entertainment, etc.), and receive a summary that shows if they are staying within their budget limits.

Besides being a practical tool, this project serves as a learning opportunity to apply core programming concepts such as class design, encapsulation, composition. It is also a stepping stone for developing more complex finance applications in the future. 

## Class Descriptions and Problem Solving
The core problem this system aims to solve is providing a structured way for a user to track their income, expenses, and manage their budget across different categories.

1. FinancialRecord (Base Class)
Description: This is an abstract base class that represents any transaction that affects a user's financial standing. It holds common attributes like the date, a description of the transaction, and the amount. It also defines virtual functions (displayRecordDetails and getRecordType) to ensure that all specific financial record types (like income or expense) can be treated uniformly through polymorphism.
How it Solves the Problem:
 - Abstraction: It encapsulates the shared characteristics of all financial transactions, reducing code duplication.
 - Polymorphism: By defining virtual methods, it allows PersonalBudget to store and process a vector of FinancialRecord pointers, regardless of whether they are IncomeRecords or ExpenseRecords. This enables generic handling of records (e.g., in a financial report) while still allowing specific details to be displayed.
2. IncomeRecord
Description: This class inherits from FinancialRecord and specifically represents money coming in. It adds an incomeSource attribute to capture where the money originated. It overrides the virtual methods from FinancialRecord to provide specific details for income.
How it Solves the Problem:
 - Specialization: It extends the general FinancialRecord to model income distinctively.
 - Detailed Tracking: Allows users to categorize and understand where their money is coming from.
 - Contribution to Balance: Its amount directly contributes positively to the overall financial balance.
3. BudgetCategory
Description: This class represents a defined spending area within the budget (e.g., "Groceries", "Utilities"). It tracks the categoryName, an allocatedAmount (how much the user plans to spend), and the spentAmount (how much has actually been spent). It provides methods to add expenses, check remaining budget, and determine if the category is over budget. It also includes an overloaded operator+ to combine the financial stats of two categories.
How it Solves the Problem:
 - Budget Planning: Enables the user to set financial limits for different areas of spending.
 - Spending Control: By tracking spentAmount against allocatedAmount, it helps users monitor their spending and identify potential overspending early.
 - Flexibility with Operator Overloading: The operator+ allows for convenient summation of financial metrics across different categories, which can be useful for higher-level reporting or analysis (e.g., "How much did I spend on food and housing combined?").
4. ExpenseRecord
Description: This class inherits from FinancialRecord and represents money going out. It includes a paymentMethod and, crucially, a pointer to an associated BudgetCategory. When an ExpenseRecord is created, its amount is added to the spentAmount of its linked BudgetCategory.
How it Solves the Problem:
 - Specialization: Models outflows of money.
 - Category Linkage: The direct association with BudgetCategory is fundamental. It ensures that every expense directly impacts the relevant budget category, making real-time budget tracking possible. This is where the budget control mechanism is primarily enforced.
 - Payment Method Tracking: Offers additional detail for understanding spending patterns (e.g., "Am I relying too much on credit cards for certain expenses?").
5. PersonalBudget
Description: This is the central "manager" class of the system. It holds a user's userName, a vector of FinancialRecord pointers (allowing for both income and expense records), and a vector of BudgetCategory objects. It provides methods to add new financial records and categories, record specific income/expenses, calculate total income, expenses, and current balance, and generate comprehensive financial reports.
How it Solves the Problem:
 - Central Control: Acts as the main interface for the user, orchestrating interactions between financial records and budget categories.
 - Data Aggregation: Collects and manages all financial data (records and categories) for a single user.
 - Comprehensive Reporting: Generates a holistic view of the user's financial health, summarizing income, expenses, balance, and providing detailed breakdowns per category.
 - User Interface Logic (Implicit): This class would expose the high-level functions that a user would interact with (e.g., "add income," "record expense," "show report").

![UML_project (7)](https://github.com/user-attachments/assets/29c4c7bc-0064-4e90-b95c-38d94abf5225)

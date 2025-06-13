# Personal Budget Manager
In today’s complex financial world, managing personal finances has become a fundamental life skill. People of all ages often face challenges when trying to track how they spend their money, how much they earn, and how well they stick to a monthly budget. This is particularly important for young adults and students, who may be managing money on their own for the first time.

Inspired by real-world personal finance tools and educational initiatives on financial literacy, the Personal Budget Manager aims to simulate a simplified financial planner using C++ and Object-Oriented Programming (OOP). The main goal is to help users become aware of their income and expenses by categorizing them and monitoring their monthly financial balance.

This console-based application allows users to input their earnings and expenses, organize spending into categories (like rent, food, entertainment, etc.), and receive a summary that shows if they are staying within their budget limits.

Besides being a practical tool, this project serves as a learning opportunity to apply core programming concepts such as class design, encapsulation, composition. It is also a stepping stone for developing more complex finance applications in the future. 

## Class Descriptions and Problem Solving
The core problem this system aims to solve is providing a structured way for a user to track their income, expenses, and manage their budget across different categories.

1. FinancialRecord
 - Description: The blueprint for any money movement. It ensures every transaction has a date, description, and amount, providing a universal standard.
 - How it Solves the Problem: It unifies how all money events are handled, making it easy to process income and expenses together for reports and calculations.
2. IncomeRecord
 - Description: Specifically tracks money flowing in, adding details like the income's source (e.g., "Salary").
 - How it Solves the Problem: Clearly identifies your earnings, allowing the system to calculate your total income and understand where your wealth originates.
3. BudgetCategory
 - Description: Your digital spending envelope. You set an allocatedAmount for a named category (e.g., "Groceries"), and it tracks your spentAmount against that limit.
 - How it Solves the Problem: Actively monitors your spending against predefined limits, preventing overspending and instantly showing how much you have left in each area. The operator+ helps combine spending insights across categories.
4. ExpenseRecord
 - Description: Your digital receipt for money going out. It logs payment method and, critically, links directly to its BudgetCategory to update spending.
 - How it Solves the Problem: Automatically updates your budget categories in real-time with every expense, providing an immediate and accurate view of remaining funds for specific spending areas.
5. PersonalBudget
 - Description: Your central financial dashboard. It manages all your financial records and budget categories, processes transactions, and generates reports.
 - How it Solves the Problem: Provides a comprehensive overview of your financial health (income, expenses, balance, budget status) and serves as the main point of interaction for managing your money.
 - 
![UML_project (8)](https://github.com/user-attachments/assets/650fea7c-bc67-4365-ab19-a1e07d10ce33)



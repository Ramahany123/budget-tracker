#Program Overview:
This budget tracker program enables users to manage their income and expenses. 
It offers functionalities to add, display, and delete income sources and expense categories. 
Additionally, it generates reports on financial details such as total expenses, income, most expensive category, and consumption details.

##Libraries Used:
<iostream>: Input and output operations.
<limits>: Provides numeric limits for streams.
using namespace std: Allows using elements of the standard C++ library.
##Functions and Classes:
####toLower(const string& input)
Converts a given string to lowercase characters.
Usage: Makes the program case insensitive.

####handleInvalidInput()
Handles invalid inputs by clearing the error state and ignoring the input buffer.

####struct Expense & struct Income
Structures to store expense categories and income sources with their respective amounts.

####class CIncome
Manages income-related operations.
addIncome(): Adds income from recommended sources or user-input sources, avoiding duplicates.
showIncomes(): Displays added income sources and their amounts.
deleteIncome(): Deletes a specific income source.
calculateTotalIncome(): Calculates the total income.

####class ClassExpense
Manages expense-related operations.
addExpenseCategory(): Adds expense categories from recommended options or user-input categories, preventing duplicates.
calculateTotalExpenses(): Calculates the total expenses.
DisplayExpensesUsed(): Displays added expense categories and their amounts.
deleteExpenseCategory(): Deletes a specific expense category.

####class Report
Generates reports based on financial data.
ShowTotalExpence(ClassExpense ex, CIncome in): Shows total expenses and total incomes.
ShowMostExpenceCat(ClassExpense ex): Shows the most expensive expense category.
ConsumptionDetails(ClassExpense ex, CIncome inco): Provides consumption details like remaining amount and spending percentage.

####main()
Main program execution.
Displays a welcome message and asks for the user's name.
Provides a menu-driven interface for users to interact with different functionalities:
Income management
Expense management
Reports generation
Displaying program credits and exit.

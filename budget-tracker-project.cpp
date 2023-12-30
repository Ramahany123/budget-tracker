#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;
//comment
struct Expense {
    string category;
    double amount;
};

struct Income {
    string source;
    double amount;
};

class CIncome {
private:
    Income incomes[20];   // Assuming a maximum of 20 incomes
    int incomeCount = 0;  // To keep track of the number of incomes

public:
    void addIncome() {
        if (incomeCount < 20) {
            cout << "Enter the income source: ";
            cin.ignore();
            getline(cin, incomes[incomeCount].source);
            cout << "Enter the amount of the income: ";
            cin >> incomes[incomeCount].amount;

            for (int i = 0; i < incomeCount; i++) {
                if (incomes[incomeCount].source == incomes[i].source) {
                    incomes[i].amount += incomes[incomeCount].amount;
                    incomeCount--;

                    for (int j = i + 1; j < incomeCount; j++) {
                        incomes[j] = incomes[j + 1];
                    }
                    break;
                }
            }
            incomeCount++;
        } else {
            cout << "Maximum number of incomes reached!" << endl;
        }
    }

    void showIncomes() {
        for (int i = 0; i < incomeCount; i++) {
            cout << "Income source: " << incomes[i].source << "\tIncome amount: " << incomes[i].amount << endl;
        }
    }

    void deleteIncome() {
        cout << "Enter the name of the income you want to delete: ";
        Income incomeToDelete;
        cin.ignore();
        getline(cin, incomeToDelete.source);

        for (int i = 0; i < incomeCount; i++) {
            if (incomeToDelete.source == incomes[i].source) {
                for (int j = i; j < incomeCount - 1; j++) {
                    incomes[j] = incomes[j + 1];
                }
                incomeCount--;
                cout << "Income with source '" << incomeToDelete.source << "' deleted successfully." << endl;
                return;
            }
        }
    }

    double calculateTotalIncome() {
        double total = 0.0;
        for (int i = 0; i < incomeCount; ++i) {
            total += incomes[i].amount;
        }
        return total;
    }
};

class ClassExpense {
private:
    Expense expenses[30];
    int expenseCount = 0;

    string ExpenseCategories[6] = {"Food", "Utilities", "Rent", "Entertainment", "Transportation", "Other"};

public:

    void addExpenseCategory() {
        string choice;
        do {
            int selectedCategory;
            if(expenseCount < 30){
            cout << "Enter the number corresponding to the recommended category: ";
            cin >> selectedCategory;

            if (selectedCategory >= 1 && selectedCategory <= 5) {
                expenses[expenseCount].category = ExpenseCategories[selectedCategory - 1];
                cout << "Enter amount of money spent on this category: ";
                cin >> expenses[expenseCount].amount;
            } else if (selectedCategory == 6) {
                cout << "Enter expense category: ";
                cin.ignore();
                getline(cin, expenses[expenseCount].category);
                cout << "Enter amount of money spent on this category: ";
                cin >> expenses[expenseCount].amount;
            } else {
                cout << "Invalid category selection.\n";
                break;
            }

            for (int i = 0; i < expenseCount; i++) {
                if (expenses[expenseCount].category == expenses[i].category) {
                    expenses[i].amount += expenses[expenseCount].amount;
                    expenseCount--;

                    for (int j = i + 1; j < expenseCount; j++) {
                        expenses[j] = expenses[j + 1];
                    }
                    break;
                }
            }

            cout << "Expense category added successfully.\n";
            expenseCount++;
            }else{
            cout << "Expense entries limit reached.\n";
            break;
            }

cout << "Do you want to add another expense category? (y/n): ";
            cin.ignore();
            getline(cin, choice);

        } while (choice == "y" || choice == "Y");
    }

    void calculateTotalExpenses() {
        double totalExpense = 0.0;
        for (int i = 0; i < expenseCount; ++i) {
            totalExpense += expenses[i].amount;
        }
        cout << "Total Expenses: " << totalExpense << endl;
    }

    void DisplayExpensesUsed() {
        cout << "Your Expenses: \n";
        for (int i = 0; i < expenseCount; i++) {
            cout << expenses[i].category << " : " << expenses[i].amount << endl;
        }
    }

    void ShowExpenses() {
        if (expenseCount < 30) {
            cout << "Here Are Recommended Categories\n";
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << "-" << ExpenseCategories[i] << endl;
            }
        }
    }

    void deleteExpenseCategory() {
        cout << "Enter the name of expense you want to delete: ";
        Expense expenseToDelete;
        cin.ignore();
        getline(cin, expenseToDelete.category);

        for (int i = 0; i < expenseCount; i++) {
            if (expenseToDelete.category == expenses[i].category) {
                for (int j = i; j < expenseCount - 1; j++) {
                    expenses[j] = expenses[j + 1];
                }
                expenseCount--;
                cout << "Expense with category '" << expenseToDelete.category << "' deleted successfully." << endl;
                return;
            }
        }
    }
};

int main() {
    ClassExpense objExpense;
    CIncome objIncome;
    int choiceSelect;
    string name;
    cout << "Welcome To Our Budget Tracker Program\n";
    cout << "Please, Provide us with your name\n";
    cout << "Your name: ";
    cin >> name;
    cout << "Hello, " << name << ":)" << "\nWe are so glad that you are interested in our program\nLet's Start...\n";
    cout << "--------------------<>--------------------" << endl;
    while (true) {
        cout << "Enter your choice:\n";
        cout << "1-Income\n2-Expense\n3-Report\n4-Exit\n";
        cout << "--------------------<>--------------------" << endl;
        cin >> choiceSelect;
        cout << "--------------------<>--------------------" << endl;
        if (choiceSelect == 1) {
            while (true) {
                int choiceIncome;
                cout << "1-Add income\n2-Show incomes\n3-Delete income\n4-Return to main menu\n";
                cout << "--------------------<>--------------------" << endl;
                cin >> choiceIncome;
                cout << "--------------------<>--------------------" << endl;
                if (choiceIncome == 1) {
                    objIncome.addIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceIncome == 2) {
                    objIncome.showIncomes();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceIncome == 3) {
                    objIncome.deleteIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceIncome == 4) {
                    break;
                }
            }

} else if (choiceSelect == 2) {
            while (true) {
                int choiceExpense;
                cout << "1-Add Expense Category\n2-Show Recommended Expenses\n3-Delete Expense Category\n4-Return to main menu\n";
                cout << "--------------------<>--------------------" << endl;
                cin >> choiceExpense;
                cout << "--------------------<>--------------------" << endl;
                if (choiceExpense == 1) {
                    objExpense.addExpenseCategory();
                    cout << "--------------------<>--------------------" << endl;
                    objExpense.DisplayExpensesUsed();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 2) {
                    objExpense.ShowExpenses();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 3) {
                    objExpense.deleteExpenseCategory();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 4) {
                    break;
                }
            }
        } else if (choiceSelect == 3) {

        } else if (choiceSelect == 4) {
            cout << "This program is made by:\n1.Shahd Ramadan\n2.Omnia Abuelhassan\n3.Rama Hany\n4.Alaa Abdallah\n";
            cout << "--------------------<>--------------------" << endl;
            cout << "Special thanks to:\n1-Dr.Sherif.\n2-Dr.Yasmeen.\nWe really appreciate their guidance and support with us\nA great thanks to them \n";
            cout << "--------------------<>--------------------" << endl;
            cout << "Goodbye\nWaiting for us for future amazing programs ISA:)\n";
            break;
        }
    }

    return 0;
}
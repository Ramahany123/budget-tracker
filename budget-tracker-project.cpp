#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

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
    string incomeSources[4] = {"Primary job","Part-time job","Freelance", "Other"}; // to add recommended sources for income

public:
    void addIncome() {
        string choice;
        cout << "Here Are Recommended Categories\n";
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << "-" << incomeSources[i] << endl;
        }
        do {
            int selectedCategory;
            if(incomeCount < 30){
            cout << "Enter the number corresponding to the recommended source: ";
            cin >> selectedCategory;

            if (selectedCategory >= 1 && selectedCategory <= 3) {
                incomes[incomeCount].source = incomeSources[selectedCategory - 1];
                cout << "Enter amount of money gained from this category: ";
                cin >> incomes[incomeCount].amount;
            } else if (selectedCategory == 4) {
                cout << "Enter income source: ";
                cin.ignore();
                getline(cin, incomes[incomeCount].source);
                cout << "Enter amount of money gained from this category: ";
                cin >> incomes[incomeCount].amount;
            } else {
                cout << "Invalid source selection.\n";
                break;
            }

            for (int i = 0; i < incomeCount; i++) {
                if (incomes[incomeCount].source == incomes[i].source) {     //to check for dublicated source
                    incomes[i].amount += incomes[incomeCount].amount;
                    incomeCount--;

                    for (int j = i + 1; j < incomeCount; j++) {     //to delete the dublicated source
                        incomes[j] = incomes[j + 1];
                    }
                    break;
                }
            }

            cout << "income source added successfully.\n";
            incomeCount++;
            }else{
            cout << "incomes entries limit reached.\n";
            break;
            }

            cout << "Do you want to add another income source? (y/n): ";
            cin.ignore();
            getline(cin, choice);

        } while (choice == "y" || choice == "Y");
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
string ExpenseCategories[6] = {"Food", "Utilities", "Rent", "Entertainment", "Transportation", "Other"};
public:
int expenseCount = 0;
Expense expenses[30];
void addExpenseCategory() {
        string choice;
        cout << "Here Are Recommended Categories\n";
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << "-" << ExpenseCategories[i] << endl;
            }
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

    double calculateTotalExpenses() {
        double totalExpense = 0.0;
        for (int i = 0; i < expenseCount; ++i) {
            totalExpense += expenses[i].amount;
        }
        return totalExpense;
    }

    void DisplayExpensesUsed() {
        cout << "Your Expenses: \n";
        for (int i = 0; i < expenseCount; i++) {
            cout << expenses[i].category << " : " << expenses[i].amount << endl;
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
class Report : public CIncome, public ClassExpense {
public:
    void ShowTotalExpence(ClassExpense &ex) {
        double totalExpenses = ex.calculateTotalExpenses();
        cout << "Total Expenses: " << totalExpenses << endl;
    }

    void ShowMostExpenceCat(ClassExpense &ex) {
        Expense mostExpensive = ex.expenses[0];
        for (int i = 1; i < ex.expenseCount; i++) {
            if (ex.expenses[i].amount > mostExpensive.amount) {
                mostExpensive = ex.expenses[i];
            }
        }
        cout << "You have spent the most in the category of " << mostExpensive.category << " which amounts to $" << mostExpensive.amount << endl;
    }

    void ConsumptionDetails(ClassExpense &ex, CIncome &inco) {
        double totalExpenses = ex.calculateTotalExpenses();
        double totalIncome = inco.calculateTotalIncome();
        double remainingAmount = totalIncome - totalExpenses;

        if (remainingAmount <= 0) {
            cout << "Warning: Your expenses have done a magic trick and made your money disappear!\n Expect a minus sign in your balance unless you work some financial wizardry!\nYou spent "<< totalExpenses - totalIncome <<"$ more than your income" << endl;
        } else {
            cout << "Your total income is $" << totalIncome << ". You have spent $" << totalExpenses << " on expenses." << endl;
            cout << "The remaining amount is $" << remainingAmount << ", which is about " << ((totalExpenses / totalIncome) * 100) << "% of your income." << endl;
        }
    }
};



int main() {
    ClassExpense objExpense;
    CIncome objIncome;
    Report objReport;
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
            }}
 else if (choiceSelect == 2) {
           while (true) {
                int choiceExpense;
                cout << "1-Add Expense Category\n2-Show Expenses\n3-Delete Expense Category\n4-Return to main menu\n";
                cout << "--------------------<>--------------------" << endl;
                cin >> choiceExpense;
                cout << "--------------------<>--------------------" << endl;
                if (choiceExpense == 1) {
                    objExpense.addExpenseCategory();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 2) {
                    objExpense.DisplayExpensesUsed();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 3) {
                    objExpense.deleteExpenseCategory();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 4) {
                    break;
                }
            }
        } else if (choiceSelect == 3) {
            while (true){
              int reportChoice;
            cout << "1-Show total expense\n2-Show most expensive category\n3-Show consumption details\n4-Return to main menu\n";
            cout << "--------------------<>--------------------" << endl;
            cin >> reportChoice;
            cout << "--------------------<>--------------------" << endl;

             if (reportChoice == 1) {
                    objReport.ShowTotalExpence(objExpense);
                    cout << "--------------------<>--------------------" << endl;
                } else if (reportChoice== 2) {
              objReport.ShowMostExpenceCat(objExpense);
                    cout << "--------------------<>--------------------" << endl;
                } else if (reportChoice == 3) {
                    objReport.ConsumptionDetails(objExpense,objIncome);
                    cout << "--------------------<>--------------------" << endl;
                } else if (reportChoice == 4) {
                    break;
                }
           }
        }else if (choiceSelect == 4) {
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
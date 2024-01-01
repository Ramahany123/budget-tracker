#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;
string toLower(const string& input) {       //use it to make program case insensitive
    string result = input;
    for (char& c : result) {
        c = tolower(c);
    }
    return result;
}
struct ExpenseAndIncome {
    string category;
    double amount;
};


class parent {
protected:
    ExpenseAndIncome EI[30]; // Assuming a maximum of 30 incomes and expense
    int ParentCount = 0;    // To keep track of the number of incomes and expenses
    public:
     virtual void AddExpenseAndIncome() = 0;
     virtual void ShowExpenseAndIncome() = 0;
     virtual void DeleteExpenseAndIncome() = 0;
     virtual double TotalExpenseAndIncome() = 0;

};

class CIncome:public parent {
private:
    string incomeSources[4] = {"Primary job","Part-time job","Freelance", "Other"}; // to add recommended sources for income

public:
    void AddExpenseAndIncome() override {
        string choice;

        do {
            cout << "Here Are Recommended Categories\n";
            for (int i = 0; i < 4; i++) {
                cout << i + 1 << "-" << incomeSources[i] << endl;
            }
            int selectedCategory;
            if(ParentCount < 30){
            cout << "Enter the number corresponding to the recommended source: ";
            cin >> selectedCategory;

            if (selectedCategory >= 1 && selectedCategory <= 3) {                   //add money to the recommended source
                EI[ParentCount].category = incomeSources[selectedCategory - 1];
                cout << "Enter amount of money gained from this source: ";
                cin >> EI[ParentCount].amount;
            } else if (selectedCategory == 4) {         //add a source from the user and then the amount of money
                cout << "Enter income source: ";
                cin.ignore();
                getline(cin, EI[ParentCount].category);
                cout << "Enter amount of money gained from this source: ";
                cin >> EI[ParentCount].amount;
            } else {
                cout << "Invalid source selection.\n";          //if user choose something isn't in list it restart the loop and ask the user again
                break;
            }

            for (int i = 0; i < ParentCount; i++) {
                if (toLower(EI[ParentCount].category) == toLower(EI[i].category)) {     //to check for dublicated source
                    EI[i].amount += EI[ParentCount].amount;
                    ParentCount--;

                    for (int j = i + 1; j < ParentCount; j++) {     //to delete the dublicated source
                        EI[j] = EI[j + 1];
                    }
                    break;
                }
            }

            cout << "income source added successfully.\n";
            ParentCount++;
            }else{
            cout << "incomes entries limit reached.\n";
            break;
            }

            cout << "Do you want to add another income source? (y/n): ";
            cin.ignore();
            getline(cin, choice);

} while (choice == "y" || choice == "Y");       //gives the user the option to add another income if he want
    }

    void ShowExpenseAndIncome() {
        for (int i = 0; i < ParentCount; i++) {
            cout << "Income source: " << EI[i].category << "\tIncome amount: " << EI[i].amount << endl;
        }
    }

    void DeleteExpenseAndIncome() {
        cout << "Enter the name of the income you want to delete: ";
        ExpenseAndIncome incomeToDelete;
        cin.ignore();
        getline(cin, incomeToDelete.category);

        for (int i = 0; i < ParentCount; i++) {
            if (toLower(incomeToDelete.category) == toLower(EI[i].category)) {
                for (int j = i; j < ParentCount - 1; j++) {
                   EI[j] = EI[j + 1];
                }
                ParentCount--;
                cout << "Income with source '" << incomeToDelete.category << "' deleted successfully." << endl;
                return;
            }
        }
    }

    double TotalExpenseAndIncome() {
        double total = 0.0;
        for (int i = 0; i < ParentCount; ++i) {
            total += EI[i].amount;
        }
        return total;
    }
};

class ClassExpense: public parent {
private:
string ExpenseCategories[6] = {"Food", "Utilities", "Rent", "Entertainment", "Transportation", "Other"};
public:
void AddExpenseAndIncome() {
        string choice;
        do {
            cout << "Here Are Recommended Categories\n";
            for (int i = 0; i < 6; i++) {
                cout << i + 1 << "-" << ExpenseCategories[i] << endl;
            }
            int selectedCategory;
            if(ParentCount < 30){
            cout << "Enter the number corresponding to the recommended category: ";
            cin >> selectedCategory;

            if (selectedCategory >= 1 && selectedCategory <= 5) {
                EI[ParentCount].category = ExpenseCategories[selectedCategory - 1];
                cout << "Enter amount of money spent on this category: ";
                cin >> EI[ParentCount].amount;
            } else if (selectedCategory == 6) {
                cout << "Enter expense category: ";
                cin.ignore();
                getline(cin, EI[ParentCount].category);
                cout << "Enter amount of money spent on this category: ";
                cin >> EI[ParentCount].amount;
            } else {
                cout << "Invalid category selection.\n";
                break;
            }

            for (int i = 0; i < ParentCount; i++) {
                if (toLower(EI[ParentCount].category) == toLower(EI[i].category)) {
                    EI[i].amount += EI[ParentCount].amount;
                   ParentCount--;

                    for (int j = i + 1; j < ParentCount; j++) {
                        EI[j] = EI[j + 1];
                    }
                    break;
                }
            }

cout << "Expense category added successfully.\n";
            ParentCount++;
            }else{
            cout << "Expense entries limit reached.\n";
            break;
            }

            cout << "Do you want to add another expense category? (y/n): ";
            cin.ignore();
            getline(cin, choice);

        } while (choice == "y" || choice == "Y");
    }

    double TotalExpenseAndIncome() {
        double totalExpense = 0.0;
        for (int i = 0; i < ParentCount; ++i) {
            totalExpense += EI[i].amount;
        }
        return totalExpense;
    }

    void ShowExpenseAndIncome() {
        cout << "Your Expenses: \n";
        for (int i = 0; i < ParentCount; i++) {
            cout << EI[i].category << " : " <<EI[i].amount << endl;
        }
    }

    void DeleteExpenseAndIncome() {
        cout << "Enter the name of expense you want to delete: ";
        ExpenseAndIncome expenseToDelete;
        cin.ignore();
        getline(cin, expenseToDelete.category);

for (int i = 0; i < ParentCount; i++) {
            if (toLower(expenseToDelete.category) == toLower(EI[i].category)) {
                for (int j = i; j < ParentCount - 1; j++) {
                    EI[j] = EI[j + 1];
                }
                ParentCount--;
                cout << "Expense with category '" << expenseToDelete.category << "' deleted successfully." << endl;
                return;
            }
        }
    }
    friend class Report;
};
class Report : public CIncome, public ClassExpense {
public:
    void ShowTotalExpence(ClassExpense &ex) {
        double totalExpenses = ex.TotalExpenseAndIncome();
        cout << "Total Expenses: " << totalExpenses << endl;
    }

    void ShowMostExpenceCat(ClassExpense &ex) {
        ExpenseAndIncome mostExpensive = ex.EI[0];
        for (int i = 1; i < ex.ParentCount; i++) {
            if (ex.EI[i].amount > mostExpensive.amount) {
                mostExpensive = ex.EI[i];
            }
        }
        cout << "You have spent the most in the category of " << mostExpensive.category << " which amounts to $" << mostExpensive.amount << endl;
    }

    void ConsumptionDetails(ClassExpense &ex, CIncome &inco) {
        double totalExpenses = ex.TotalExpenseAndIncome();
        double totalIncome = inco.TotalExpenseAndIncome();
        double remainingAmount = totalIncome - totalExpenses;

        if (remainingAmount <= 0) {
            cout << "Warning: Your expenses have done a magic trick and made your money disappear!\nExpect a minus sign in your balance unless you work some financial wizardry!\nYou spent "<< totalExpenses - totalIncome <<"$ more than your income" << endl;
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
    parent* ptr1 = &objExpense;
    parent* ptr2 = &objIncome;
    string name;
    cout << "Welcome To Our Budget Tracker Program\n";
    cout << "Please, Provide us with your name\n";
    cout << "Your name: ";
    getline(cin, name);
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
                    ptr2->AddExpenseAndIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceIncome == 2) {
                    ptr2->ShowExpenseAndIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceIncome == 3) {
                    ptr2->DeleteExpenseAndIncome();
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
                    ptr1->AddExpenseAndIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 2) {
                    ptr1->ShowExpenseAndIncome();
                    cout << "--------------------<>--------------------" << endl;
                } else if (choiceExpense == 3) {
                    ptr1->DeleteExpenseAndIncome();
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
        else{
            cout << "INVALID INPUT!!! please try agian\n";
            continue;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

struct Transaction {
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
            for (int i = 0; i < incomeCount; i++){            //check if the source is the same and add its amount to the original source
                if (incomes[incomeCount].source == incomes[i].source){
                    incomes[i].amount += incomes[incomeCount].amount;
                    incomeCount--;

                    for (int j = i +1; j < incomeCount; j++){      //delete the dublicated source
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
    void showIncomes(){
            for (int i = 0; i < incomeCount; i++){
                cout << "Income source: " << incomes[i].source << "\tIncome amount: " << incomes[i].amount << endl;
            }
        }
    void deleteIncome(){
        cout << "Enter the name of the income you want to delete: ";
        Income incomeToDelete;
        cin.ignore();
        getline(cin, incomeToDelete.source);
        for(int i = 0; i < incomeCount; i++){
            if (incomeToDelete.source == incomes[i].source){
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
class Expense {
private:
    Transaction expenses[30];
    int expenseCount = 0;

    string ExpenseCategories[6] = {"Food", "Utilities (Gas, Electricity, Water,..)", "Housing (Rent, Mortage Payment)", "Entertainment", "Transportation","Other"};

public:

    void addExpenseCategory() {
         string choice;
         Transaction t;
        do {

                cout << "Choose from the following expense categories:\n";
                for (int i = 0; i <6; i++) {
                    cout << i + 1 << "-" << ExpenseCategories[i] << endl;
                }

                int selectedCategory;
                cout << "Enter the number corresponding to the category: ";
                cin >> selectedCategory;

                if (selectedCategory >= 1 && selectedCategory <= 5) {

                    t.category = ExpenseCategories[selectedCategory - 1];
                    cout << "Enter amount of money spent on this category: ";
                    cin >> t.amount;
                    }else if (selectedCategory == 6) {
                        cout << "Enter expense category: ";
                        cin >> t.category;
                        cout << "Enter amount of money spent on this category: ";
                        cin >> t.amount;
                    }else {
                    cout << "Invalid category selection.\n";
                    break;
                }
                    if (expenseCount < 30) {
                        expenses[expenseCount++] = t;
                        cout << "Expense category added successfully.\n";
                    } else {
                        cout << "Expense entries limit reached.\n";
                        break;
                    }


            cout << "Do you want to add another expense category? (y/n): ";
            cin >> choice;
        }
        while(choice == "y" || choice == "Y");

    }

    void sumExpenses() {
        double totalExpense = 0;
        for (int i = 0; i < expenseCount; ++i) {
            totalExpense += expenses[i].amount;
        }
        cout << "Total Expenses: " << totalExpense << endl;
    }

    void DisplayExpenses(){
    for(int i = 0; i<expenseCount;i++){
        cout << expenses[i].category << " : " << expenses[i].amount << endl;
    }

    }

    void deleteExpenseCategory() {
        string categoryToDelete;
        cout << "Enter expense category to delete: ";
        cin >> categoryToDelete;

        for (int i = 0; i < expenseCount; i++) {
            if (expenses[i].category == categoryToDelete) {
                for (int j = i; j < expenseCount - 1; ++j) {
                    expenses[j] = expenses[j + 1];
                }
                --expenseCount;
                cout << "Expense category deleted successfully.\n";
                return;
            }
        }
        cout << "Expense category not found.\n";
    }
};


int main() {
    CIncome objIncome;
    Expense objExpense;
    int choiceSelect;
    while (true){
        cout << "1-Income\n2-Expense\n3-Report\n4-Exit\n";
        cout << "-------------------<>---------------------" << endl;
        cout << "Enter your choice:\n";
        cin >> choiceSelect;
        cout << "-------------------<>---------------------" << endl;
    if (choiceSelect == 1){
        while (true){
            int choiceIncome;
            cout << "1-Add income\n2-Show incomes\n3-Delete income\n4-Return to main menu\n";
            cout << "-------------------<>---------------------" << endl;
            cin >> choiceIncome;
            cout << "-------------------<>---------------------" << endl;
            if (choiceIncome == 1){
                objIncome.addIncome();
                cout << "-------------------<>---------------------" << endl;
            }
            else if (choiceIncome == 2){
                objIncome.showIncomes();
                cout << "-------------------<>---------------------" << endl;
            }
            else if (choiceIncome == 3){
                objIncome.deleteIncome();
                cout << "-------------------<>---------------------" << endl;
            }
            else if (choiceIncome == 4){
                break;
            }

        }
    }
    else if (choiceSelect == 2){
        int choiceExpense;
            cout << "1-Add Expense Category\n2-Delete Expense Category\n";
            cout << "-------------------<>---------------------" << endl;
            cin >> choiceExpense;
            cout << "-------------------<>---------------------" << endl;
            if (choiceExpense == 1) {
                objExpense.addExpenseCategory();
                cout << "-------------------<>---------------------" << endl;
                  objExpense.DisplayExpenses();
                cout << "-------------------<>---------------------" << endl;
                objExpense.sumExpenses();
                cout << "-------------------<>---------------------" << endl;
            } else if (choiceExpense == 2) {
                objExpense.deleteExpenseCategory();
                cout << "-------------------<>---------------------" << endl;
            }
    }
    else if (choiceSelect == 3){
        
    }
    else if (choiceSelect == 4){
      break;  
    }
        
    }


    return 0;
}
#include <iostream>
#include <string>

using namespace std;

struct Expense {
    string category;
    double amount;
};

struct Income {
    string source;
    double amount;
};

class BudgetTracker {
private:
    Expense expenses[20]; // Assuming a maximum of 10 expenses
    Income incomes[20];   // Assuming a maximum of 10 incomes
    int expenseCount = 0; // To keep track of the number of expenses
    int incomeCount = 0;  // To keep track of the number of incomes

public:
    void addExpense(const string& category, double amount) {
        if (expenseCount < 10) {
            expenses[expenseCount].category = category;
            expenses[expenseCount].amount = amount;
            expenseCount++;
        } else {
            cout << "Maximum number of expenses reached!" << endl;
        }
    }

    void addIncome(const string& source, double amount) {
        if (incomeCount < 10) {
            incomes[incomeCount].source = source;
            incomes[incomeCount].amount = amount;
            incomeCount++;
        } else {
            cout << "Maximum number of incomes reached!" << endl;
        }
    }

    double calculateTotalExpenses() {
        double total = 0.0;
        for (int i = 0; i < expenseCount; ++i) {
            total += expenses[i].amount;
        }
        return total;
    }

    double calculateTotalIncome() {
        double total = 0.0;
        for (int i = 0; i < incomeCount; ++i) {
            total += incomes[i].amount;
        }
        return total;
    }
};

int main() {
    int choiceSelect;
    while (true){
    cout << "enter your choice";
    cout << "1-income\n2-expense\n3-report\n4-exit";
    cin >> choiceSelect;
    if (choiceSelect == 1){
        while (true){
            int choiceIncome;
            cout << "1-add income\n2-delete income\n3-return to main menu";
            cin >> choiceIncome;
            if (choiceIncome == 1){

            }
            else if (choiceIncome == 2){

            }
            else if (choiceIncome == 3){
                break;
            }

        }
    }
    else if (choiceSelect == 2){

    }
    else if (choiceSelect == 3){
        
    }
    else if (choiceSelect == 4){
      break;  
    }
        
    }


    return 0;
}
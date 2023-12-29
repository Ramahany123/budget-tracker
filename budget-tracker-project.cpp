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
};


int main() {
    CIncome ObjIncome;
    int choiceSelect;
    while (true){
    cout << "Enter your choice\n";
    cout << "1-Income\n2-Expense\n3-Report\n4-Exit\n";
    cin >> choiceSelect;
    if (choiceSelect == 1){
        while (true){
            int choiceIncome;
            cout << "1-Add income\n2-Show incomes\n3-Delete income\n4-Return to main menu\n";
            cin >> choiceIncome;
            if (choiceIncome == 1){
                ObjIncome.addIncome();
            }
            else if (choiceIncome == 2){
                ObjIncome.showIncomes();
            }
            else if (choiceIncome == 3){
                ObjIncome.deleteIncome();
            }
            else if (choiceIncome == 4){
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
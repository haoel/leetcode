// Source : https://github.com/haoel/leetcode/issues/135
// Author : Alexander Duffaut
// Date   : 2022-01-30

/********************************************************************************** 
* 
* The sales data of a company's sales is stored in a file Txt that
* obeys the following format: branch_code, year_month, sales_count, total_dend.
* 
* Make a program that loads the data from the file into data structures and allows
* answer expressions such as:
* 
* 1. total sales of subsidiaries with codes between 10 and 20
* 
* 2. total sales of subsidiaries with codes between 10 and 20 in the months of Jan / 17 to Jun / 17
* 
* 3. total sales of all branches in the months of Aug / 17 to Oct / 17
*               
**********************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

int main() {
    //load data from the file
    ifstream inFile;
    cout << "Input file name: " << endl;
    string filename;
    cin >> filename;
    inFile.open(filename);
    
    //store the data into respective 
    string line;
    int count = 0;
    vector<int> branch_codes;
    vector<pair<int, int>> year_month;
    vector<int> sales_count;
    vector<int> total_dend;
    while (inFile >> line) {
        if (count % 4 == 0) {
            //this is a branch code
            branch_codes.push_back(stoi(line.substr(0, line.length() - 1)));
        }
        else if (count % 4 == 1) {
            //this is a year_month
            pair<int, int> tempPair;
            tempPair.first = stoi(line.substr(0, 4));
            tempPair.second = stoi(line.substr(5, 2));
            year_month.push_back(tempPair);
        }
        else if (count % 4 == 2) {
            //this is a sales_count
            sales_count.push_back(stoi(line.substr(0, line.length() - 1)));
        }
        else if (count % 4 == 3) {
            //this is total_dend
            total_dend.push_back(stoi(line.substr(0, line.length() - 1)));
        }
        count++;
    }

    //now all info is stored in contiguous order

    //answer specific prompts:
    int prompt;
    cout << "Enter prompt number: " << endl;
    cin >> prompt;

    if (prompt == 1) {
        int temp1, temp2;
        cout << "Enter the branch codes to search between: " << endl;
        cin >> temp1 >> temp2;
        int total = 0;
        for (int i = 0; i < branch_codes.size(); i++) {
            if (branch_codes[i] >= temp1 && branch_codes[i] <= temp2) {
                //branch code is in range, add to total sales count
                total += sales_count[i];
            }
        }
        cout << "Total sales of subsidiaries with codes between " << temp1 << " and " << temp2 << ": ";
        cout << total << endl;
    }
    else if (prompt == 2) {
        int temp1, temp2;
        cout << "Enter the branch codes to search between: " << endl;
        cin >> temp1 >> temp2;
        cout << "Enter year_month to search between: " << endl;
        string t1, t2;
        cin >> t1 >> t2;
        cout << t1 << " " << t2 << endl;
        int total = 0;
        for (int i = 0; i < branch_codes.size(); i++) {
            if (branch_codes[i] >= temp1 && branch_codes[i] <= temp2) {
                if (year_month[i].first >= stoi(t1.substr(0, 4)) && year_month[i].first <= stoi(t2.substr(0, 4))) {
                    if (year_month[i].second >= stoi(t1.substr(5, 2)) && year_month[i].second <= stoi(t2.substr(5, 2))) {
                        //if entries meet the range, add to total sales count
                        total += sales_count[i];
                    }
                }
            }
        }
        cout << "Total sales of subsdiaries with codes between " << temp1 << " and " << temp2 << " in the months of " << t1 << " to " << t2 << ": ";
        cout << total << endl;
    }
    else if (prompt == 3) {
        string t1, t2;
        cout << "Enter year_month to search between: " << endl;
        cin >> t1 >> t2;
        int total = 0;
        for (int i = 0; i < branch_codes.size(); i++) {
            if (year_month[i].first >= stoi(t1.substr(0, 4)) && year_month[i].first <= stoi(t2.substr(0, 4))) {
                if (year_month[i].second >= stoi(t1.substr(5, 2)) && year_month[i].second <= stoi(t2.substr(5, 2))) {
                    total += sales_count[i];
                }
            }
        }
        cout << "Total sales of all branches in the months of " << t1  << " to " << t2 << ": ";
        cout << total << endl;
    }
}
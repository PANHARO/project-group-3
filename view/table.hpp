#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

// Function to print the table with colors
void printTable(const vector<vector<string>> data, const vector<string> columnNames) {
    cout << fixed << setprecision(2);
    const int colWidth = 30;

    // ANSI escape codes for coloring (RGB format)
    const string headerColor = "\033[38;2;0;255;255m";  // Cyan for headers
    const string priceColor = "\033[38;2;255;223;0m";   // Yellow for price
    const string reset = "\033[0m";                      // Reset to default color
    char red = '\033[31m-';

    // Print top border
    cout << "\033[31m+";
    for (int i = 0; i < columnNames.size(); ++i) cout <<string(colWidth, '\033[31m-') << "\033[31m+";
    cout << endl;

    // Print headers with color
    cout << "\033[31m|";
    for (const string& header : columnNames) {
        cout << headerColor << setw(colWidth) << left << header << reset << "\033[31m|";
    }
    cout << endl;

    // Print header-bottom border
    cout << "\033[31m+";
    for (int i = 0; i < columnNames.size(); ++i) cout << string(colWidth,'\033[31m-') << "\033[31m+";
    cout << endl;

    // Print rows with color for price column
    for (const auto& row : data) {
        cout << "\033[31m|";
        for (int i = 0; i < row.size(); ++i) {
            if (i == 2) { // Apply color to the price column
                cout << priceColor << setw(colWidth) << left << row[i] << reset << "\033[31m|"<<reset;
            } else {
                cout << setw(colWidth) << left << row[i] << "\033[31m|"<<reset;
            }
        }
        cout << endl;

        // Print row border
        cout << "\033[31m+";
        for (int i = 0; i < columnNames.size(); ++i) cout << string(colWidth, '\033[31m-') << "\033[31m+";
        cout<<endl;
    }
    cout <<reset<<endl;
}

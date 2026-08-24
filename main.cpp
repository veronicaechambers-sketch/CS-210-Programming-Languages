#include <iostream>
#include <limits>
#include <string>

#include "ItemTracker.h"

using namespace std;

// Displays the four required menu choices.
void DisplayMenu() {
    cout << "\n=================================\n";
    cout << "   CORNER GROCER ITEM TRACKER\n";
    cout << "=================================\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display item histogram\n";
    cout << "4. Exit\n";
    cout << "---------------------------------\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Constructing the tracker reads the purchase file and creates frequency.dat.
    ItemTracker tracker;

    if (!tracker.IsReady()) {
        return 1;
    }

    int menuChoice = 0;

    while (menuChoice != 4) {
        DisplayMenu();

        // Validate numeric menu input to prevent the input stream from failing.
        if (!(cin >> menuChoice)) {
            cout << "Invalid input. Please enter a number from 1 through 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (menuChoice) {
        case 1: {
            string requestedItem;
            cout << "Enter the item you want to find: ";
            getline(cin, requestedItem);

            if (requestedItem.empty()) {
                cout << "No item was entered. Please try again.\n";
            }
            else {
                const int frequency = tracker.GetItemFrequency(requestedItem);
                cout << requestedItem << " was purchased " << frequency
                     << (frequency == 1 ? " time.\n" : " times.\n");
            }
            break;
        }
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Thank you for using the Corner Grocer Item Tracker.\n";
            break;
        default:
            cout << "Invalid selection. Please choose an option from 1 through 4.\n";
            break;
        }
    }

    return 0;
}

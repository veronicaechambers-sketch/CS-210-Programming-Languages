#include "ItemTracker.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

ItemTracker::ItemTracker(const string& inputFile, const string& outputFile)
    : inputFileName(inputFile), outputFileName(outputFile), dataLoaded(false) {
    dataLoaded = LoadInputFile();

    // The assignment requires the backup file to be created automatically.
    if (dataLoaded && !WriteBackupFile()) {
        cerr << "Warning: The backup file could not be created." << endl;
    }
}

string ItemTracker::NormalizeItem(const string& item) {
    // Remove surrounding whitespace so accidental spaces do not affect matching.
    const size_t firstCharacter = item.find_first_not_of(" \t\r\n");
    if (firstCharacter == string::npos) {
        return "";
    }

    const size_t lastCharacter = item.find_last_not_of(" \t\r\n");
    string normalized = item.substr(firstCharacter, lastCharacter - firstCharacter + 1);

    transform(normalized.begin(), normalized.end(), normalized.begin(),
              [](unsigned char character) {
                  return static_cast<char>(tolower(character));
              });

    return normalized;
}

string ItemTracker::FormatItemName(const string& item) {
    if (item.empty()) {
        return item;
    }

    string formatted = item;
    formatted[0] = static_cast<char>(toupper(static_cast<unsigned char>(formatted[0])));
    return formatted;
}

bool ItemTracker::LoadInputFile() {
    ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open " << inputFileName << "." << endl;
        cerr << "Make sure the input file is in the same folder as the program." << endl;
        return false;
    }

    string item;
    while (getline(inputFile, item)) {
        // Ignore empty lines so they are not counted as grocery items.
        const string normalizedItem = NormalizeItem(item);
        if (!normalizedItem.empty()) {
            ++itemFrequencies[normalizedItem];
        }
    }

    return true;
}

bool ItemTracker::WriteBackupFile() const {
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        return false;
    }

    for (const auto& entry : itemFrequencies) {
        outputFile << FormatItemName(entry.first) << ' ' << entry.second << '\n';
    }

    return true;
}

bool ItemTracker::IsReady() const {
    return dataLoaded;
}

int ItemTracker::GetItemFrequency(const string& item) const {
    const string normalizedItem = NormalizeItem(item);
    const auto foundItem = itemFrequencies.find(normalizedItem);

    if (foundItem == itemFrequencies.end()) {
        return 0;
    }

    return foundItem->second;
}

void ItemTracker::PrintAllFrequencies() const {
    cout << "\nITEM PURCHASE FREQUENCIES\n";
    cout << "-------------------------\n";

    for (const auto& entry : itemFrequencies) {
        cout << left << setw(15) << FormatItemName(entry.first)
             << entry.second << '\n';
    }
}

void ItemTracker::PrintHistogram() const {
    cout << "\nITEM PURCHASE HISTOGRAM\n";
    cout << "-----------------------\n";

    for (const auto& entry : itemFrequencies) {
        cout << left << setw(15) << FormatItemName(entry.first)
             << string(entry.second, '*') << '\n';
    }
}

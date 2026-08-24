#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

// ItemTracker reads grocery purchase records, counts each item,
// creates the required backup file, and displays frequency data.
class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies;
    std::string inputFileName;
    std::string outputFileName;
    bool dataLoaded;

    // Converts text to lowercase so searches are case-insensitive.
    static std::string NormalizeItem(const std::string& item);

    // Formats a normalized item name for user-friendly display.
    static std::string FormatItemName(const std::string& item);

    // Reads the input file and stores item counts in the map.
    bool LoadInputFile();

    // Creates frequency.dat automatically for backup purposes.
    bool WriteBackupFile() const;

public:
    ItemTracker(const std::string& inputFile = "CS210_Project_Three_Input_File.txt",
                const std::string& outputFile = "frequency.dat");

    // Returns true when the input file was loaded successfully.
    bool IsReady() const;

    // Returns the number of times a requested item was purchased.
    int GetItemFrequency(const std::string& item) const;

    // Prints every item followed by its numeric purchase frequency.
    void PrintAllFrequencies() const;

    // Prints every item followed by asterisks representing its frequency.
    void PrintHistogram() const;
};

#endif

// CSVWriter.cpp
#include "CSVWriter.h"
#include <fstream>
#include <iostream>



// Member function to set the file path
void CSVWriter::SetFilePath(const std::string& path) {
    filepath = path;
}

// Function to write a map of ItemID and Item to CSV
void CSVWriter::WriteToCSV(const std::map<ItemID, Item>& items) {
    if (filepath.empty()) {
        std::cerr << "File path is not set." << std::endl;
        return;
    }

    std::ofstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filepath << std::endl;
        return;
    }

    // Write the headers
    file << "ItemID,Name,Cost,Supply,Demand,FluctuatingCost\n";

    // Write each map entry
    for (const auto& [id, item] : items) {
        file << id << ',' << item.Name << ',' << item.Cost << ',' << item.Supply
            << ',' << item.Demand << ',' << item.FluctuatingCost << '\n';
    }

    file.close();
}

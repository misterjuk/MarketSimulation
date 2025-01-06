// CSVWriter.cpp
#include "CSVWriter.h"
#include <fstream>
#include <iostream>

CSVWriter::CSVWriter() : iteration(0), isFirstWrite(true) {
    // Initialize iteration and isFirstWrite flag
}

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

    // Open file, if it's the first write, truncate the file
    std::ofstream file;
    if (isFirstWrite) {
        file.open(filepath, std::ios::out | std::ios::trunc); // Truncate to clear the file
        isFirstWrite = false;  // After first write, set flag to false
    }
    else {
        file.open(filepath, std::ios::app);  // Append data for subsequent writes
    }

    if (!file.is_open()) {
        std::cerr << "Could not open file: " << filepath << std::endl;
        return;
    }

    // Write headers only if it's the first write operation
    /*if (isFirstWrite == false) {
        file << "Iteration,ItemID,ItemName,Cost,Supply,Demand,FluctuatingCost\n";
    }*/

    // Write the iteration number and data for each item
   /* for (const auto& [id, item] : items) {
        file << iteration << ','
            << id << ','
            << item.Name << ','
            << item.Cost << ','
            << item.Supply << ','
            << item.Demand << ','
            << item.FluctuatingCost << '\n';
    }*/

    for (const auto& [id, item] : items) 
    {
        file << item.FluctuatingCost << '\n';
    }

    // Increment iteration counter for the next call
    ++iteration;

    file.close();
}

// CSVWriter.h
#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <string>
#include <map>

#include "Item.h"

class CSVWriter {
public:
    // Default Constructor
    CSVWriter();

    // Destructor
    ~CSVWriter() = default;

    // Member function to set the file path
    void SetFilePath(const std::string& path);

    // Function to write a map of ItemID and Item to CSV
    void WriteToCSV(const std::map<ItemID, Item>& items);

private:

    int iteration = 0;
    std::string filepath{ "C:\\JukCo\\output.csv" };
    bool isFirstWrite{true};
};

#endif // CSV_WRITER_H

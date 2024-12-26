// CSVWriter.h
#ifndef CSV_WRITER_H
#define CSV_WRITER_H

#include <string>
#include <map>

#include "Item.h"

class CSVWriter {
public:
    // Default Constructor
    CSVWriter() = default;

    // Destructor
    ~CSVWriter() = default;

    // Member function to set the file path
    void SetFilePath(const std::string& path);

    // Function to write a map of ItemID and Item to CSV
    void WriteToCSV(const std::map<ItemID, Item>& items);

private:

    std::string filepath{ "C:\\JukCo\\output.csv" };
};

#endif // CSV_WRITER_H

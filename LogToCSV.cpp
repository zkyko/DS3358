#include "LogToCSV.h"
#include <fstream>
#include <ctime>
#include <iomanip>

void LogToCSV(const std::string &licensePlate, const std::string &parkingSpot,
              const std::string &status) {
    std::ofstream file;
    file.open("parking_log.csv", std::ios::app); // Open in append mode.

    // Get the current time.
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    // Write to the file with a timestamp, license plate, parking spot, and status.
    file << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "," << licensePlate << ","
         << parkingSpot << "," << status << "\n";

    file.close(); // Close the file after writing to it.
}

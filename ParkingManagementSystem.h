#ifndef PARKINGMANAGEMENTSYSTEM_H
#define PARKINGMANAGEMENTSYSTEM_H

#include <map>
#include <string>

class ParkingManagementSystem {
private:
  std::string *parkingSpots; // Array to store license plates
  int totalSpots;
  int nextAvailableSpot;
  std::map<std::string, int>
      parkingDatabase; // Maps license plates to parking spots

public:
ParkingManagementSystem(int totalSpots);
~ParkingManagementSystem(); // Destructor to release memory
void loadParkingDataFromFile(const std::string& filename); // Load parking data from CSV file
int assignParkingSpot(const std::string& licensePlate);
bool isFull() const;
bool isReturningCar(const std::string& licensePlate);
bool isSpotAvailable(int spotIndex) const;
bool isTimeLimitExpired(int spotIndex) const;
void removeCarFromSpot(int spotIndex); 
void updateEntryTime(int spotIndex);
void carLeaves(const std::string& licensePlate); // Declaration of the carLeaves function
void saveParkingDataToFile(const std::string& filename);
};

#endif // PARKINGMANAGEMENTSYSTEM_H

#include <iostream>
#include <unordered_map>
#include <string>

class ParkingManagementSystem {
private:
    std::unordered_map<std::string, int> parkingDatabase; // Maps license plates to parking spots
    int nextAvailableSpot = 0;
    const int totalSpots = 10; // Total number of parking spots

public:
    int assignParkingSpot(const std::string& licensePlate) {
        if (parkingDatabase.find(licensePlate) != parkingDatabase.end()) {
            return parkingDatabase[licensePlate]; // Return existing spot
        } else {
            if (nextAvailableSpot < totalSpots) {
                parkingDatabase[licensePlate] = nextAvailableSpot;
                return nextAvailableSpot++; // Assign new spot
            } else {
                return -1; // Parking full
            }
        }
    }
};

int main() {
    ParkingManagementSystem pms;
    std::string licensePlate;
    std::cout << "Enter the license plate or 'exit' to stop:" << std::endl;

    while (true) {
        std::cin >> licensePlate;
        if (licensePlate == "exit") break;
        int spot = pms.assignParkingSpot(licensePlate);
        if (spot != -1) {
            std::cout << "Car with license plate " << licensePlate << " parks at spot " << spot << "." << std::endl;
        } else {
            std::cout << "No available parking spots." << std::endl;
        }
    }
    return 0;
}

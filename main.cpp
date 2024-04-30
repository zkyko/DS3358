#include "LogToCSV.h"
#include "ParkingManagementSystem.h"
#include "UserInterface.h"
#include <ctime>
#include <fstream>
#include <iomanip>

int main() {
  UserInterface ui;
  ParkingManagementSystem pms(10); // Initialize with 10 parking spots

  ui.displayMessage("Welcome to the Car Park.");
  ui.displayMessage(
      "Please enter your license plate number or type 'exit' to quit.");

  std::string status;
  std::string parkingSpot;

  while (true) {
    std::string licensePlate = ui.getUserInput();

    if (licensePlate == "exit") {
      ui.displayMessage("Goodbye!");
      break;
    }

    int spot = pms.assignParkingSpot(licensePlate);
    if (spot != -1) {
      parkingSpot = std::to_string(spot);
      status = pms.isReturningCar(licensePlate) ? "Left" : "Parked";
      ui.displayMessage("Your car has been assigned to spot: " + parkingSpot);
    } else {
      parkingSpot = "None";
      status = "Full";
      ui.displayMessage("Sorry, there are no available parking spots.");
    }

    // Call LogToCSV to log the action here
    LogToCSV(licensePlate, parkingSpot, status);
  }
  return 0;
}

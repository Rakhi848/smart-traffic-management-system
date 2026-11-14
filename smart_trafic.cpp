#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class SmartTrafficSystem {

private:

    // One deque for each lane (stores vehicle names)
    map<string, deque<string> > vehicles;

    vector<string> lanes = {
        "North", "East", "South", "West"
    };

    int signalIndex = 0;
    string emergencyLane = "";
    int vehicleNo = 1;      // used to name vehicles V1, V2, ...
    int emergencyNo = 1;    // used to name emergency vehicles EMG1, EMG2, ...

public:

    // Constructor
    SmartTrafficSystem() {
        vehicles["North"];
        vehicles["South"];
        vehicles["East"];
        vehicles["West"];
    }

    // Add multiple normal vehicles (push_back)
    void addVehicle(string lane, int count) {

        if (vehicles.find(lane) == vehicles.end()) {
            cout << "Invalid lane!\n";
            return;
        }

        if (count <= 0) {
            cout << "Please enter a valid number of vehicles!\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            vehicles[lane].push_back("V" + to_string(vehicleNo++));
        }

        cout << count << " vehicles added to "
             << lane << " lane successfully!\n";
    }

    // Emergency handling (push_front)
    void emergency(string lane) {

        if (vehicles.find(lane) == vehicles.end()) {
            cout << "Invalid lane!\n";
            return;
        }

        // Emergency vehicle goes to the FRONT of the lane
        vehicles[lane].push_front("EMG" + to_string(emergencyNo++));

        emergencyLane = lane;

        cout << "\nEMERGENCY ALERT!\n";
        cout << "Emergency vehicle added at the front of " << lane << " lane.\n";
        cout << "Priority given to " << lane << " lane.\n";
        cout << "Green Signal: " << lane << endl;
    }

    // Let up to 5 vehicles pass from a lane (pop_front)
    void passVehicles(string lane) {

        int passed = 0;

        cout << "Vehicles passed: ";

        while (!vehicles[lane].empty() && passed < 5) {
            cout << vehicles[lane].front() << " ";
            vehicles[lane].pop_front();
            passed++;
        }

        cout << "\nTotal passed: " << passed << endl;
    }

    // Process traffic
    void processTraffic() {

        string lane;

        // Emergency priority
        if (emergencyLane != "") {

            lane = emergencyLane;

            cout << "\nEmergency lane processed: "
                 << lane << endl;

            passVehicles(lane);

            emergencyLane = "";

            return;
        }

        // Normal signal rotation
        for (int i = 0; i < 4; i++) {

            lane = lanes[signalIndex];

            signalIndex = (signalIndex + 1) % 4;

            if (!vehicles[lane].empty()) {

                cout << "\nGreen Signal: "
                     << lane << endl;

                passVehicles(lane);

                return;
            }
        }

        cout << "\nNo vehicles available!\n";
    }

    // Display traffic status
    void displayStatus() {

        cout << "\n========== TRAFFIC STATUS ==========\n";

        for (auto &lane : vehicles) {

            cout << lane.first << " Lane : "
                 << lane.second.size() << " vehicles  [ ";

            for (auto &v : lane.second) {
                cout << v << " ";
            }

            cout << "]\n";
        }

        cout << "====================================\n";
    }

    // Reset system
    void resetSystem() {

        for (auto &lane : vehicles) {
            lane.second.clear();
        }

        signalIndex = 0;
        emergencyLane = "";
        vehicleNo = 1;
        emergencyNo = 1;

        cout << "\nTraffic system reset successfully!\n";
    }
};

int main() {

    SmartTrafficSystem traffic;

    int choice;
    string lane;

    cout << "====================================\n";
    cout << "   SMART TRAFFIC MANAGEMENT SYSTEM  \n";
    cout << "====================================\n";

    while (true) {

        cout << "\n1. Add Vehicles\n";
        cout << "2. Emergency Vehicle\n";
        cout << "3. Process Traffic\n";
        cout << "4. Display Traffic Status\n";
        cout << "5. Reset System\n";
        cout << "6. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1: {
                int count;

                cout << "Enter lane (North/South/East/West): ";
                cin >> lane;

                cout << "How many vehicles do you want to add? ";
                cin >> count;

                traffic.addVehicle(lane, count);
                break;
            }

            case 2:

                cout << "Enter emergency lane: ";
                cin >> lane;

                traffic.emergency(lane);
                break;

            case 3:

                traffic.processTraffic();
                break;

            case 4:

                traffic.displayStatus();
                break;

            case 5:

                traffic.resetSystem();
                break;

            case 6:

                cout << "\nExiting Traffic Management System...\n";
                return 0;

            default:

                cout << "\nInvalid choice! Try again.\n";
        }
    }

    return 0;
}
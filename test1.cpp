#include <iostream>
using namespace std;

enum VehicleType
{
    Bike,
    Car
};

class Vehicle
{
private:
    string ownerName;
    string ownerAddress;

public:
    void ownerdetails(const string &name, const string &address)
    {
        ownerName = name;
        ownerAddress = address;
    }

    void showownerinfo() const
    {
        cout << "Owner Details:" << endl;
        cout << "----------------" << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Owner Address: " << ownerAddress << endl;
    }
};

class universalinsurance
{
private:
#define CURRENT_YEAR 2023

    double rateForOldVehicle = 2.0; // Premium rate for vehicles aged between 5 and 15 years (2%)
    double rateForNewVehicle = 0.0; // Premium rate for vehicles aged less than or equal to 2 years (0%)
    double premiumGreen = 15000;    // Additional premium for vehicles aged less than 1 year

public:
    void calculatePremium(VehicleType vehicleType, int vehiclePrice, int purchaseYear)
    {
        int vehicleAge = CURRENT_YEAR - purchaseYear;
        cout << "\t----------------------" << endl;
        cout << "Premium Calculation:" << endl;
        cout << "\t----------------------" << endl;
        cout << "Vehicle Type: " << (vehicleType == Bike ? "Bike" : "Car") << endl;
        cout << "Vehicle Price: Rs." << vehiclePrice << "/-" << endl;
        cout << "Purchase Year: " << purchaseYear << endl;
        cout << "Vehicle Age: " << vehicleAge << " years" << endl;

        double premium = 0.0;

        if (vehicleAge <= 2)
        {
            premium = rateForNewVehicle;
            cout << "Charges : Rs.0";
        }
        else if (vehicleAge > 2 && vehicleAge <= 5)
        {
            premium = (rateForOldVehicle * vehiclePrice) / 100;
        }
        else if (vehicleAge > 5 && vehicleAge <= 15)
        {
            premium = (2.5 * vehiclePrice) / 100;
        }
        else
        {
            premium = (2.5 * vehiclePrice) / 100 + premiumGreen;
            cout << "Green premium charges (Vehicle Age less than 1 year): Rs." << premiumGreen << "/-" << endl;
        }

        if (vehicleAge > 1)
        {
            cout << "Premium Charges: Rs." << premium << "/-" << endl;
        }
    }
};

int main()
{
    int vehiclePrice;
    char vehicleTypeChar;
    int purchaseYear;
    string ownerName;
    string ownerAddress;
 cout << endl
       << "\t -------------------------------------------------" << endl
       << "\t| Welcome to 'Universal Insurance'[PvT.LTD]       |\n"
       << "\t -------------------------------------------------" << endl;

    cout << "Enter vehicle type (B for bike, C for car): ";
    cin >> vehicleTypeChar;

    VehicleType vehicleType;
    if (vehicleTypeChar == 'B' || vehicleTypeChar == 'b')
    {
        vehicleType = Bike;
    }
    else if (vehicleTypeChar == 'C' || vehicleTypeChar == 'c')
    {
        vehicleType = Car;
    }
    else
    {
        cout << "Invalid vehicle type entered." << endl;
        return 1;
    }

    cout << "Enter vehicle price: Rs.";
    if (!(cin >> vehiclePrice))
    {
        cout << "Invalid vehicle price entered." << endl;
        return 1;
    }

    cout << "Enter vehicle purchase year: ";
    if (!(cin >> purchaseYear))
    {
        cout << "Invalid purchase year entered." << endl;
        return 1;
    }

    cout << "Enter owner name: ";
    cin.ignore();
    getline(cin, ownerName);
    cout << "Enter owner address: ";
    getline(cin, ownerAddress);

    Vehicle vehicle;
    vehicle.ownerdetails(ownerName, ownerAddress);

    universalinsurance insurance;

    cout << endl;
    vehicle.showownerinfo();
    cout << endl;

    insurance.calculatePremium(vehicleType, vehiclePrice, purchaseYear);

    return 0;
}

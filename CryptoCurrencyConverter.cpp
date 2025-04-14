#include <iostream>
#include <iomanip>
using namespace std;

double bitcointoUsd = 69881.95;
double ethereumtoUsd = 3685.53;
double dogecointoUsd = 0.1455;
double solanatoUsd = 161.57;
int userChoice;
double conversionAmount;
double conversionResult;

int main()
{

    // The user menu design of the program
    cout << "Welcome to the Crypto Currency Conversion Program!!" << endl;
    cout << "This program supports the following cryptocurrencies: Bitcoin, Ethereum, Dogecoin, and Solana." << endl;
    cout << "Please select the conversion you want to perform:" << endl;
    cout << "1. USD to Bitcoin" << endl;
    cout << "2. USD to Ethereum" << endl;
    cout << "3. USD to Dogecoin" << endl;
    cout << "4. USD to Solana" << endl;
    cout << "5. Bitcoin to USD" << endl;
    cout << "6. Ethereum to USD" << endl;
    cout << "7. Dogecoin to USD" << endl;
    cout << "8. Solana to USD" << endl;
    cout << "Please enter your choice:";
    cin >> userChoice;

    // Error handling if user input is not in the 1-8 range
    if (userChoice > 8 || userChoice < 1)
    {
        cout << "Invalid choice, please restart the program and try again." << endl;
        return 0;
    }

    cout << "Please enter the amount to convert: ";
    cin >> conversionAmount;

    // Error handling if user input is in the negatives
    if (conversionAmount < 0)
    {
        cout << "Bro that is an invalid input. Restart the program and try again." << endl;
        return 0;
    }

    // The conditional to carry out the currency conversion based on the user input
    switch (userChoice)
    {
    case 1:
        conversionResult = conversionAmount / bitcointoUsd;
        if (conversionResult > 1)
        {
            cout << "$" << conversionAmount << " is worth " << conversionResult << " Bitcoins" << endl;
        }
        else
        {
            cout << "$" << conversionAmount << " is worth " << conversionResult << " Bitcoin" << endl;
        }

        break;

    case 2:
        conversionResult = conversionAmount / ethereumtoUsd;
        {
            cout << "$" << conversionAmount << " is worth " << conversionResult << " Ethereum" << endl;
        }
        break;

    case 3:
        conversionResult = conversionAmount / dogecointoUsd;
        {
            cout << "$" << conversionAmount << " is worth " << conversionResult << " Dogecoin " << endl;
        }
        break;

    case 4:
        conversionResult = conversionAmount / solanatoUsd;
        {
            cout << "$" << conversionAmount << " is worth " << conversionResult << " Solana " << endl;
        }
        break;

    case 5:
        conversionResult = conversionAmount * bitcointoUsd;
        {
            cout << conversionAmount << " Bitcoin " << "is worth " << conversionResult << " USD " << endl;
        }
        break;

    case 6:
        conversionResult = conversionAmount * ethereumtoUsd;
        {
            cout << conversionAmount << " Ethereum " << "is worth " << conversionResult << " USD " << endl;
        }
        break;

    case 7:
        conversionResult = conversionAmount * dogecointoUsd;
        {
            cout << conversionAmount << " Dogecoin " << "is worth " << conversionResult << " USD " << endl;
        }
        break;

    case 8:
        conversionResult = conversionAmount * solanatoUsd;
        {
            cout << conversionAmount << " Solana " << "is worth " << conversionResult << " USD " << endl;
        }
        break;
    }

    cout << "Thank you for using the Crypto Currency Conversion program!!" << endl;

    return 0;
}

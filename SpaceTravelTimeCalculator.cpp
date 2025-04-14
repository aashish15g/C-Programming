
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    //	constant declarations
    const long LIGHTSPEED = 299792;        // speed of light in km per sec
    const long SEC_PER_YR = 31556926;      // number	of seconds in a year
    const long DISTANCE = 100000000000000; // distance	in	km
    const int CURRENT_YEAR = 2024;

    // variable declarations
    double lorentz;
    double shipDuration;
    double earthDuration;
    double velocity = 10000.0; // rocket velocity in km/sec
    double improvement = 0.0;
    double earthETA;
    int bestyear = 0;
    int maxwait = 0;
    double quickestETA;
    int bestTravelYear;

    // Introduction
    cout << " Welcome to the interplanetary travel calculator where we will help you find the optimal year to travel!\n";
    cout << " The journey is completely safe and your life is totally not at risk!\n";
    cout << " The distance to planet Tesla is 100 trillion km.\n";
    cout << " The current average rocket speed is 10000 km/sec.\n";

    // User input to get the increase in rocket speed
    cout << " What is the anual improvement in rocket speed each year ? (0-100): ";
    cin >> improvement;
    while (improvement < 0 || (improvement > 100))
    {
        cout << " Please try again. The input must be within 0 - 100 per year: ";
        cin >> improvement;
    }

    // User input for maximum wait time
    cout << " What is the maximum number of years you are willing to wait till departure? (0-20): ";
    cin >> maxwait;
    while (maxwait < 0 || (maxwait > 20))
    {
        cout << " Please try again. The input must be within 0 - 20: ";
        cin >> maxwait;
    }

    cout << " Start Year| Avg Speed| Earth ETA| Your ETA\n";
    // For loop to print the table
    for (int i = 0; i <= maxwait; ++i)
    {
        int yearofDeparture = CURRENT_YEAR + i;
        earthDuration = (DISTANCE / velocity) / SEC_PER_YR;
        lorentz = 1.0 / sqrt(1.0 - (velocity * velocity) / (LIGHTSPEED * LIGHTSPEED));
        shipDuration = earthDuration / lorentz;

        double arrivalYearEarth = yearofDeparture + earthDuration;
        double arrivalYearShip = yearofDeparture + shipDuration;

        // formating the table
        cout << setw(10) << yearofDeparture << "| "
             << setw(9) << fixed << setprecision(2) << velocity << "| "
             << setw(9) << fixed << setprecision(2) << arrivalYearEarth << "| "
             << setw(9) << fixed << setprecision(2) << arrivalYearShip << endl;

        // method to find the quickest year for travel
        if (i == 0 || arrivalYearShip < quickestETA)
        {
            quickestETA = arrivalYearShip;
            bestTravelYear = yearofDeparture;
            earthETA = arrivalYearEarth;
        }

        velocity += (LIGHTSPEED - velocity) * (improvement / 100.0);
    }
    cout << " To get there soonest, you should leave in " << bestTravelYear << ". You will arrive in year "
         << fixed << setprecision(2) << quickestETA << " your time " << "and year " << earthETA << " Earth time. " << endl;
    cout << " Thank you for using the interplanetary travel calculator!" << endl;

    return 0;
}

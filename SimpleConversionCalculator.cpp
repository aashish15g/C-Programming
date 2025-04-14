/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;


float furlongs = 0;
float firkins = 0;
float fortnights = 0;
float newfurlong_to_Meter = 0;
float newfirkins_to_Mass = 0;
float newfortnight_to_Time = 0;
float furlongstoFortnight = 0;
float metersperSecond = 0;
float wackyunitConversion = 0;
float firkinstoFemtoFirkins = 0;

int main()
{
    
    cout << "Welcome to the FFF to SI unit converter program" << endl;
    cout << "Please enter length in furlongs: ";
    cin  >> furlongs;
    cout << "Please enter mass in firkins: ";
    cin >> firkins;
    cout <<"Please enter time in fortnights: ";
    cin >> fortnights;
    
    //Unit Conversions
    
    newfurlong_to_Meter = furlongs * 201.168;
    newfirkins_to_Mass = firkins * 25.40117272;
    newfortnight_to_Time = fortnights * 1209600;
    furlongstoFortnight = furlongs / fortnights;
    metersperSecond = newfurlong_to_Meter / newfortnight_to_Time;
    firkinstoFemtoFirkins = firkins * 0.000000000000001;
    
    //converting values to SI
    
    cout << "------Converted Values------" << endl;
    cout << furlongs << " furlongs is: " << newfurlong_to_Meter << " meters" << endl;
    cout << firkins << " firkins is: " << newfirkins_to_Mass << " kilograms" << endl;
    cout << fortnights << " fortnights is: " << newfortnight_to_Time << " seconds" << endl;
    
    //FFF velocity to SI velocity 
    
    cout << "------Velocity Values------" << endl;
    cout << furlongstoFortnight << " furlongs per fortnight is: " << metersperSecond << " meters per second" << endl; 
    
    //Wacky Unit Conversions
    
    cout << "------Wacky Units------" << endl;
    cout << newfirkins_to_Mass << " kilograms is: " << firkinstoFemtoFirkins << " femtofirkins" << endl;
    cout << "Thank you for using the FFF to SI unit conversion calculator!";
    
    
    
    
    
    
    
    
    

    
}
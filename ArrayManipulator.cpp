
//------------------------------------------------------------
// Purpose: A simple menu-based program for processing
//          an array of integers in many different ways.  
//          Each array operation is implemented in a 
//          separate function and called in the main program. 
//
// Author: Aashish Ganeshkumar
//------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <cmath> 
using namespace std;

//------------------------------------------------------------
// This function takes in an array of integers and stores
// a random value between 0..range in each array location.
//------------------------------------------------------------
void randomize(int array[], const int size, const int range)
{
    for (int index = 0; index < size; index++)
        array[index] = random() % range;
}

//------------------------------------------------------------
// This function takes in an array of integers and prints
// their values out on one line.
//------------------------------------------------------------
void print(int array[], const int size)
{
    for (int index = 0; index < size; index++)
        cout << array[index] << " ";
    cout << endl;
}

//------------------------------------------------------------
// This function finds and returns the minimum value in the array.
//------------------------------------------------------------
int find_min(int array[], const int size)
{
    int minimum = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < minimum)
            minimum = array[i];
    }
    return minimum;
}

//------------------------------------------------------------
// This function finds and returns the maximum value in the array.
//------------------------------------------------------------
int find_max(int array[], const int size)
{
    int maximum = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > maximum)
            maximum = array[i];
    }
    return maximum;
}

//------------------------------------------------------------
// This function finds and returns the sum of the values in the array
//------------------------------------------------------------
int find_sum(int array[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }
    return sum;
}

//------------------------------------------------------------
// This function calculates and returns the sum of squares of all the numbers in the array.
//------------------------------------------------------------
int find_sum_squared(int array[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += array[i] * array[i];
    }
    return sum;
}

//------------------------------------------------------------
// This function counts and returns the number of even numbers in the array.
//------------------------------------------------------------
int count_num_even(int array[], const int size)
{
    int counting = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
            counting++;
    }
    return counting;
}

//------------------------------------------------------------
// This function counts and returns the number of odd numbers in the array.
//------------------------------------------------------------
int count_num_odd(int array[], const int size)
{
    int counting = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 != 0)
            counting++;
    }
    return counting;
}

//------------------------------------------------------------
// Supporting function that finds whether a number in the array is prime or not.
//------------------------------------------------------------
bool is_prime(const int N)
{
    bool is_prime = true;

    // 0 and 1 are not prime numbers
    if (N == 0 || N == 1)
        is_prime = false;

    // loop to check if n is prime by checking whether any
    // numbers between 2 and n/2 divide into it with no remainder
    // stop the loop as soon as you determine that it is not prime
    int i = 2;
    while ((is_prime == true) && (i <= N / 2))
    {
        if (N % i == 0)
            is_prime = false;
        i++;
    }
    return is_prime;
}
//------------------------------------------------------------
// This function counts and returns the number of prime numbers in the array.
//------------------------------------------------------------
int count_num_prime(int array[], const int size)
{
    int counting = 0;
    for (int i = 0; i < size; i++)
    {
        if (is_prime(array[i]))
            counting++;
    }
    return counting;
}

//------------------------------------------------------------
// This function searches for a value in the array and returns its location.
//------------------------------------------------------------
int search_value(int array[], const int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
            return i;
    }
    return -1;
}

//------------------------------------------------------------
// This function checks if the array is sorted in ascending order.
//------------------------------------------------------------
bool is_sorted(int array[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    
    return true;
}

//------------------------------------------------------------
// This function sorts the array in ascending order using selection sort.
//------------------------------------------------------------
void sort_array(int array[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }
        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}


//------------------------------------------------------------
// This function prints the command menu and reads user input.
//------------------------------------------------------------
int get_command()
{
    cout << "\nWelcome to our Simple Array Processing Program\n";
    cout << "     Your command options are:\n";
    cout << "     0 - Quit the program.\n";
    cout << "     1 - Print the array.\n";
    cout << "     2 - Randomize the array.\n";
    cout << "     3 - Find the minimum value in array.\n";
    cout << "     4 - Find the maximum value in array.\n";
    cout << "     5 - Find sum of all values in array.\n";
    cout << "     6 - Find sum of squares of all values in array.\n";
    cout << "     7 - Count number of even numbers in array.\n";
    cout << "     8 - Count number of odd numbers in array.\n";
    cout << "     9 - Count number of prime numbers in array.\n";
    cout << "    10 - Search the array for location of a specified value.\n";
    cout << "    11 - Check to see if the array is sorted in ascending order.\n";
    cout << "    12 - Sort the array in ascending order using selection sort.\n";
    cout << "\nEnter command: ";
    int command = 0;
    cin >> command;
    return command;
}

//------------------------------------------------------------
// The main function
//------------------------------------------------------------
int main()
{
    // Declare local variables
    const int DATA_SIZE = 25;
    int data[DATA_SIZE] = {0};
    int range = 0;
    int command = -1;

    // Loop processing user commands
    while (command != 0)
    {
        command = get_command();
        switch (command)
        {
            case 0:
                cout << "Have a nice day.\n";
                break;
            case 1:
                print(data, DATA_SIZE);
                break;
            case 2:
                cout << "Enter desired range: ";
                cin >> range;
                randomize(data, DATA_SIZE, range);
                cout << "Array has been randomized.\n";
                break;
            case 3:
                cout << "Minimum value = " << find_min(data, DATA_SIZE) << endl;
                break;
            case 4:
                cout << "Maximum value = " << find_max(data, DATA_SIZE) << endl;
                break;
            case 5:
                cout << "Sum of values = " << find_sum(data, DATA_SIZE) << endl;
                break;
            case 6:
                cout << "Sum of squares of values = " << find_sum_squared(data, DATA_SIZE) << endl;
                break;
            case 7:
                cout << "Count of even numbers = " << count_num_even(data, DATA_SIZE) << endl;
                break;
            case 8:
                cout << "Count of odd numbers = " << count_num_odd(data, DATA_SIZE) << endl;
                break;
            case 9:
                cout << "Count of prime numbers = " << count_num_prime(data, DATA_SIZE) << endl;
                break;
            case 10:
                int value;
                cout << "Enter desired value: ";
                cin >> value;
                int valLocation;
                valLocation = search_value(data, DATA_SIZE, value);
                if (valLocation == -1)
                    cout << "The value was NOT found in the array.\n";
                else
                    cout << "The value was found at location " << valLocation << ".\n";
                break;
            case 11:
                if (is_sorted(data, DATA_SIZE))
                    cout << "The array IS in sorted order.\n";
                else
                    cout << "The array is NOT in sorted order.\n";
                break;
            case 12:
                sort_array(data, DATA_SIZE);
                cout << "Array has been sorted.\n";
                break;
            default:
                cout << "Error,that is an invalid command brother.\n";
        }
    }
    return 0 ;
}
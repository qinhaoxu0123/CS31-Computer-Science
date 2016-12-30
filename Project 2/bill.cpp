////Project 2 Energy Calculator.

#include <iostream>
#include <string>

using namespace std;
// ask user to input data;
int main ()
{
    string name;
    string type;
    double energy;
    
    cout << "Customer Name: ";
    getline(cin, name);

//If an empty string was provided for the customer name:
    if(name == "" )
    {
        cout << "---"<< endl;
        cout << "You must enter a customer name. "<< endl;
        return 0;
    }
    
    cout << "Energy Used (in kilowatt hours): ";
    cin >> energy;
    cin.ignore (10000, '\n');
    
// If the power usage is negative:
    
    if(energy < 0 )
    {
        cout << "---"<< endl;
        cout << "The energy usage reading must be nonnegative. "<< endl;
        return 0;
    }
    
    cout << "Customer Type: ";
    getline (cin, type);
    
//If the customer type is neither Business nor Residential:
    
    if(type!= "Residential" && type != "Business")
    {
       cout << "---"<< endl;
       cout << "The customer type is not valid. "<< endl;
       return 0;
    }
    
    cout << "---" << endl;
    
// Caculation and print out the result based on the given data.
    
    double R_first = 14.95 + (4.50 * energy );
    double B_first = 19.95 + (7.50 * energy );
    double R_second = 59.95 + (energy-10)*9;
    double B_second = 94.95 + (energy-10)*15;
    double R_third =  149.95 + (energy-20)*15;
    double B_third = 244.95 + (energy-20)*20;

// the result need to fixed
    
    cout.setf (ios::fixed);
    cout.setf (ios::showpoint);
    cout.precision(2);
    
    
 /// conditions for the calculation 
    if (type== "Residential"&& energy <= 10)
    {
        cout << "The bill for " << name << " is $" << R_first << endl;
    }
    else if (type == "Business" && energy <=10)
    {
        cout << "The bill for " << name << " is $" << B_first << endl;
    }
    else if (type =="Residential" && energy > 10 && energy <= 20)
    {
        cout << "The bill for " << name << " is $" << R_second << endl;
        
    }
    else if(type == "Business" && energy > 10 && energy <= 20)
    {
        cout << "The bill for " << name << " is $" << B_second << endl;
        
    }
    else if (type == "Residential"  && energy >20 )
    {
        cout << "The bill for " << name << " is $" << R_third << endl;
        
    }
    else if (type == "Business" && energy > 20)
    {
        cout << "The bill for " << name << " is $" << B_third << endl;
        
    }

    
    
    
    
    
    
    
}

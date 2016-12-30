//
//  main.cpp
//  Project 1
//
//  Created by Qinhao Xu on 1/7/16.
//  Copyright © 2016 Qinhao Xu. All rights reserved.
//
include <iostream>
Using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
    int daysReviewed;
    int daysWithRain;
    int daysBelow50Degrees;
    
    cout << "How many days were reviewed?" ;
    cin >> daysReviewed;
    cout << "How many of these days were rainy? ";
    cin >> daysWithRain;
    cout << "How many of these days were colder than 50 degrees? ";
    cin >> daysBelow50Degrees;
    
    double pctRainy = 100.0 * daysWithRain / daysReviewed;
    double pctCold  = 100.0 * daysBelow50Degrees / daysReviewed;
    
    cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
    cout.precision(1);
    
    cout << endl;
    cout << pctRainy << "% were rainy." << endl;
    cout << pctCold << "% were cold." << endl;
    
    if (pctRainy > pctCold)
        cout << "It was rainy more often than it was cold." << endl;
    else
        cout << "It was cold more often than it rained." << endl;
}

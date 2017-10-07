//
//  main.cpp
//  PRG-4-25-Data-Usage-Overage-Costs
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A mobile phone service provider has three different data plans for its customers:
//
//  Package A:  For $39.99 per month, 4 gigabytes are provided. Additional data costs
//              $10 per gigabyte
//  Package B:  For $59.99 per month, 8 gigabytes are provided. Additional data costs
//              $5 per gigabyte.
//  Package C:  For $69.99 per month, unlimited data is provided.
//
//  Write a program that calculates a customer's monthly bill. It should ask which package
//  the customer has purchased and how many gigabytes were used. It should then display
//  the total amount due.
//
//  Input Validation: Be sure the user only selects package A, B, or C.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float fltTotalCost;
    
    const float FLT_COST_PLAN_A = 39.99f,
                FLT_COST_PLAN_B = 59.99f,
                FLT_COST_PLAN_C = 69.99f,
    
                FLT_COST_PLAN_A_OVERAGE = 10.00f,
                FLT_COST_PLAN_B_OVERAGE = 5.00f;
    
    int intPlanSelection,
        intOverage,
        intDataUsed;
    
    const int INT_CASE_A = 1,
              INT_CASE_B = 2,
              INT_CASE_C = 3,
    
              INT_DATACAP_A = 4,
              INT_DATACAP_B = 8;
    
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "Please select a data plan from the options below.\n"
         << "1. Plan A: $39.99, 4GB Monthly, $10.00 per gigabyte over\n"
         << "2. Plan B: $59.99, 8GB Monthly, $5.00 per gigabyte over\n"
         << "3. Plan C: $69.99, Unlimited\n";
    cin >> intPlanSelection;
    while(!cin || intPlanSelection < 1 || intPlanSelection > 3)
    {
        cout << "Please select a menu option(1-3):\n";
        cin.clear();
        cin.ignore();
        cin >> intPlanSelection;
    }
    
    cout << "Please enter the amount of data (GB) you used with whole numbers:\n";
    cin >> intDataUsed;
    while(!cin || intDataUsed < 0 || intDataUsed > 100)
    {
        cout << "Please enter the amount of data you used(0GB-100GB):\n";
        cin.clear();
        cin.ignore();
        cin >> intDataUsed;
    }
    
    switch(intPlanSelection)
    {
        case INT_CASE_A:
            cout << "Select Plan A.\n";
            if(intDataUsed > INT_DATACAP_A)
            {
                intOverage = intDataUsed - INT_DATACAP_A;
                fltTotalCost = (intOverage * FLT_COST_PLAN_A_OVERAGE) + FLT_COST_PLAN_A;
            }
            else
            {
                fltTotalCost = FLT_COST_PLAN_A;
            }
            cout << "Your cost for data usage this month is $"
            << fltTotalCost << endl;
            break;
        case INT_CASE_B:
            cout << "Select Plan B.\n";
            if(intDataUsed > INT_DATACAP_B)
            {
                intOverage = intDataUsed - INT_DATACAP_B;
                fltTotalCost = (intOverage * FLT_COST_PLAN_B_OVERAGE) + FLT_COST_PLAN_B;
            }
            else
            {
                fltTotalCost = FLT_COST_PLAN_B;
            }
            cout << "Your cost for data usage this month is $"
            << fltTotalCost << endl;
            break;
        case INT_CASE_C:
            cout << "Select Plan C.\n";
            
            fltTotalCost = FLT_COST_PLAN_C;
            
            cout << "Your cost for data usage this month is $"
            << fltTotalCost << endl;
            break;
    }
    
    return 0;
}






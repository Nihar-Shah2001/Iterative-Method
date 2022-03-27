// Iterative Method.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<math.h>
constexpr auto a1 = 5678.83;
constexpr auto a2 = 0.212;
constexpr auto mu0 = 1.3e-06;
using namespace std;
long double function(long double* phi, long double* H, long double* tau, long double* M, long int datapoints, long double B, long double C, long double D, long double E, long double F)
{
    long double error, A, taupredicted;
    error = 0;
    for (int j = 0; j < datapoints; j++)
    {
        A = (H[j]) / (a1 * pow((phi[j] * M[j]), a2));
        taupredicted = ((pow(A, B)) / ((pow(A, B)) + 1)) * ((C) * (pow(phi[j], D) * mu0 * (pow(M[j], E) * (pow(H[j], F)))));
        error += abs(tau[j] - taupredicted);
    }
    return error;
}
int main()
{
    long double lowerB, upperB, lowerC, upperC, lowerD, upperD, lowerE, upperE, lowerF, upperF, divB, divC, divD, divE, divF, B, C, D, E, F, Error = 1000000, AnsB = 0, AnsC = 0, AnsD = 0, AnsE = 0, AnsF = 0;
    long int datapoints;
    cout << "Enter the number of Data points: ";
    cin >> datapoints;
    long double* phi = new long double[datapoints];
    long double* H = new long double[datapoints];
    long double* tau = new long double[datapoints];
    long double* M = new long double[datapoints];
    ifstream indata;
    long double data;
    indata.open("Data.txt");
    indata >> data;
    for (int i = 0; i < datapoints; i++)                 //Takes Input from File Location Entered.
    {
        phi[i] = data;
        indata >> data;
        H[i] = data;
        indata >> data;
        tau[i] = data;
        indata >> data;
        M[i] = data;
        indata >> data;
    }
    indata.close();
    cout << "Enter the lower Bound for B: ";
    cin >> lowerB;
    cout << "Enter the upper bound for B: ";
    cin >> upperB;
    cout << "Enter the lower Bound for C: ";
    cin >> lowerC;
    cout << "Enter the upper bound for C: ";
    cin >> upperC;
    cout << "Enter the lower Bound for D: ";
    cin >> lowerD;
    cout << "Enter the upper bound for D: ";
    cin >> upperD;
    cout << "Enter the lower Bound for E: ";
    cin >> lowerE;
    cout << "Enter the upper bound for E: ";
    cin >> upperE;
    cout << "Enter the lower Bound for F: ";
    cin >> lowerF;
    cout << "Enter the upper bound for F: ";
    cin >> upperF;
    cout << "Enter the number of division of B required: ";
    cin >> divB;
    cout << "Enter the number of division of C required: ";
    cin >> divC;
    cout << "Enter the number of division of D required: ";
    cin >> divD;
    cout << "Enter the number of division of E required: ";
    cin >> divE;
    cout << "Enter the number of division of F required: ";
    cin >> divF;
    for (B = lowerB; B <= upperB; B += (upperB - lowerB) / divB)
    {
        for (C = lowerC; C <= upperC; C += (upperC - lowerC) / divC)
        {
            for (D = lowerD; D <= upperD; D += (upperD - lowerD) / divD)
            {
                for (E = lowerE; E <= upperE; E += (upperE - lowerE) / divE)
                {
                    for (F = lowerF; F <= upperF; F += (upperF - lowerF) / divF)
                    {
                        if (Error > (function(phi, H, tau, M, datapoints, B, C, D, E, F)))
                        {
                            Error = function(phi, H, tau, M, datapoints, B, C, D, E, F);
                            AnsB = B;
                            AnsC = C;
                            AnsD = D;
                            AnsE = E;
                            AnsF = F;
                        }
                    }
                }
            }
        }
    }
    cout << "\n \t Error = " << Error;
    cout << "\n \t B = " << AnsB << "\n \t C = " << AnsC << "\n \t D = " << AnsD << "\n \t E = " << AnsE << "\n \t F = " << AnsF;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

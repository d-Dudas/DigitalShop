// DigitalShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "Controlpanel.h"

int main()
{
    int run = 1, c;
    while (run) {
        std::cout << "1) Control Panel\n";
        std::cout << "2) User Interface\n";
        std::cout << "3) Exit\n";

        std::cout << "\nSELECT: "; std::cin >> c;

        switch (c)
        {
        case 1 :
            student1();
            break;
        case 2 :
            student2();
        default:
            run = 0;
            break;
        }
    }

    return 0;
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

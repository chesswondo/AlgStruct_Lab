#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>

#include "functions.h"

using namespace std;

int main()
{
    int num_task;
    while (true)
    {
        cout << "Enter the number of task you want to process:\n";
        cin >> num_task;

        switch (num_task)
        {
            case 1:
                process_task1();
                break;
            
            case 2:
                process_task2();
                break;

            case 3:
                process_task3();
                break;

            case 4:
                process_task4();
                break;

            case 7:
                process_task7();
                break;

            default:
                cout << "Incorrect number, retry\n\n";
                break;
        }


    }

    return 0;
}

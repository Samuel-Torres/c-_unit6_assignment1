#include <iostream>
#include <iomanip>
using namespace std;

const int MAXSIZE = 50;
typedef float TempArray[MAXSIZE];

float averageTemp(TempArray, int);
float highestTemp(TempArray, int);
float lowestTemp(TempArray, int);

int main()
{
    int n;
    TempArray temps;

    cout << "Please input the number of temperatures to be read" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Input temperature " << i + 1 << ":" << endl;
        cin >> temps[i];
    }

    cout << fixed << showpoint << setprecision(2);
    cout << "The average temperature is " << averageTemp(temps, n) << endl;
    cout << "The highest temperature is " << highestTemp(temps, n) << endl;
    cout << "The lowest temperature is " << lowestTemp(temps, n) << endl;

    return 0;
}

float averageTemp(TempArray arr, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / size;
}

float highestTemp(TempArray arr, int size)
{
    float high = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > high)
            high = arr[i];
    return high;
}

float lowestTemp(TempArray arr, int size)
{
    float low = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < low)
            low = arr[i];
    return low;
}

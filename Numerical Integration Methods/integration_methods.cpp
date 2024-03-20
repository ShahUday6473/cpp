#include <iostream>
#include <cmath>
using namespace std;

// Global variables
int function, interval, s; // Variables to store function, interval, and solution type
float lowLim, upLim;       // Variables to store lower and upper limits

// Function to choose the type of solution
void sol_type()
{
    cout << "Choose the type of solution:" << endl
         << "1.  Direct Answer" << endl
         << "2.  Detailed Solution" << endl;

    cin >> s; // User input for solution type

    switch (s)
    {
    case 1:
        cout << "Direct answer:" << endl;
        break;

    case 2:
        cout << "Your Detailed solution is:" << endl;
        break;
    }
}

// Function to choose the function for Simpson's (1/3)th rule and Trapezoidal rule
void fn1()
{
    cout << "Choose the function:" << endl
         << "1.  1/(x+y)" << endl
         << "2.  x^2 + y^2" << endl
         << "3.  (2x + 3y^2 )" << endl
         << "4.  (5x^2 - y)/(e^(x+y))" << endl
         << "5.  2x^2+3y^2 - 2" << endl
         << "6.  y+sqrt(x^2+y^2)" << endl
         << "You selected function no.:";

    cin >> function; // User input for function
}

// Function to choose the function for Simpson's (3/8)th rule
void fn()
{
    cout << "Choose the function:" << endl
         << "1.  1/(1+x)" << endl
         << "2.  1/(1+x^2)" << endl
         << "3.  e^x/(1 + x)" << endl
         << "4.  (cos x - log x + e^x)" << endl
         << "5.  x/(1+x)" << endl
         << "You selected function no.:";

    cin >> function; // User input for function
}

// Function to set the lower and upper limits and interval for integration
void setvalue()
{
    cout << "Enter Lower Limit:";
    cin >> lowLim; // User input for lower limit

    cout << "Enter Upper Limit:";
    cin >> upLim; // User input for upper limit

    cout << "Enter interval:";
    cin >> interval; // User input for interval

    cout << endl
         << endl;
}

// Function to calculate the function value for Simpson's (1/3)th rule and Trapezoidal rule
double rk4thFunc(double x, double y, int function)
{
    switch (function)
    {

    case 1:
        return (1 / (x + y)); // Calculation for function 1
        break;

    case 2:
        return ((x * x + y * y)); // Calculation for function 2
        break;

    case 3:
        return ((2 * x) + (3 * y * y)); // Calculation for function 3
        break;

    case 4:
        return (((5 * x * x) - y) / (exp(x + y))); // Calculation for function 4
        break;

    case 5:
        return (((2 * x * x) + (3 * y * y)) - 2); // Calculation for function 5
        break;

    case 6:
        return (y + sqrt(x * x + y * y)); // Calculation for function 6
        break;

    default:
        cout << "Error:Choose a valid code."; // Error message for invalid function
        break;
    }
}

// Function to calculate the function value for Simpson's (3/8)th rule
float mathFunc(float x, int function)
{

    switch (function)
    {

    case 1:
        return (1 + (1 / x)); // Calculation for function 1
        break;

    case 2:
        return (1 / (1 + (x * x))); // Calculation for function 2
        break;

    case 3:
        return (exp(x) / (1 + x)); // Calculation for function 3
        break;

    case 4:
        return (cos(x) - log(x) + exp(x)); // Calculation for function 4
        break;

    case 5:
        return (x + (1 / x)); // Calculation for function 5
        break;

    default:
        cout << "Error:Choose a valid code."; // Error message for invalid function
        break;
    }
}

// Function to calculate Simpson's (1/3)th rule
void Simpson1()
{

    fn();       // Choose the function
    sol_type(); // Choose the solution type
    setvalue(); // Set the lower and upper limits and interval

    int a, b, n;
    a = lowLim, b = upLim, n = interval;

    if (interval % 2 != 0)
    {
        cout << "Error: Interval for this method must be even.";
    }

    else
    {
        float h, res = 0.0, oddSum = 0.0, evenSum = 0.0, lim;
        int i;

        h = (b - a) / n; // calculate the distance between two interval

        res = (mathFunc(a, function) + mathFunc(b, function)); // initial sum using f(a) and f(b)

        lim = n / 2;

        if (s == 2)
        {

            cout << "h=" << h << endl
                 << "Yn=f[lower Limit + (n * h)] " << endl;

            for (int i = 0; i <= n; i++)
            {
                cout << "y" << i << ":" << mathFunc(a + (i * h), function) << endl;
            }
        }

        for (i = 1; i <= lim; i++)
        {
            oddSum += mathFunc(a + (2 * i - 1) * h, function); // sum of numbers, placed at odd number
        }

        if (s == 2)
        {
            cout << "Odd term sum:" << oddSum << endl;
        }

        oddSum *= 4; // odd sum are multiplied by 4

        for (i = 1; i < lim; i++)
        {
            evenSum += mathFunc(a + (2 * i) * h, function); // sum of numbers, placed at even number
        }

        if (s == 2)
        {
            cout << "Even term sum:" << evenSum << endl;
        }

        evenSum *= 2; // even sum are multiplied by 2

        res += oddSum + evenSum;
        res *= (h / 3);

        if (s == 2)
        {
            cout << "Answer = (h/3)*((first term + last term) + 4*(Odd Sum) + 2*(Even Sum))" << endl;
        }
        cout << "The answer is:" << res; // The result of integration
    }
}

// Function to calculate Simpson's (3/8)th rule
void Simpson2()
{
    fn();       // Choose the function
    sol_type(); // Choose the solution type
    setvalue(); // Set the lower and upper limits and interval

    if (interval % 3 == 0)
    {

        float interval_size = (upLim - lowLim) / interval;

        if (s == 2)
        {
            cout << "Yn=f[lower Limit + (n * h)] " << endl;

            for (int i = 0; i <= interval; i++)
            {
                cout << "y" << i << ":" << mathFunc(lowLim + i * interval_size, function) << endl;
            }

            cout << "Answer = {(3*h)*[(first term + last term) + (4 * sum of odd terms) + (2 * sum of even terms)]}/8" << endl;
        }

        float sum = mathFunc(lowLim, function) + mathFunc(upLim, function);

        for (int i = 1; i < interval; i++)
        {
            if (i % 3 == 0)
            {
                sum = sum + 2 * mathFunc(lowLim + i * interval_size, function);
            }

            else
            {
                sum = sum + 3 * mathFunc(lowLim + i * interval_size, function);
            }
        }

        cout << ((3 * interval_size / 8) * sum);
    }

    else
    {
        cout << "Error: Interval for this method must be multiple of '3'.";
    }
}

// Function to calculate Trapezoidal rule
void Trapezoidal_rule()
{
    float h, sum;
    fn();       // Choose the function
    sol_type(); // Choose the solution type
    setvalue(); // Set the lower and upper limits and interval

    h = (upLim - lowLim) / interval; // calculate the distance between two interval
    if (s == 2)
    {
        cout << "Yn=f[lowLim + (n * h)] " << endl
             << endl
             << "y0:" << mathFunc(lowLim, function) << endl;
    }
    sum = (mathFunc(lowLim, function) + mathFunc(upLim, function)) / 2; // initial sum using f(a) and f(b)

    for (int i = 1; i < interval; i++)
    {
        if (s == 2)
        {
            cout << "y" << i << ":" << mathFunc(lowLim + i * h, function) << endl;
        }
        sum += mathFunc(lowLim + i * h, function);
    }

    if (s == 2)
    {
        cout << "y" << interval << ":" << mathFunc(upLim, function) << endl;

        cout << "Answer = (h/2)*((first term + last term) + 2*(Remaining terms Sum))" << endl;
    }

    cout << "Answer:" << (h * sum); // The result of integration
}

// Function to perform Runge-Kutta 4th Order method
void rk4thOrder()
{
    fn1();      // Choose the function
    sol_type(); // Choose the solution type

    double k1, k2, k3, k4, k;
    double x0, y0, x, h;

    cout << "Enter x0 and [f(x0) = y0]: ";
    cin >> x0 >> y0;

    cout << "Enter x: ";
    cin >> x;

    cout << "Enter h: ";
    cin >> h;

    int iteration = int((x - x0) / h); // calculate number of iterations
    double y = y0;                     // initially y is f(x0)

    if (s == 2)
    {
        cout << endl
             << endl
             << "x = x0 + (h / 2)" << endl
             << "k1 = h * f(x0, y0)" << endl
             << "k2 = h * f[(x), (y0 + (k1 / 2)]" << endl
             << "k3 = h * f[(x), (y + (k2 / 2)]" << endl
             << "k4 = h * f[(x0 + h), (y + k3)]" << endl
             << " k = (1.0 / 6.0) * [k1 + (2 * (k2 + k3)) + k4]" << endl
             << "y = y0 + k" << endl
             << endl;
    }

    for (int i = 1; i <= iteration; i++)
    {

        cout << "For Y" << i << ":" << endl;

        k1 = h * rk4thFunc(x0, y, function);
        k2 = h * rk4thFunc((x0 + h / 2), (y + k1 / 2), function);
        k3 = h * rk4thFunc((x0 + h / 2), (y + k2 / 2), function);
        k4 = h * rk4thFunc((x0 + h), (y + k3), function);
        k = (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        y += double((k)); // update y using del y
        x0 += h;          // update x0 by h

        cout << "k1:" << k1 << endl
             << "k2:" << k2 << endl
             << "k3:" << k3 << endl
             << "k4:" << k4 << endl
             << "k:" << k << endl
             << "Answer:" << endl
             << "  y=" << y << endl
             << endl;
    }
}

// Main function
int main()
{
    int method;
    cout << "Choose the Method:" << endl
         << "1.  Simpson's (1/3)th rule" << endl
         << "2.  Simpson's (3/8)th rule" << endl
         << "3.  Trapezoidal rule" << endl
         << "4.  Runge-Kutta 4th Order rule" << endl
         << "You selected method no.:";
    cin >> method; // User input for method selection

    cout << endl
         << endl;
    switch (method)
    {
    case 1:
        cout << "Your selected method is 'Simpson's (1/3)th rule'" << endl;
        Simpson1(); // Perform Simpson's (1/3)th rule
        break;
    case 2:
        cout << "Your selected method is 'Simpson's (3/8)th rule'" << endl;
        Simpson2(); // Perform Simpson's (3/8)th rule
        break;
    case 3:
        cout << "Your selected method is 'Trapezoidal rule'" << endl;
        Trapezoidal_rule(); // Perform Trapezoidal rule
        break;

    case 4:
        cout << "Your selected method is 'Runge-Kutta 4th Order rule'" << endl;
        rk4thOrder(); // Perform Runge-Kutta 4th Order method
        break;
    default:
        cout << "Error:Choose a valid method.";
        break;
    }

    return 0;
}

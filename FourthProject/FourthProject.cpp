#include <iostream>

using namespace std;

int Myroot(double, double, double, double&, double&);

void quadraticSquare(){
    double x1;
    double x2;

    double a;
    cout << "Enter the first coefficient of a quadratic square: ";
    cin >> a;
    double b;
    cout << "Enter the second coefficient of a quadratic square: ";
    cin >> b;
    double c;
    cout << "Enter the third coefficient of a quadratic square: ";
    cin >> c;

    int ans = Myroot(a, b, c, x1, x2);
    if (ans > 0) {
        cout << "There are two roots of the equation:\t";
        cout << "x1: " << x1 << "\t";
        cout << "x2: " << x2 << endl;
    }
    else if (ans == 0) {
        cout << "There is only one root:\t";
        cout << "x: " << x1 << endl;
    }
    else {
        cout << "There are no roots of the equation" << endl;
    }
}

bool input(int &a, int &b) {
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    if (a==0 || b==0) {
        return false;
    }
    else if ((a+b<0 && a>0 && b>0)|| (a+b>0 && a<0 && b<0)) {
        return false;
    }
    return true;
}

int main()
{
    //quadraticSquare();

    int a=0, b=0;
    if (!input(a, b)) {
        cerr << endl<<"error";
        return 1;
    }
    int s = a + b;
    cout << "s: " << s << endl;
}

int Myroot(double a, double b, double c, double& x1, double& x2) {
    if (a != 0 && b != 0 && c != 0) {
        double discr = pow(b, 2) - 4 * a * c;
        if (discr < 0) {
            return -1;
        }
        else if (discr == 0) {
            x1 = -b / (2 * a);
            x2 = x1;
            return 0;
        }
        else {
            x1 = (-b - sqrt(discr)) / (2 * a);
            x2 = (-b + sqrt(discr)) / (2 * a);
            return 1;
        }
    }
    else {
        if (a == 0) {
            x1 = -c / b;
            x2 = x1;
            return 0;
        }
        else {
            if (b == 0 && c == 0) {
                x1 = 0;
                x2 = x1;
                return 0;
            }
            else if (b == 0) {
                if (-c / a < 0) {
                    return -1;
                }
                else {
                    x1 = sqrt(-c / a);
                    x2 = -sqrt(-c / a);
                    return 1;
                }
            }
            else {
                x1 = 0;
                x2 = -b / a;
                return 1;
            }
        }
    }
}
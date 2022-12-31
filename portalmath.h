#include <cmath>
#include <iostream>
using namespace std;
















//constant
const double pi = 3.1415926;
const double e = 2.7181828;
















//complex number and quaternion
struct complex_number
{
    double Re, Im;
};

double abs(complex_number z)
{
    return sqrt(z.Re * z.Re + z.Im * z.Im);
}

complex_number assign_value_complex_number(double a, double b)
{
    complex_number z;
    z.Re = a;
    z.Im = b;
    return z;
}

complex_number i = assign_value_complex_number(0, 1);

double argument(complex_number z)
{
    return atan(z.Im / z.Re);
}

void print(complex_number z, bool newline)
{
    
    if (z.Re == 0 && z.Im == 0)
    {
        cout << 0;
    }
    else if (z.Re == 0)
    {
        cout << z.Im << "i";
    }
    else if (z.Im == 0)
    {
        cout << z.Re;
    }
    else if (z.Im == 1)
    {
        cout << z.Re << "+i";
    }
    else if (z.Im == -1)
    {
        cout << z.Re << "-i";
    }
    else if (z.Im > 0)
    {
        cout << z.Re << "+" << z.Im << "i";
    }
    else
    {
        cout << z.Re << "-" << -z.Im << "i";
    }
    if (newline)
    {
        cout << endl;
    }
}

complex_number exp(complex_number z)
{
	complex_number u = assign_value_complex_number(z.Re * cos(z.Im), z.Re * sin(z.Im));
	return u;
}

complex_number log(complex_number z)
{
	double r = abs(z), theta = argument(z);
	complex_number u = assign_value_complex_number(log(r), theta);
	return u;
}

complex_number operator + (complex_number z1, complex_number z2)
{
	complex_number u = assign_value_complex_number(z1.Re + z2.Re, z1.Im + z2.Im);
	return u;
}

complex_number operator + (complex_number z1, double z2)
{
	complex_number u = assign_value_complex_number(z1.Re + z2, z1.Im);
	return u;
}

complex_number operator + (double z1, complex_number z2)
{
	complex_number u = assign_value_complex_number(z1 + z2.Re, z2.Im);
	return u;
}

complex_number operator - (complex_number z1, complex_number z2)
{
	complex_number u = assign_value_complex_number(z1.Re - z2.Re, z1.Im - z2.Im);
	return u;
}

complex_number operator - (complex_number z1, double z2)
{
	complex_number u = assign_value_complex_number(z1.Re - z2, z1.Im);
	return u;
}

complex_number operator - (double z1, complex_number z2)
{
	complex_number u = assign_value_complex_number(z1 - z2.Re, z2.Im);
	return u;
}

complex_number operator * (complex_number z1, complex_number z2)
{
    complex_number u;
    u.Re = z1.Re * z2.Re - z1.Im * z2.Im;
    u.Im = z1.Re * z2.Im + z1.Im * z2.Re;
    return u;
}

complex_number operator * (complex_number z1, double z2)
{
    complex_number u = assign_value_complex_number(z1.Re * z2, z1.Im * z2);
    return u;
}

void operator += (complex_number &z1, complex_number z2)
{
    z1.Re += z2.Re;
    z1.Im += z2.Im;
}

void operator += (complex_number &z1, double z2)
{
    z1.Re += z2;
}

void operator -= (complex_number &z1, complex_number z2)
{
    z1.Re -= z2.Re;
    z1.Im -= z2.Im;
}

void operator -= (complex_number &z1, double z2)
{
    z1.Re -= z2;
}

complex_number conjugate(complex_number z)
{
    complex_number u = assign_value_complex_number(z.Re, -z.Im);
    return u;
}

complex_number operator * (double z1, complex_number z2)
{
    complex_number u = assign_value_complex_number(z1 * z2.Re, z1 * z2.Im);
    return u;
}

bool operator == (complex_number z1, complex_number z2)
{
    if (z1.Re == z2.Re && z1.Im == z2.Im)
    {
        return true;
    }
    else
    {
        return false;
    }
}
















//algebra
long long factorial(int x)
{
    long long mul = 1;
    for (int t = 1; t <= x; t++)
    {
        mul *= t;
    }
    return mul;
}

double square(double x)
{
    return x * x;
}

double cube(double x)
{
    return x * x * x;
}

long long A(int n, int m)
{
    long long mul = 1;
    for (int t = n; t >= n - m + 1; t--)
    {
        mul *= t;
    }
    return mul;
}

long long C(int n, int m)
{
    return A(n, m) / factorial(m);
}
















//geometry
struct point
{
    double x_coordinate, y_coordinate;
};

double distance(point A, point B)
{
    return sqrt(square(A.x_coordinate - B.x_coordinate) + square(A.y_coordinate - B.y_coordinate));
}

point assign_value_point(double x, double y)
{
    point P;
    P.x_coordinate = x;
    P.y_coordinate = y;
    return P;
}

point O = assign_value_point(0, 0);

struct line
{
    point A, B;
};

double slope(line l)
{
	return (l.B.y_coordinate - l.A.y_coordinate) / (l.B.x_coordinate - l.A.x_coordinate);
}

struct triangle
{
	point A, B, C;
};

point complex_number_to_point(complex_number z)
{
    point P = assign_value_point(z.Re, z.Im);
    return P;
}
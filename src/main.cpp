
#include <main.hpp>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    cout << add<int>(5, 4) << endl;
    cout << add<double>(5.1, 4.1) << endl;
    vector<double> a = {5.3, 1.2, 5.4};
    vector<double> b = {0.1, -7.4, 2.3};
    cout << fixed << setprecision(15) << xdot(a.data(), b.data(), (MKL_INT)a.size()) << endl;
    cout << fixed << setprecision(15) << mydot(a.data(), b.data(), (MKL_INT)a.size()) << endl;
    return 0;
}

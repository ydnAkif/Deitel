#include <iostream>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{

    //a

    array<int, 10> counts;

    for (size_t i = 0; i < counts.size(); ++i)
    {
        counts[i] = 0;
        cout << counts[i] << " ";
    }
    cout << endl;
    cout << endl;

    //b

    array<int, 15> bonus = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (size_t j = 0; j < bonus.size(); ++j)
    {
        bonus[j] += 1;
        cout << bonus[j] << " ";
    }
    cout << endl;
    cout << endl;

    //c

    array<double, 12> monthlyTemperatures;

    cout << "Enter 12 temprature for mounths" << endl;

    for (double k = 0; k < monthlyTemperatures.size(); ++k)
    {
        cin >> monthlyTemperatures[k];

        cout << monthlyTemperatures[k] << "\370"
             << "C ";
    }
    cout << endl;
    cout << endl;

    //d

    array<int, 5>
        bestScores = {100, 95, 90, 85, 80};

    for (size_t l = 0; l < bestScores.size(); ++l)
    {
        cout << l + 1 << " ==> " << bestScores[l] << endl;
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <array>

using namespace std;

int main(int argc, char const *argv[])
{

    //a

    array<int, 10> counts = {0};

    cout << endl;

    //b

    array<int, 15> bonus = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    for (size_t j = 0; j < bonus.size(); ++j)
    {
        ++bonus[j];
        cout << bonus[j] << " ";
    }
    cout << endl;
    cout << endl;

    //c

    array<double, 12> monthlyTemperatures;

    cout << "Enter 12 temprature for mounths" << endl;

    for (double k : monthlyTemperatures)
    {
        cin >> k;

        cout << k
             << '\370'
             << "C ";
    }
    cout << endl;
    cout << endl;

    //d

    array<int, 5>
        bestScores = {100, 95, 90, 85, 80};

    for (size_t score : bestScores)
    {
        cout << score << '\t';
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int getDaysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)))
        return 29;
    return days[month];
}

int getDayIndex(string day) {
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    for (int i = 0; i < 7; i++)
        if (days[i] == day)
            return i;
    return 0;
}

void printCalendar(int startDay, int totalDays) {
    string days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    // Print header
    cout << "|---------------------------|" << endl;
    for (int i = 0; i < 7; i++)
        cout << "|" << days[i];
    cout << "|" << endl;
    cout << "|---------------------------|" << endl;

    // Calculate if we need to wrap days
    bool needWrap = false;
    int daysInFiveWeeks = 35 - startDay;
    int overflow = totalDays - daysInFiveWeeks;
    if (overflow > 0) needWrap = true;

    // Print calendar body
    int day = 1;
    int weekCount = 0;

    if (needWrap) {
        // Print first week with wrapped days
        cout << "|";
        for (int i = 0; i < 7; i++) {
            if (i < startDay) {
                if (daysInFiveWeeks < totalDays) {
                    cout << setw(2) << daysInFiveWeeks + 1 << " |";
                    daysInFiveWeeks++;
                } else {
                    cout << " - |";
                }
            } else {
                cout << setw(2) << day << " |";
                day++;
            }
        }
        cout << endl;
        cout << "|---------------------------|" << endl;
    } else {
        // Print first week normally
        cout << "|";
        for (int i = 0; i < 7; i++) {
            if (i < startDay)
                cout << " - |";
            else {
                cout << setw(2) << day << " |";
                day++;
            }
        }
        cout << endl;
        cout << "|---------------------------|" << endl;
    }
    weekCount++;

    // Print remaining weeks
    while (weekCount < 5) {
        cout << "|";
        for (int i = 0; i < 7 && day <= daysInFiveWeeks; i++) {
            cout << setw(2) << day << " |";
            day++;
        }
        while (day > daysInFiveWeeks && day % 7 != 1) {
            //cout << "  |";
            day++;
        }
        cout << endl;
        cout << "|---------------------------|" << endl;
        weekCount++;
    }
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string input;
        getline(cin, input);

        int day = stoi(input.substr(0, 2));
        int month = stoi(input.substr(3, 2));
        int year = stoi(input.substr(6, 4));
        string dayName = input.substr(11);

        int firstDay = (getDayIndex(dayName) - ((day - 1) % 7) + 7) % 7;
        int totalDays = getDaysInMonth(month, year);

        printCalendar(firstDay, totalDays);

        if (T > 0) cout << endl;
    }
    return 0;
}

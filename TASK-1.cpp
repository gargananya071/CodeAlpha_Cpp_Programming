#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int n, total_grade = 0, total_credit = 0;;
    double GPA;

    cout << "Enter number of courses : ";
    cin >> n;

    vector<int> course_grade(n), course_credit(n), final_grade(n);
    vector<string> course_name(n);

    for (int i=0; i<n; i++)
    {
        cout << "Enter name of course : ";
        cin.ignore();
        getline(cin, course_name[i]);

        cout << "Enter grade obtained by student in " << course_name[i] << ": ";
        cin >> course_grade[i];

        cout << "Enter credit of this course : ";
        cin >> course_credit[i];
        total_credit += course_credit[i];

        final_grade[i] = course_grade[i] * course_credit[i];
        total_grade += final_grade[i];
    }

    GPA = (double)total_grade / total_credit;

    cout << "\n\n\n======================================================================================================\n";
    cout << left << setw(40) << "COURSE" << setw(30) << "CREDIT" << setw(30) << "GRADE POINTS" << "\n";
    cout << "------------------------------------------------------------------------------------------------------\n";
    for (int i=0; i<n; i++)
    {
        transform(course_name[i].begin(), course_name[i].end(), course_name[i].begin(), ::toupper);
        cout << left << setw(40) << course_name[i] << setw(30) << course_credit[i] << setw(30) << final_grade[i] << "\n";
    }
    cout << "------------------------------------------------------------------------------------------------------\n\n";
    cout << left << setw(20) << "Total Grade Points " << setw(5) << ":" << total_grade << "\n";
    cout << left << setw(20) << "Total Credit " << setw(5) << ":" << total_credit << "\n";
    cout << left << setw(20) << "GPA " << setw(5) << ":" << GPA << fixed << setprecision(2) << "\n\n";
    cout << "======================================================================================================\n\n";

    return 0;

}

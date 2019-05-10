#include <iostream>
#include <vector>

using namespace std;

struct School{
    int count, number, nOfStudents;
};

int main() {

    int N, results = 0;
    int midRes;
    vector<School> schools;
    vector<int> betterThenMiddle;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        string buf;

        cin >> buf >> buf >> buf;

        int schoolNumber = stoi(buf);

        cin >> buf;

        int result = stoi(buf);

        results += result;

        int size = schools.size();
        bool ex = false;
        for (int j = 0; j < size; ++j) {
            if (schoolNumber == schools[j].number){
                schools[j].nOfStudents++;
                schools[j].count += result;

                ex = true;
                break;
            }
        }

        if (!ex){
            School school{};
            school.nOfStudents = 1;
            school.count = result;
            school.number = schoolNumber;

            schools.push_back(school);
        }
    }

    midRes = results /  N;
    int size = schools.size();
    for (int i = 0; i < size; ++i) {
        int mid = schools[i].count / schools[i].nOfStudents;

        if (mid > midRes){
            betterThenMiddle.push_back(schools[i].number);
        }
    }

    size = betterThenMiddle.size();
    if (size > 1){
        for (int i = 0; i < size; ++i) {
            cout << betterThenMiddle[i] << endl;
        }
    } else {
        cout << betterThenMiddle[0] << endl;
        cout << midRes;
    }

    return 0;
}
#include <iostream>
using namespace std;

void sortScores(double* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                double temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double averageScore(double* arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum / n;
}

int main() {
    int n;
    cout << "Enter number of test scores: ";
    cin >> n;

    double* scores = new double[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter score " << i + 1 << ": ";
        cin >> scores[i];
    }

    sortScores(scores, n);

    cout << "\nSorted Scores: ";
    for (int i = 0; i < n; i++) {
        cout << scores[i] << " ";
    }

    cout << "Average Score: " << averageScore(scores, n) << endl;

    delete[] scores;
    return 0;
}

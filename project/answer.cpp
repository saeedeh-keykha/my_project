#include <iostream>
#include <cmath>

using namespace std;

void Q1(){
    for(int i = 5; i <= 200; i += 5) {
        cout << i << endl;
    }
}

    double f(double x) {
        if (x > 1) {
            return x * x * x * x - 2 * x * x + 5 * x - 3;
        }
        else if (x == 1){
            return -2;
        }
        else {
            return 4 * x * x * x - x * (x + 1) - 1;
        }
    }

void Q3() {
    int num;
    cout << " Enter the desired one: ";
    cin >> num;

    bool isPrime = true;

    if (num <= 1) {
        isPrime = false;
    }
    for (int i = 2; i <= sqrt(num); i++){
        if (num % i == 0) {
            isPrime = false;
            break;
        }
    }
    if(isPrime)
        cout << num << "it is a prime number" << endl;
    else
        cout << num << "it is not a prime number" << endl;
}
void Q4() {
    int num;
    cout << "Enter the desired one: ";
    cin >> num;

    for (int i = num + 1; i <= num + 6; i++) {
        if(i % 2 == 0) {
            cout << i << endl;
        }
    }
}
void Q5() {
    int a, b;
    cout << " Enter the number a: ";
    cin >> a;
    cout << "Enter the number b: ";
    cin >> b;

    int result = 1;
    for (int i = 0; i < b; i++){
        result *= a;
    }
    cout << "a^b = " << result << endl;
}

void displayMenu() {
    cout << "_______________" << endl;
    cout << "choose one of the options below: " << endl;
    cout << "a. Q1: show 5, 10, ...,200 " << endl;
    cout << "b. Q2: f(x) " <<endl;
    cout << "c. Q3: prime number "<< endl;
    cout << "d. Q4: Tree Even numbers " << endl;
    cout << "e. Q5: a^b " << endl;
    cout << "_____________" << endl;
}

int main()
{
    long long studentNumbers;
    int questionNum;
    char continueAnswer;

    cout << "Enter student number: ";
    cin >> studentNumbers;

    if (to_string(studentNumbers).length() != 10){
        cout << "student number must be 10 digits. " << endl;
        return 1;
    }

    do{
        displayMenu();
        cout << "Enter the question number(1-5): ";
        cin >> questionNum;

        switch (questionNum) {
        case 1:
            Q1();
            break;
        case 2:
            {
                double x;
                cout << "Enter the value of x: ";
                cin >> x;
                cout << "f(" << x << ") = " << f(x) << endl;
            }
            break;
        case 3:
            Q3();
            break;
        case 4:
            Q4();
            break;
        case 5:
            Q5();
            break;
        default:
            cout << " Invalid, Enter a number between 1 and 5." << endl;
        }
        cout << "Do you want to continue (Y/N)? ";
        cin >> continueAnswer;
    }
    while (continueAnswer == 'y' || continueAnswer == 'Y' );
    cout << "the end" << endl;

    return 0;
}

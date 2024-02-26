// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 5F
// Add a function
// int largestTwinPrime(int a, int b);
// that returns the largest twin prime in the range a ≤ N ≤ b.
// If there is no twin primes in range, then return -1.

#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n){
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;

}


bool isTwinPrime(int n){
    
    while(isPrime(n)){ // check from the function isPrime

        if (isPrime(n - 2) || isPrime(n + 2)){
            return true; // returns true

        } else if (!isPrime(n + 2) && !isPrime(n - 2)){
            return false; // return false

        } else if (!isPrime(n)){
            return false; // return false

        } else {
            return true; // return true
        }

    }

    return false; // returns false
}

int largestTwinPrime(int a, int b){
    int largestTwin = -1;
    for (int i = b; i >= a; i--){ 
        if(isTwinPrime(i) && isPrime(i)){ // check from the function whether the number is prime and twin prime
            return i; // return the largest twin prime
        }

    }
    return largestTwin; // returns -1
}


int main() {

    int num_1, num_2;

    cout << "Enter the first number: ";
    cin >> num_1;

    cout << "Enter the second number: ";
    cin >> num_2;

    cout << largestTwinPrime(num_1, num_2) << endl;

    return 0;

}
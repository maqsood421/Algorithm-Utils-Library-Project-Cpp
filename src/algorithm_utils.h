#pragma once
#ifndef ALGORITHM_UTILS_H
#define ALGORITHM_UTILS_H

//headers
#include <string>
#include <cmath>

using std::string; 
using std::cin; 
using std::cout;


//swap function for all data types
template <class T> void _swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}


//reverse string and array
template <class T> void _reverse(T a[], int len) {

    if(len == 1)
        return;

    for(int i = 0; i < len / 2; ++i) {
        T temp = a[i];
        a[i] = a[len - 1 - i];
        a[len - 1 - i] = temp;
    }
}

void _reverseInt(int &a) {
    int ans = 0;
    while(a != 0) {
        int rem = a % 10;
        ans = ans * 10 + rem;
        a /= 10;
    }
    a = ans;
}


//find maximum number in array
template<class T> 
T _findMax(T a[], int len) {
    
    if(len == 1)
        return T();

    T Max = a[0];
    
    for(int i = 1; i < len; i++) {
        if(Max < a[i])
            Max = a[i];
    }

    return Max;
}


//find minimum number in array
template<class T>
T _findMin(T a[], int len) {

    if(len == 1)
        return T();

    T Min = a[0];
    
    for(int i = 1; i < len; i++) {
        if(Min > a[i])
            Min = a[i];
    }

    return Min;
}



//search in a array
template<class T> bool _linearSearch(T a[], int len, T target) {
    
    for(int i = 0; i < len; ++i) {
        if(a[i] == target)
            return true;
    }

    return false;
}



//fibonacci of n
long long _fibonacci(int n) {
    long long dp[n];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}   


//factorial of n
long long _factorial(int n) {
    long long dp[n];
    dp[0] = 1;
    for(auto i = 1; dp[i]; i++)
        dp[i] = dp[i] * i;

    return dp[n];
}

//function to check a number is even or not
bool _isEven(int n) {
    if(n & 1)
        return false;
    
    return true;
}


//check the array is sorted or not
template<class T> bool _isSorted(T a[], int len) {

    for(int i = 0; i < len/2; ++i) {
        if(!(a[i] <= a[len - 1 - i]))
            return false;
    }   
    return true;
}


//checking if string is uppercase or not
bool _isUppercase(const string s) {
    for(int i = 0; i < s.length(); ++i) {
        if(!(s[i] >= 'A' && s[i] <= 'Z'))
            return false;
    }   
    return true;
}


//checking if string is lowercase or not
bool _isLowercase(const string s) {
    for(int i = 0; i < s.length(); ++i) {
        if(!(s[i] >= 'a' && s[i] <= 'z'))
            return false;
    }   
    return true;
}



//binary search
template<class T> bool _binarySearch(T a[], int len, T target) {

    int low = 0, high = len - 1;

    if (!_isSorted<T>(a, len)) {
        return false;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2; 
        if (a[mid] > target) {
            high = mid - 1;
        }
        else if (a[mid] < target) {
            low = mid + 1;
        }
        else {
            return true; // Element found
        }
    }
    return false; // Element not found
}


//check if the number is prime or not
bool _isPrime(int n) {
    if(n < 0 || n == 1)
        return false;
    
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) 
            return false;
    }
    return true;
}


//function to sort array
template<class T>
void _sort(T *a, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}


#endif
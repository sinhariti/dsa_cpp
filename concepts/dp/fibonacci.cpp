// Fibonacci with time tracking
#include <iostream>
#include <chrono>  // for timing
using namespace std;
using namespace chrono;
#define MOD 1000000007
/*************  ✨ Windsurf Command ⭐  *************/
/**
 * Calculates the nth Fibonacci number using memoization.
 * 
 * @param n The position in the Fibonacci sequence to compute.
 * @param fib A reference to a vector used for memoization, initialized with -1.
 * @return The nth Fibonacci number.
 */

/*******  05e26911-626a-4439-82d8-8caf2790424a  *******/
int fibodp(int n , vector<int>& fib){
    if(n<=1) return n;
    if(fib[n]!=-1) return fib[n];
    return fib[n] = (fibodp(n-1, fib)+ fibodp(n-2, fib)) % MOD;
}
int fibo(int n){
    if(n <= 1) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Start timing
    auto start = high_resolution_clock::now();
    if(n < 40){
      cout << "Fibonacci sequence: ";
      for(int i = 0; i < n; i++){
          cout << fibo(i) << " ";
      }
    }

    // End timing
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cout << "\nTime taken: " << duration.count() << " ms" << endl;


    auto start2 = high_resolution_clock::now();

    cout << "Fibonacci DP: ";
    vector<int> fib(n+1, -1);
    cout << fibodp(n, fib) << " ";


    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);

    cout << "\nTime taken DP: " << duration2.count() << " ms" << endl;

    return 0;
}
// / A C++ Program to generate test cases for array filled with random numbers 
#include<bits/stdc++.h> 
using namespace std; 
  
// Define the number of runs for the test data generated 
#define test_cases 2
  
// Define the range of the array elements (arr[i]<=maxARR) 
#define maxARR 1000000
  
// Define the maximum number of array elements (n<=maxN)
#define maxN 10
  
int main() 
{ 
    freopen ("input.txt", "w", stdout); 
    
    //For random values every time 
    srand(time(NULL)); 

    printf("%d\n",test_cases);

    for (int i=1; i<=test_cases; i++) 
    { 
        // Number of array elements 
        int n = 1 + rand() % maxN; 

        // First print the number of array elements 
        printf("%d\n",n);

        // Then print the array elements separated by space 
        for(int j=1; j<=n; j++) 
            printf("%d ", rand() % maxARR); 
        printf("\n"); 
    } 
  
    // Uncomment the below line to store 
    // the test data in a file 
    fclose(stdout); 
    return(0); 
} 
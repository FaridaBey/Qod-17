//
//  main.cpp
//  Qod#17
//
//  Created by Farida Sherif on 16/05/2023.
//
#include<iostream>
using namespace std;

int cluster(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }

//    If the total sum is not even its not possible to divide the data points equally
    if (sum % 2 != 0) {
        return 0;
    }
    int m =sum / 2;
    int T[n + 1][m + 1];

    for (int i = 0; i <= n; ++i)
        T[i][0] = 1;
    
    for (int j = 1; j <= m; j++)
        T[0][j] = 0;
    
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            T[i][j] = T[i - 1][j] + T[i - 1][j - arr[i - 1]];
            if (arr[i - 1] < j)
                T[i][j] = T[i - 1][j];
                
                

        }
    }
    return (T[n][m*2])/2;
}

int main() {

    int data_points[] = {1,2,3,4,5,6,7};
    int n = 7;
    cout << "Output: " << cluster(data_points, n) << endl;

    return 0;
}
/*
 table parameters: number of elements, sum of all elements.
 
 cell definition: is the number of ways to divide the array of size n into two groups with equal sums m.
 
 Base case: if the target sum is 0.
 
time complexity is O(n*m), where n is the number of elements and m is the sum of all elements in the array divided 2, the time complexity is explained by the most dominant operation's position which is the comparison that happens inside the 2 loops "arr[i - 1] <= j".
 
 space complexity is O(n*m) as well as it uses a 2-d array of size n+ and m+1.
 */

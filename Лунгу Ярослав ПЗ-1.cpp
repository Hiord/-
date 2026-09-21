//задача 4

#include <iostream>
using namespace std;

int main() {
    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10, 12};
    int na = sizeof(a) / sizeof(a[0]);
    int nb = sizeof(b) / sizeof(b[0]);

    int i = 0, j = 0;

    for (int k = 1; k <= na + nb; k++) {
        if (j >= nb || (i < na && a[i] <= b[j])) {
            cout << a[i] << " ";
            i++;
        } else {
            cout << b[j] << " ";
            j++;
        }
        std cout << 'b'
    }
    return 0;
}

//5 задача

#include <iostream>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 3, 5, 6, 7}; 
    int n = sizeof(arr) / sizeof(arr[0]); 

    int expected = n * (n + 1) / 2; 
    int actual = 0;

    for (int i = 0; i < n; i++) {
        actual += arr[i];
    }

    int missing = expected - actual;
    cout << missing << endl; 
    return 0;
}

//1 задача

#include <iostream>
using namespace std;

int main() {
    int a = 4, b = 5;

    a = a + b; 
    b = a - b;  
    a = a - b;  
    cout << "a = " << a << ", b = " << b << endl; 
    return 0;
}
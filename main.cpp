#include <iostream>
#include <cmath>

template <typename T> const T pi = T(3.1415926535897932385L);

bool inPiRange(){
    std::cout << "Enter a number: " << std::endl;
    float x;
    std::cin >> x;
    if (x > pi<float>){
        std::cout << "bigger than pi" << std::endl;
        return false;
    } else {
        std::cout << "lesser than pi" << std::endl;
        return true;
    }
}

template <typename T> void bubblesort(T A[], int n){
    for (int i = 0; i < n - 1;i++)
        for (int j = n - 1; i < j; j--)
            if (A[j] < A[j - 1])
                std::swap(A[j], A[j - 1]);
}

template <typename T> void bubblesort1(T A[], int n){
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (A[j] < A[j - 1]){
                T temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
}

int main(){
    inPiRange();

    int A[5] = {5,1,8,13,27};
    int B[5] = {5,1,8,13,27};
    int n = sizeof(A) / sizeof(A[0]);

    bubblesort<int>(A, n);

    std::cout << "sorted array (bubblesort std): ";
    for (int i = 0; i < n; i++){
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    bubblesort1<int>(B, n);

    std::cout << "sorted array (bubblesort1): ";
    for (int i = 0; i < n; i++){
        std::cout << B[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
#include <iostream>
using namespace std;

int A[3][3][3];

void prinear() {
    for (int i{ 0 }; i < 3; i++) {
        for (int j{ 0 }; j < 3; j++) {
            for (int k{ 0 }; k < 3; k++) {
                cout << " |" << A[i][j][k];
            }
            cout << "|\n";
        }
        cout << "--------------\n";
    }
}

void multi(int (*p)[3][3]) {
    int* f = **p;
    p++;
    int* s = **p;
    p++;
    int* r = **p;
    int* fins = s + 9;
    int* inis = s;
    int* inir = r;
    int* fin = r + 9;
    int* finr = r + 3;

    
    while (r < fin) {
        *r = *r + (*f * *s);
        r++;
        s++;
        if (r == finr) {
            r = inir;
            f++;
        }
        if (s == fins) {
            inir = inir + 3;
            finr = finr + 3;
            r = inir;
            s = inis;
        }
    }
}


int main()
{
    for (int i{ 0 }; i < 3; i++) {
        for (int j{ 0 }; j < 3; j++) {
            A[0][i][j] = i+j+10;
        }
    }
    for (int i{ 0 }; i < 3; i++) {
        for (int j{ 0 }; j < 3;  j++) {
            A[1][i][j] = i + j+20;
        }
    }
    for (int i{ 0 }; i < 3; i++) {
        for (int j{ 0 }; j < 3; j++) {
            A[2][i][j] = 0;
        }
    }
    
    multi(A);
    prinear();
}

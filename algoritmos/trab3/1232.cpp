#include <iostream>
 
using namespace std;

void fill_matrix(char matrix[3][3], char letter) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix[i][j] = letter;
        }
    }
}

void print_matrix(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void copia_fileira(char m1[][3], char m2[][3], int linha1, int coluna1, int linha2, int coluna2) {
    if (linha1 != -1) {
        if (linha2 != -1) {
            for (int i = 0; i < 3; i++) {
                m1[linha1][i] = m2[linha2][i];
            }
        } else {
            for (int i = 0; i < 3; i++) {
                m1[linha1][i] = m2[i][coluna2];
            }
        }
    } else {
        if (linha2 != -1) {
            for (int i = 0; i < 3; i++) {
                m1[i][coluna1] = m2[linha2][i];
            }
        } else {
            for (int i = 0; i < 3; i++) {
                m1[i][coluna1] = m2[i][coluna2];
            }
        }
    }
}

// FORCA BRUTA

void r_left(char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    char aux[3][3];
    copia_fileira(aux, F, -1, 2, -1, 2);
    copia_fileira(F, D, -1, 2, -1, 2);
    copia_fileira(D, B, -1, 2, -1, 2);
    copia_fileira(B, U, -1, 2, -1, 2);
    copia_fileira(U, aux, -1, 2, -1, 2);
}

void r_right(char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    for (int i = 0; i < 3; i++){
        r_left(D, U , B, F);
    }
}

void l_left(char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    char aux[3][3];
    copia_fileira(aux, F, -1, 0, -1, 0);
    copia_fileira(F, U, -1, 0, -1, 0);
    copia_fileira(U, B, -1, 0, -1, 0);
    copia_fileira(B, D, -1, 0, -1, 0);
    copia_fileira(D, aux, -1, 0, -1, 0);
}

void l_right(char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    for (int i = 0; i < 3; i++){
        l_left(D, U , B, F);
    }
}

void f_left(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    char aux[3][3];
    copia_fileira(aux, U, 2, -1, 2, -1);
    copia_fileira(U, R, 2, -1, 2, -1);
    copia_fileira(R, D, 2, -1, 2, -1);
    copia_fileira(D, L, 2, -1, 2, -1);
    copia_fileira(L, aux, 2, -1, 2, -1);
}

void f_right(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    for (int i = 0; i < 3; i++) {
        f_left(R, L, D, U);
    }
}

void b_right(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    char aux[3][3];
    copia_fileira(aux, U, 0, -1, 0, -1);
    copia_fileira(U, R, 0, -1, 0, -1);
    copia_fileira(R, D, 0, -1, 0, -1);
    copia_fileira(D, L, 0, -1, 0, -1);
    copia_fileira(L, aux, 0, -1, 0, -1);
}

void b_left(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    for (int i = 0; i < 3; i++) {
        b_right(R, L, D, U);
    }
}
 
int main() {
    char R[3][3], L[3][3], D[3][3], U[3][3], B[3][3], F[3][3];
    
    // posicoes iniciais

    fill_matrix(R, 'r');
    fill_matrix(L, 'l');
    fill_matrix(D, 'd');
    fill_matrix(U, 'u');
    fill_matrix(B, 'b');
    fill_matrix(F, 'f');

    // relacoes

    r_left(D, U , B, F);
    r_right(D, U, B, F);

    l_left(D, U, B, F);
    l_right(D, U, B, F);

    f_left(R, L, D, U);
    f_right(R, L, D, U);

    b_left(R, L, D, U);

    cout << "R" << endl;
    print_matrix(R);
    cout << "L" << endl;
    print_matrix(L);
    cout << "D" << endl;
    print_matrix(D);
    cout << "U" << endl;
    print_matrix(U);
    cout << "B" << endl;
    print_matrix(B);
    cout << "F" << endl;
    print_matrix(F);

    return 0;
}
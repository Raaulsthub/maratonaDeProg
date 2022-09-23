#include <iostream>
#include <string.h> 

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

void inicialize_cube(char R[3][3], char L[3][3], char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    fill_matrix(R, 'r');
    fill_matrix(L, 'l');
    fill_matrix(D, 'd');
    fill_matrix(U, 'u');
    fill_matrix(B, 'b');
    fill_matrix(F, 'f');
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

// f F b B u U


void r_left(char D[3][3], char U[3][3], char B[3][3], char F[3][3]) {
    char aux[3][3];
    copia_fileira(aux, F, -1, 2, -1, 2);
    copia_fileira(F, D, -1, 2, -1, 2);
    copia_fileira(D, B, -1, 2, -1, 0);
    copia_fileira(B, U, -1, 0, -1, 2);
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
    copia_fileira(U, B, -1, 0, -1, 2);
    copia_fileira(B, D, -1, 2, -1, 0);
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
    copia_fileira(U, L, 2, -1, -1, 2);
    copia_fileira(L, D, -1, 2, 0, -1);
    copia_fileira(D, R, 0, -1, -1, 0);
    copia_fileira(R, aux, -1, 0, 2, -1);
}

void f_right(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    for (int i = 0; i < 3; i++) {
        f_left(R, L, D, U);
    }
}

void b_right(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    char aux[3][3];
    copia_fileira(aux, U, 0, -1, 0, -1);
    copia_fileira(U, L, 0, -1, -1, 0);
    copia_fileira(L, D, -1, 0, 2, -1);
    copia_fileira(D, R, 2, -1, -1, 2);
    copia_fileira(R, aux, -1, 2, 0, -1);
}

void b_left(char R[3][3], char L[3][3], char D[3][3], char U[3][3]) {
    for (int i = 0; i < 3; i++) {
        b_right(R, L, D, U);
    }
}

void u_left(char R[3][3], char L[3][3], char B[3][3], char F[3][3]) {
    char aux[3][3];
    copia_fileira(aux, F, 0, -1, 0, -1);
    copia_fileira(F, R, 0, -1, 0, -1);
    copia_fileira(R, B, 0, -1, 0, -1);
    copia_fileira(B, L, 0, -1, 0, -1);
    copia_fileira(L, aux, 0, -1, 0, -1);
}

void u_right(char R[3][3], char L[3][3], char B[3][3], char F[3][3]) {
    for (int i = 0; i < 3; i++) {
        u_left(R, L, B, F);
    }
}

void d_left(char R[3][3], char L[3][3], char B[3][3], char F[3][3]) {
    char aux[3][3];
    copia_fileira(aux, F, 2, -1, 2, -1);
    copia_fileira(F, L, 2, -1, 2, -1);
    copia_fileira(L, B, 2, -1, 2, -1);
    copia_fileira(B, R, 2, -1, 2, -1);
    copia_fileira(R, aux, 2, -1, 2, -1);
}

void d_right(char R[3][3], char L[3][3], char B[3][3], char F[3][3]) {
    for (int i = 0; i < 3; i++) {
        d_left(R, L, B, F);
    }
}

int matrix_compare(char a[3][3], char b[3][3]) {
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] != b[i][j]) return 0;
        }
    }
    return 1;
}



int main() {
    char R[3][3], L[3][3], D[3][3], U[3][3], B[3][3], F[3][3];
    char RC[3][3], LC[3][3], DC[3][3], UC[3][3], BC[3][3], FC[3][3];
    
    // posicoes iniciais

    inicialize_cube(R, L, D, U, B, F);
    inicialize_cube(RC, LC, DC, UC, BC, FC);



    char sequence[81];

    cin >> sequence;

    int times = 1;

    do {
        for (int i = 0; i < strlen(sequence); i++) {
            switch (sequence[i])
            {
            case 'R':
                r_left(D, U, B, F);
                break;
            case 'r':
                r_right(D, U, B, F);
                break;
            case 'L':
                l_left(D, U, B, F);
                break;
            case 'l':
                l_right(D, U, B, F);
                break;
            case 'F':
                f_left(R, L, D, U);
                break;
            case 'f':
                f_right(R, L, D, U);
                break;
            case 'B':
                b_left(R, L, D, U);
                break;
            case 'b':
                b_right(R, L, D, U);
                break;
            case 'U':
                u_left(R, L, B, F);
                break;
            case 'u':
                u_right(R, L, B, F);
                break;
            case 'D':
                d_left(R, L, B, F);
                break;
            case 'd':
                d_right(R, L, B, F);
            default:
                break;
            }
        }
        if(matrix_compare(R, RC) == 1 && matrix_compare(L, LC) == 1 && matrix_compare(D, DC) == 1 &&
            matrix_compare(U, UC) == 1 && matrix_compare(B, BC) == 1 && matrix_compare(F, FC) == 1) 
        {
            break;
        }
        times++;
    } while(true);

    cout << times << endl;
    
    return 0;
}
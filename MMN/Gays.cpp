//
// Created by evgenii on 28.03.17.
//

#include "Gays.h"

int gays(vector<vector<double>> matrix, vector<double> B, vector<double> &R, int n) {
    double mass[n][n + 1];
    double res[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mass[i][j] = matrix[i][j];
        }
        mass[i][n] = B[i];
    }

    for(int k = 0; k < n - 1; k++) {
#ifdef mod
#if mod == 1
        // поиск наибольшего числа в столбце
        double max = fabs(mass[k][k]);
        int idx = k;
        for (int i = k + 1; i < n; ++i) {
            double tmp = fabs(mass[i][k]);
            if(tmp > max) {
                max = tmp;
                idx++;
            }
        }
        //обмен строк
        for (int l = 0; l < n + 1; ++l) {
            double tmp = mass[idx][l];
            mass[idx][l] = mass[k][l];
            mass[k][l] = tmp;
        }
#endif
#endif
        for (int i = k + 1; i < n; i++) {
            if (mass[k][k] == 0) { // если диагональный элемент равен нулю
                int j;
                //поиск строки замены
                for (j = k + 1; j < n || mass[k][j] == 0; j++);
                if (j == n) {
                    return 3;
                }
                //обмен строк
                for (int l = 0; l < n + 1; ++l) {
                    double tmp = mass[j][l];
                    mass[j][l] = mass[k][l];
                    mass[k][l] = tmp;
                }
            }
            double koef = mass[i][k] / mass[k][k];
            for (int j = k; j <= n; j++) {
                double c = mass[i][j] - (mass[k][j] * koef);
                if (fabs(c) < accuracy) {
                    mass[i][j] = 0;
                }
                else {
                    mass[i][j] = c;
                }
            }
        }
    }

    // проверка на нулевую строку
    for (int i = 0; i < n; ++i) {
        if (mass[i][0] == 0) {
            int col = 1;
            for (int j = 1; j < n + 1; ++j) {
                if (mass[i][j] == 0) {
                    col++;
                }
            }
            if (col == n + 1) {
                return 4;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        double tmp = mass[i][n];
        for (int j = n - 1; j >= 0; --j) {
            if (j != i) {
                tmp -= res[j] * mass[i][j];
            }
        }
        res[i] = tmp / mass[i][i];
        if (fabs(res[i]) < accuracy) {
            res[i] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        R[i] = res[i];
    }
    return 0;
}
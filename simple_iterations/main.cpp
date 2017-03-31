#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

long double eps;

#define mod 1

#define type_iteration 2

long double matrix_norm(vector<vector<long double>> matrix);
long double matrix_norm(vector<vector<long double>> matrix) {
    vector<long double> tmp(matrix.size());
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            tmp[i] += abs(matrix[i][j]);
        }
    }
    long double maximum = tmp[0];
    for (int i = 1; i < tmp.size(); ++i) {
        if (tmp[i] > maximum) {
            maximum = tmp[i];
        }
    }
    return maximum;
}

long double vector_norm(vector<long double> vec);
long double vector_norm(vector<long double> vec) {
    long double maximum = 0;
    if (vec.size() > 0) {
        maximum = abs(vec[0]);
        for (int i = 1; i < vec.size(); ++i) {
            if (abs(vec[i]) > maximum) {
                maximum = abs(vec[i]);
            }
        }
    }
    return maximum;
}

int enter_slay(const char *name_f, vector<vector<long double>> &slay, unsigned int &size, long double &eps);
int enter_slay(const char *name_f, vector<vector<long double>> &slay, unsigned int &size, long double &eps) {
    ifstream input;
    input.open(name_f, ios_base::in);
    if (!input.is_open()) {
        cout << "Ошибка при открытии файла" << endl;
        return -1;
    }
    input >> size;
    cout << "Размер матрицы: " << size << endl;
    input >> eps;
    cout << "Точность: " << eps << endl;

    slay.resize (size);
    for (int i = 0; i < size; i++) {
        slay[i].resize (size + 1);
        for (int j = 0; j < size + 1; j++) {
            input >> slay[i][j];
        }
    }
    return 0;
}
void print_matrix(vector<vector<long double>> matrix);

void print_matrix(vector<vector<long double>> matrix) {
    for (auto col : matrix) {
        for (auto row : col) {
            cout << row << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_vector(vector<long double> vector_t);

void print_vector(vector<long double> vector_t) {
    for (auto iter : vector_t) {
        cout << iter << endl;
    }
    cout << endl;
}

int multiplication_matrix_vector(vector<long double> &out, vector<vector<long double>> inp, vector<long double> vec);

int multiplication_matrix_vector(vector<long double> &out, vector<vector<long double>> inp, vector<long double> vec) {
    if (inp.size() != vec.size()) {
        return -1;
    }
    out.resize(vec.size());
    int i = 0;
    for (auto col : inp) {
        for (int j = 0; j < col.size(); j++) {
            out[i] += col[j] * vec[j];
        }
        i++;
    }
    return 0;
}
int difference_vector(vector<long double> &res, vector<long double> &vector1, vector<long double> &vector2);

int difference_vector(vector<long double> &res, vector<long double> &vector1, vector<long double> &vector2) {
    if (vector1.size() != vector2.size()) {
        return -1;
    }
    else if (vector1.size() != res.size()) {
        return -1;
    }
    for (int i = 0; i < vector1.size(); i++) {
        res[i] = vector1[i] - vector2[i];
    }
    return 0;
}

int return_matrix(vector<vector<long double>> &matrix, vector<vector<long double>> slay, unsigned long size_matrix);

int return_matrix(vector<vector<long double>> &matrix, vector<vector<long double>> slay, unsigned long size_matrix) {
    if (slay.size() < size_matrix) {
        return -1;
    }
    for (auto col : slay) {
        if (col.size() < size_matrix) {
            return -1;
        }
    }
    matrix.resize(size_matrix);
    for (int i = 0; i < size_matrix; i++) {
        matrix[i].resize(size_matrix);
    }
    for (int i = 0; i < size_matrix; i++) {
        for (int j = 0; j < size_matrix; j++) {
            matrix[i][j] = slay[i][j];
        }
    }
    cout << endl;
    return 0;
}
int return_vector(vector<long double> &vec, vector<vector<long double>> slay, unsigned long numbeer_vec);

int return_vector(vector<long double> &vec, vector<vector<long double>> slay, unsigned long numbeer_vec) {
    if (slay.size() < numbeer_vec - 1) {
        return -1;
    }
    for (auto col : slay) {
        if (col.size() < numbeer_vec - 1) {
            return -1;
        }
    }
    vec.resize(numbeer_vec - 1);

    int i = 0;
    for (auto col : slay) {
        vec[i] = col[numbeer_vec - 1];
        i++;
    }
    return 0;
}
int diagonal_one(vector<vector<long double>> &slay, unsigned long size_matrix);

int diagonal_one(vector<vector<long double>> &slay, unsigned long size_matrix) {
    for (int i = 0; i < size_matrix; i++) {
        if (slay[i][i] == 0) {
            if (i != size_matrix - 1) {
                int j;
                for (j = i + 1; (slay[j][i] == 0) && (j + 1 < size_matrix); j++);
                if (j == size_matrix - 1) {
                    cout << "Система несовместна" << endl;
                    return -1;
                }
                vector<long double> tmp;
                tmp = slay[i];
                slay[i] = slay[j];
                slay[j] = tmp;
            } else {
                int j;
                for (j = i - 1; (slay[j][i] == 0) && (j > 0); j--);
                if (j < 0) {
                    cout << "Система несовместна" << endl;
                    return -1;
                }
                vector<long double> tmp;
                tmp = slay[i];
                slay[i] = slay[j];
                slay[j] = tmp;
            }
        }
    }
    for (int i = 0; i < size_matrix; i++ ) {
        long double temp = slay[i][i];
        for(int j = 0; j < size_matrix + 1; j++){
            if(temp != 0)
                slay[i][j] /= temp;
        }
    }
    return 0;
}
int partition_matrix(vector<vector<long double>> &matrix, vector<vector<long double>> &one_matrix, unsigned long size_matrix);

int partition_matrix(vector<vector<long double>> &matrix, vector<vector<long double>> &one_matrix, unsigned long size_matrix) {
    one_matrix.resize(size_matrix);
    for(int i = 0; i < size_matrix; i++) {
        one_matrix[i].resize(size_matrix);
        one_matrix[i][i] = 1;
        matrix[i][i] = 0;
    }
    return 0;
}

int iteration(vector<long double> &res, vector<vector<long double>> matrix, vector<long double> B);

int iteration(vector<long double> &res, vector<vector<long double>> matrix, vector<long double> B) {
    res.resize(B.size());
    vector<long double> tmp;
    tmp.resize(B.size());
    multiplication_matrix_vector(tmp, matrix, res);
    difference_vector(res, B, tmp);
    print_vector(res);
    return 0;
}

int zeidel_iteration(vector<long double> &res, vector<vector<long double>> matrix, vector<long double> B);
int zeidel_iteration(vector<long double> &res, vector<vector<long double>> matrix, vector<long double> B) {
    res.resize(B.size());
    int i = 0;
    for (auto col : matrix) {
        long double tmp = 0;
        for (int j = 0; j < col.size(); j++) {
            tmp += col[j] * res[j];
        }
        res[i] = B[i] - tmp;
        i++;
    }
    return 0;
}

long long int count_step(vector<vector<long double >> matrix, vector<long double> B, long double eps);
long long int count_step(vector<vector<long double >> matrix, vector<long double> B, long double eps){
    long double norm_m = matrix_norm(matrix);
    long double norm_v = vector_norm(B);
    long long int N = (long long int) ((log(eps * (1 - norm_m) / norm_v) / log(norm_m)) + 1);
    return N;
}

int main()
{
    unsigned int size;
    vector<vector<long double>> slay;

    enter_slay("../matrix.txt", slay, size, eps);

    cout << "slay: " << endl;
    print_matrix(slay);

    diagonal_one(slay, size);
    cout << "slay diagonal one: " << endl;
    print_matrix(slay);

    vector<vector<long double>> matrix;
    vector<long double> B;

    return_matrix(matrix, slay, size);
    cout << "matrix: " << endl;
    print_matrix(matrix);

    return_vector(B, slay, size + 1);

    cout << "vector B: " << endl;
    print_vector(B);

    vector<vector<long double>> one_matrix;

    partition_matrix(matrix, one_matrix, size);

    vector<long double> res;
    res.resize(B.size());
    int iter = 0;
#ifdef mod
#if mod == 1
    while (true) {
        vector<long double> res1;
        res1.resize(res.size());
        res1 = res;
#if type_iteration == 1
        iteration(res, matrix, B);
#elif type_iteration == 2
        zeidel_iteration(res, matrix, B);
#endif
        iter++;
        vector<long double> vec_norm;
        vec_norm.resize(res.size());
        difference_vector(vec_norm, res, res1);
        long double norm = vector_norm(vec_norm);
        if (norm < eps) {
            break;
        }
    }
    cout << "iteration: " << iter << endl;
#elif mod == 2
    long long int step = count_step(matrix, B, eps);
    for (int i = 0; i < step; ++i) {
#if type_iteration == 1
        iteration(res, matrix, B);
#elif type_iteration == 2
        zeidel_iteration(res, matrix, B);
#endif
    }
    cout << "step: " << step << endl;
#endif
#endif
    cout << "result: " << endl;
    print_vector(res);
    return 0;
}
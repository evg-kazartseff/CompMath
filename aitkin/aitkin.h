//
// Created by evgenii on 10.04.17.
//

#ifndef AITKIN_AITKIN_H
#define AITKIN_AITKIN_H

#include <utility>
#include <vector>
#include <stdio.h>
#include <set>
#include <queue>

class aitkin {
private:
    double left;
    double right;
    double step;
    double err;

    std::vector<std::pair<double, double>> table;
    std::queue<std::pair<double, std::pair<double, double>>> queue;
    double (*func) (double);

    void SetFunc(double (*function)(double));
    void SetTable(std::vector<std::pair<double, double>> table);
    void SetLeft(double left) {
        this->left = left;
    }
    void SetRight(double right) {
        this->right = right;
    }
    void SetStep(double step) {
        this->step = step;
    }
    void SetErr(double err) {
        this->err = err;
    }

    void FillTable();
    std::pair<double, std::pair<double, double>> polinomial_calc(double x, double polinom1, double polinom_2, double X_k, double X_m);
public:
    aitkin() {};
    aitkin(double left, double right, double step, double err, double (*function)(double));
    aitkin(double left, double right, double step, double err, std::vector<std::pair<double, double>> table);
    double GetLeft() {
        return this->left;
    }
    double GetRight() {
        return this->right;
    }
    double GetStep() {
        return this->step;
    }
    double GetErr() {
        return this->err;
    }
    double GetValFunction(double x);
    void AddInTable(double x, double y);
    size_t GetSizeTable();
    std::pair<double, double> GetPairPoints(unsigned int number);

    double calc(double x);
};

#endif //AITKIN_AITKIN_H

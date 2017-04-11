//
// Created by evgenii on 10.04.17.
//

#include <cmath>
#include "aitkin.h"

aitkin::aitkin(double left, double right, double step, double err, double (*function)(double)) {
    this->SetLeft(left);
    this->SetRight(right);
    this->SetStep(step);
    this->SetErr(err);
    this->SetFunc(function);
    this->FillTable();
}

aitkin::aitkin(double left, double right, double step, double err, std::vector<std::pair<double, double>> table) {
    this->SetLeft(left);
    this->SetRight(right);
    this->SetStep(step);
    this->SetErr(err);
    this->SetTable(table);
}

void aitkin::SetFunc(double (*function)(double)) {
    this->func = function;
}

void aitkin::SetTable(std::vector<std::pair<double, double>> table) {
    this->table = table;
}

void aitkin::FillTable() {
    for (double i = GetLeft() + 1.0; i <= GetRight() - 1.0; i += GetStep()) {
        this->AddInTable(i, this->GetValFunction(i));
    }
}

double aitkin::GetValFunction(double x) {
    return this->func(x);
}

void aitkin::AddInTable(double x, double y) {
    this->table.push_back({x, y});
}

size_t aitkin::GetSizeTable() {
    return this->table.size();
}

std::pair<double, double> aitkin::GetPairPoints(unsigned int number) {
    if (number > GetSizeTable()) {
        return {0.0, 0.0};
    }
    return this->table.at(number);
}

double aitkin::calc(double x) {
    for (unsigned int i = 0; i < GetSizeTable(); ++i) {
        auto points = this->GetPairPoints(i);
        std::pair<double, std::pair<double, double>> tmp;
        tmp.first = points.second; // point y
        tmp.second = {points.first, points.first}; // polinom(X_k......X_m)
        this->queue.push(tmp);
    }
    double polinom1, polinom2;
    double X_k, X_m;
    std::pair<double, std::pair<double, double>> tmp;
    for (int i = 1; this->queue.size() != 1; ++i) {
        if (i == this->queue.size()) {
            this->queue.pop();
            i = 0;
            continue;
        }
        tmp = this->queue.front();
        this->queue.pop();
        polinom1 = tmp.first;
        X_k = tmp.second.first;
        tmp = this->queue.front();
        polinom2 = tmp.first;
        X_m = tmp.second.second;
        this->queue.push(this->polinomial_calc(x, polinom1, polinom2, X_k, X_m));
    }
    auto val =  this->queue.front().first;
    this->queue.pop();
    return val;
}

std::pair<double, std::pair<double, double>>
aitkin::polinomial_calc(double x, double polinom_1, double polinom_2, double X_k, double X_m) {
    std::pair<double, std::pair<double, double>> tmp;
    double val_pol = polinom_1 * (x - X_m) - polinom_2 * (x - X_k);
    val_pol /= (X_k - X_m);
    tmp.first = val_pol;
    tmp.second.first = X_k;
    tmp.second.second = X_m;
    return tmp;
}

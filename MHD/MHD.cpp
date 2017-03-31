//
// Created by evgenii on 14.03.17.
//


#include <iomanip>
#include "MHD.h"

double MHD::fanction(double x)
{
    return pow(x, 2) - 1;
}

void MHD::bisect(double a, double b) {
    this->set_c((a + b) / 2);
}

void MHD::input() {
    std::ifstream input;
    input.open("../input.dat", std::ios_base::in);
    if (!input.is_open()) {
        std::cout << "Ошибка при открытии файла" << std::endl;
        return;
    }
    double eps, a, b;
    input >> eps;
    input >> a;
    input >> b;
    this->set_a(a);
    this->set_b(b);
    this->set_c(0);
    this->set_eps(eps);
    return;
}

void MHD::run() {
    Achievement_of_accuracy accuracy;
    Sign_change sign_change;
    int c = 0;
    while (accuracy(get_a(), get_b(), get_eps())) {
        bisect(get_a(), get_b());
        double val_a = fanction(get_a());
        double val_b = fanction(get_b());
        double val_c = fanction(get_c());
        if(sign_change(val_a, val_c)) {
            set_b(get_c());
        }
        else if (sign_change(val_c, val_b)) {
            set_a(get_c());
        }
        std::cout << std::fixed << std::setprecision(6) << get_c() << " ";
        c++;
    }
    std::cout << std::endl;
    std::cout << "iteration: " << c << std::endl;
}

bool Sign_change::operator()(double y1, double y2)
{
    return (y1 * y2) <= 0;
}

bool Achievement_of_accuracy::operator()(double a, double b, double eps) {
    return fabs(fabs(a) - fabs(b)) > eps;
}

void MC::bisect(double a, double b) {
    double val = ((get_a() * fanction(get_b()))  - (get_b() * fanction(get_a()))) / (fanction(get_b()) - fanction(get_a()));
    this->set_c(val);
}

void MC::run() {
    Achievement_of_accuracy accuracy;
    Sign_change sign_change;
    double c_local;
    int c = 0;
    do {
        c_local = get_c();
        bisect(get_a(), get_b());
        double val_a = fanction(get_a());
        double val_b = fanction(get_b());
        double val_c = fanction(get_c());
        if(sign_change(val_a, val_c)) {
            set_b(get_c());
        }
        else if (sign_change(val_c, val_b)) {
            set_a(get_c());
        }
        std::cout  << std::fixed << std::setprecision(6) << get_c() << " ";
        c++;
    } while (accuracy(get_c(), c_local, get_eps()));
    std::cout << std::endl;
    std::cout << "iteration: " << c << std::endl;
}

double MN::fanction(double x) {
    return pow(x, 2) - 1;
}

double MN::derivative_fanction(double x) {
    return 2 * x;
}

void MN::input() {
    std::ifstream input;
    input.open("../input1.dat", std::ios_base::in);
    if (!input.is_open()) {
        std::cout << "Ошибка при открытии файла" << std::endl;
        return;
    }
    double eps, x0;
    input >> eps;
    input >> x0;
    this->set_x0(x0);
    this->set_eps(eps);
    return;
}

void MN::set_x0(double x0) {
    this->x0 = x0;
}

double MN::get_x0() {
    return this->x0;
}

void MN::run() {
    Achievement_of_accuracy accuracy;
    double x_loc;
    int c = 0;
    do {
        x_loc = get_x0();
        set_x0(x_loc - (fanction(x_loc) / derivative_fanction(x_loc)));
        std::cout << std::fixed << std::setprecision(6) << get_x0() << " ";
        c++;
    } while (accuracy(get_x0(), x_loc, get_eps()));
    std::cout << std::endl;
    std::cout << "iteration: " << c << std::endl;
}

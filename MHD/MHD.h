//
// Created by evgenii on 14.03.17.
//

#ifndef MHD_MHD_H
#define MHD_MHD_H

#include <cmath>
#include <fstream>
#include <iostream>

class Achievement_of_accuracy {
public:
    bool operator()(double a, double b, double eps);
};

class Sign_change {
public:
    bool operator()(double y1, double y2);
};


class MHD {
private:
    double a;
    double b;
    double c;
    double eps;

    void bisect(double a, double b);

protected:
    double get_a() {
        return this->a;
    }
    double get_b() {
        return this->b;
    }
    double get_c() {
        return this->c;
    }
    double get_eps() {
        return this->eps;
    }
    void set_a(double a) {
        this->a = a;
    }
    void set_b(double b) {
        this->b = b;
    }
    void set_c(double c) {
        this->c = c;
    }
    void set_eps(double eps) {
        this->eps = eps;
    }
public:

    double fanction(double x);

    void input();
    virtual void run();
};

class MC : public MHD{
private:
    void bisect(double a, double b);

public:
    void run();
};


class MN {
private:
    double x0;
    double eps;
    void set_x0(double x0);
    double get_x0();

    void set_eps(double eps) {
        this->eps = eps;
    }
    double get_eps() {
        return this->eps;
    }
public:
    double fanction(double x);
    double derivative_fanction(double x);

    void input();

    void run();
};
#endif //MHD_MHD_H

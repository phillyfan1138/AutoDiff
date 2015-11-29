#ifndef AUTODIFF_H
#define AUTODIFF_H
#include <cmath>


class AutoDiff {
    private:
        double standard;
        double dual;

    public:
        friend AutoDiff operator+(const AutoDiff&, const AutoDiff&);
        friend AutoDiff operator+(const AutoDiff&, double);
        friend AutoDiff operator+(double, const AutoDiff&);
        friend AutoDiff operator-(const AutoDiff&, const AutoDiff&);
        friend AutoDiff operator-(const AutoDiff&);
        friend AutoDiff operator-(const AutoDiff&, double);
        friend AutoDiff operator-(double, const AutoDiff&);
        friend AutoDiff operator*(const AutoDiff&, const AutoDiff&);
        friend AutoDiff operator*(const AutoDiff&, double);
        friend AutoDiff operator*(double, const AutoDiff&);
        friend AutoDiff operator/(const AutoDiff&, const AutoDiff&);
        friend AutoDiff operator/(const AutoDiff&, double);
        friend AutoDiff operator/(double, const AutoDiff&);
        friend bool operator==(const AutoDiff&, const AutoDiff&);
        friend bool operator==(double, const AutoDiff&);
        friend bool operator==(const AutoDiff&, double);
        friend bool operator!=(const AutoDiff&, const AutoDiff&);
        friend bool operator!=(double, const AutoDiff&);
        friend bool operator!=(const AutoDiff&, double);
        friend bool operator>(const AutoDiff&, const AutoDiff&); //compares "standard" only!
        friend bool operator>(const AutoDiff&, double);
        friend bool operator>(double, const AutoDiff&);
        friend bool operator<(const AutoDiff&, const AutoDiff&);//compares "standard" only!
        friend bool operator<(const AutoDiff&, double);
        friend bool operator<(double, const AutoDiff&);

        AutoDiff operator=(const AutoDiff &right){
            return right;
        }
        AutoDiff operator+=(const AutoDiff &right){
            standard+=right.getStandard();
            dual+=right.getDual();
        }
        AutoDiff(double, double);
        AutoDiff();
        AutoDiff add(const AutoDiff&) const;
        AutoDiff add(double) const;
        AutoDiff subtract(const AutoDiff&) const;
        AutoDiff subtract(double) const;
        AutoDiff multiply(const AutoDiff&) const;
        AutoDiff multiply(double) const;
        AutoDiff divide(const AutoDiff&) const;
        AutoDiff divide(double) const;
        void setDual(double);
        void setStandard(double);
        AutoDiff recipricol() const;
        double getStandard() const;
        double getDual() const;
};
AutoDiff sin(const AutoDiff&);
AutoDiff cos(const AutoDiff&);
AutoDiff exp(const AutoDiff&);
AutoDiff log(const AutoDiff&);
AutoDiff sqrt(const AutoDiff&);
AutoDiff erf(const AutoDiff&);
#endif

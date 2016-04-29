// Copyright 2016 Polkanov Nikita

#ifndef MODULES_HYPOTHEC_CALCULATOR_H_
#define MODULES_HYPOTHEC_CALCULATOR_H_

class HypothecCalculator {
 public:

    static const int DEFAULT_PROPERTY_COST;
    static const int DEFAULT_PERCENT;
    static const double DEFAULT_FIRST_PAYMENT_PERCENT;
    static const int DEFAULT_TERM;

    HypothecCalculator();
    HypothecCalculator(const int propertyCost, const int firstPayment, const int term, const int percent);


    int getPercent() const;
    int getPropertyCost() const;
    int getFirstPayment() const;
    int getTerm() const;
    double getMonthlyPayment() const;
    double getOverpayment() const;
    double getPaymentsSum() const;

    void setPercent(const int percent);
    void setPropertyCost(const int property_cost);
    void setFirstPayment(const int first_payment);
    void setTerm(const int term);
    void setMonthlyPayment(const double monthly_payment);
    void setOverpayment(const double overpayment);

    void calculate();
    void resetDefaults();

 private:
    int percent_;
    int property_cost_;
    int first_payment_;
    int term_;
    double monthly_payment_;
    double overpayment_;
};

#endif  // MODULES_HYPOTHEC_CALCULATOR_H_

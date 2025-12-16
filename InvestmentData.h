#ifndef AIRGEAD_INVESTMENT_DATA_H_
#define AIRGEAD_INVESTMENT_DATA_H_

// The InvestmentData class stores all user-provided inputs.
class InvestmentData {
public:
    InvestmentData();
    InvestmentData(double t_initialInvestment,
        double t_monthlyDeposit,
        double t_annualInterestRate,
        unsigned int t_numberOfYears);

    // Setters
    void setInitialInvestment(double t_initialInvestment);
    void setMonthlyDeposit(double t_monthlyDeposit);
    void setAnnualInterestRate(double t_annualInterestRate);
    void setNumberOfYears(unsigned int t_numberOfYears);

    // Getters
    double initialInvestment() const;
    double monthlyDeposit() const;
    double annualInterestRate() const;
    unsigned int numberOfYears() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    unsigned int m_numberOfYears;
};

#endif // AIRGEAD_INVESTMENT_DATA_H_
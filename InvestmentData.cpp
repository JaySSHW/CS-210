#include "InvestmentData.h"

// Default constructor
InvestmentData::InvestmentData()
    : m_initialInvestment(0.0),
    m_monthlyDeposit(0.0),
    m_annualInterestRate(0.0),
    m_numberOfYears(0U) {
}

// Convenience constructor
InvestmentData::InvestmentData(double t_initialInvestment,
    double t_monthlyDeposit,
    double t_annualInterestRate,
    unsigned int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment),
    m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterestRate(t_annualInterestRate),
    m_numberOfYears(t_numberOfYears) {
}

// Setters
void InvestmentData::setInitialInvestment(double t_initialInvestment) {
    m_initialInvestment = t_initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double t_monthlyDeposit) {
    m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentData::setAnnualInterestRate(double t_annualInterestRate) {
    m_annualInterestRate = t_annualInterestRate;
}

void InvestmentData::setNumberOfYears(unsigned int t_numberOfYears) {
    m_numberOfYears = t_numberOfYears;
}

// Getters
double InvestmentData::initialInvestment() const {
    return m_initialInvestment;
}

double InvestmentData::monthlyDeposit() const {
    return m_monthlyDeposit;
}

double InvestmentData::annualInterestRate() const {
    return m_annualInterestRate;
}

unsigned int InvestmentData::numberOfYears() const {
    return m_numberOfYears;
}
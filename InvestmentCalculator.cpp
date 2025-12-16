#include "InvestmentCalculator.h"

// Helper function used internally to calculate the monthly interest rate.
// Formula: (annual interest / 100) / 12
static double calculateMonthlyRate(double t_annualRatePercent) {
    return (t_annualRatePercent / 100.0) / 12.0;
}

// Calculates balances and earned interest when there are NO monthly deposits.
std::vector<InvestmentReportRecord>
InvestmentCalculator::calculateWithoutMonthlyDeposits(const InvestmentData& t_data) const {
    std::vector<InvestmentReportRecord> results;

    double balance = t_data.initialInvestment();
    const double monthlyRate = calculateMonthlyRate(t_data.annualInterestRate());
    unsigned int years = t_data.numberOfYears();

    // Loop through each year
    for (unsigned int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;

        // Loop through each month in the current year
        for (unsigned int month = 1; month <= 12; ++month) {
            double interestForMonth = balance * monthlyRate;
            balance += interestForMonth;
            yearlyInterest += interestForMonth;
        }

        InvestmentReportRecord record;
        record.year = year;
        record.yearEndBalance = balance;
        record.yearEndEarnedInterest = yearlyInterest;

        results.push_back(record);
    }

    return results;
}

// Calculates balances and earned interest when there ARE monthly deposits.
std::vector<InvestmentReportRecord>
InvestmentCalculator::calculateWithMonthlyDeposits(const InvestmentData& t_data) const {
    std::vector<InvestmentReportRecord> results;

    double balance = t_data.initialInvestment();
    const double monthlyDeposit = t_data.monthlyDeposit();
    const double monthlyRate = calculateMonthlyRate(t_data.annualInterestRate());
    unsigned int years = t_data.numberOfYears();

    // Loop through each year
    for (unsigned int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;

        // Loop through each month in the current year
        for (unsigned int month = 1; month <= 12; ++month) {
            // Add the monthly deposit first
            balance += monthlyDeposit;

            double interestForMonth = balance * monthlyRate;
            balance += interestForMonth;
            yearlyInterest += interestForMonth;
        }

        InvestmentReportRecord record;
        record.year = year;
        record.yearEndBalance = balance;
        record.yearEndEarnedInterest = yearlyInterest;

        results.push_back(record);
    }

    return results;
}
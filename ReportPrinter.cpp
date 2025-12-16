#include "ReportPrinter.h"

#include <iostream>
#include <iomanip>

// Prints the initial input summary screen.
void ReportPrinter::printInputSummary(const InvestmentData& t_data) const {
    std::cout << "**********************************" << std::endl;
    std::cout << "*********** Data Input ***********" << std::endl;
    std::cout << "Initial Investment Amount: $"
        << std::fixed << std::setprecision(2)
        << t_data.initialInvestment() << std::endl;
    std::cout << "Monthly Deposit: $"
        << std::fixed << std::setprecision(2)
        << t_data.monthlyDeposit() << std::endl;
    std::cout << "Annual Interest: "
        << std::fixed << std::setprecision(2)
        << t_data.annualInterestRate() << "%" << std::endl;
    std::cout << "Number of Years: "
        << t_data.numberOfYears() << std::endl;
    std::cout << "**********************************" << std::endl;
}

// Helper to print a common header for both reports.
void ReportPrinter::printReportHeader(const char* t_title) const {
    std::cout << std::endl;
    std::cout << t_title << std::endl;
    std::cout << "============================================================"
        << std::endl;
    std::cout << std::left << std::setw(10) << "Year"
        << std::setw(20) << "Year End Balance"
        << std::setw(20) << "Year End Earned Interest"
        << std::endl;
    std::cout << "------------------------------------------------------------"
        << std::endl;
}

// Prints the report for the scenario without additional monthly deposits.
void ReportPrinter::printReportWithoutDeposits(
    const std::vector<InvestmentReportRecord>& t_records) const {

    printReportHeader("Balance and Interest Without Additional Monthly Deposits");

    for (const InvestmentReportRecord& record : t_records) {
        std::cout << std::left << std::setw(10) << record.year
            << "$" << std::right << std::setw(18)
            << std::fixed << std::setprecision(2)
            << record.yearEndBalance
            << "   $"
            << std::setw(16)
            << std::fixed << std::setprecision(2)
            << record.yearEndEarnedInterest
            << std::endl;
    }

    std::cout << "============================================================"
        << std::endl;
}

// Prints the report for the scenario with additional monthly deposits.
void ReportPrinter::printReportWithDeposits(
    const std::vector<InvestmentReportRecord>& t_records) const {

    printReportHeader("Balance and Interest With Additional Monthly Deposits");

    for (const InvestmentReportRecord& record : t_records) {
        std::cout << std::left << std::setw(10) << record.year
            << "$" << std::right << std::setw(18)
            << std::fixed << std::setprecision(2)
            << record.yearEndBalance
            << "   $"
            << std::setw(16)
            << std::fixed << std::setprecision(2)
            << record.yearEndEarnedInterest
            << std::endl;
    }

    std::cout << "============================================================"
        << std::endl;
}
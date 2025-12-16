#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#include "InvestmentData.h"
#include "InvestmentCalculator.h"
#include "ReportPrinter.h"

// Function declarations
void getUserInput(InvestmentData& t_data);
double readNonNegativeDouble(const std::string& t_prompt);
double readPositiveDouble(const std::string& t_prompt);
unsigned int readPositiveUnsignedInt(const std::string& t_prompt);
void waitForEnter();

// The main function acts only as a driver to create objects and
// call the proper functions, per Airgead standards.
int main() {
    try {
        bool runAgain = true;

        while (runAgain) {
            InvestmentData userData;
            InvestmentCalculator calculator;
            ReportPrinter printer;

            // 1. Collect user input for this scenario
            getUserInput(userData);

            // 2. Show summary screen
            printer.printInputSummary(userData);

            // 3. Wait before showing the reports
            waitForEnter();

            // 4. Calculate both sets of results
            std::vector<InvestmentReportRecord> resultsNoDeposits =
                calculator.calculateWithoutMonthlyDeposits(userData);

            std::vector<InvestmentReportRecord> resultsWithDeposits =
                calculator.calculateWithMonthlyDeposits(userData);

            // 5. Print both reports
            printer.printReportWithoutDeposits(resultsNoDeposits);
            printer.printReportWithDeposits(resultsWithDeposits);

            // 6. Allow the user to test different values
            std::cout << std::endl;
            std::cout << "Would you like to test another set of values? (y/n): ";
            char choice = 'n';
            std::cin >> choice;

            if (choice != 'y' && choice != 'Y') {
                runAgain = false;
            }

            // Clear any remaining input including newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Thank you for using Airgead Banking Investment Calculator."
            << std::endl;
    }
    catch (const std::exception& ex) {
        // Basic exception handling to exit gracefully if something unexpected occurs.
        std::cerr << "An unexpected error occurred: " << ex.what() << std::endl;
    }

    return 0;
}

// Reads and validates all user inputs, then populates the InvestmentData object.
void getUserInput(InvestmentData& t_data) {
    std::cout << "**********************************" << std::endl;
    std::cout << "*********** Data Input ***********" << std::endl;

    double initialInvestment = readNonNegativeDouble("Initial Investment Amount: $");
    double monthlyDeposit = readNonNegativeDouble("Monthly Deposit: $");
    double annualInterest = readPositiveDouble("Annual Interest (%): ");
    unsigned int numberOfYears = readPositiveUnsignedInt("Number of Years: ");

    t_data.setInitialInvestment(initialInvestment);
    t_data.setMonthlyDeposit(monthlyDeposit);
    t_data.setAnnualInterestRate(annualInterest);
    t_data.setNumberOfYears(numberOfYears);
}

// Reads a non-negative double from standard input.
double readNonNegativeDouble(const std::string& t_prompt) {
    double value = 0.0;
    bool isValid = false;

    while (!isValid) {
        std::cout << t_prompt;
        std::cin >> value;

        if (std::cin.fail() || value < 0.0) {
            std::cout << "Please enter a non-negative numeric value." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            isValid = true;
        }
    }

    // Clear remaining newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

// Reads a strictly positive double from standard input.
double readPositiveDouble(const std::string& t_prompt) {
    double value = 0.0;
    bool isValid = false;

    while (!isValid) {
        std::cout << t_prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0.0) {
            std::cout << "Please enter a numeric value greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            isValid = true;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

// Reads a strictly positive unsigned integer from standard input.
unsigned int readPositiveUnsignedInt(const std::string& t_prompt) {
    int value = 0; // Start with int for validation
    bool isValid = false;

    while (!isValid) {
        std::cout << t_prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= 0) {
            std::cout << "Please enter an integer value greater than zero." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            isValid = true;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return static_cast<unsigned int>(value);
}

// Waits for the user to press Enter before continuing.
void waitForEnter() {
    std::cout << std::endl << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;
}
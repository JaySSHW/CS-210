#ifndef AIRGEAD_INVESTMENT_REPORT_RECORD_H_
#define AIRGEAD_INVESTMENT_REPORT_RECORD_H_

//A simple record that holds the results for a single year of an investment scenario.
struct InvestmentReportRecord {
	unsigned int year;
	double yearEndBalance;
	double yearEndEarnedInterest;
};

#endif //AIRGEAD_INVESTMENT_REPORT_RECORD_H_
#ifndef AIRGEAD_INVESTMENT_CALCULATOR_H_
#define AIRGEAD_INVESTMENT_CALCULATOR_H_

#include <vector>
#include "InvestmentData.h"
#include "InvestmentReportRecord.h"

//The InvestmentCalculator class performs the compound-interest calculations based on the user;s investment data.
class InvestmentCalculator {
public:
	//Calculates results assuming NO additional monthly deposits.
	std::vector<InvestmentReportRecord>
		calculateWithoutMonthlyDeposits(const InvestmentData& t_data) const;

	//Calculates results WITH the specified additional monthly deposits.
	std::vector<InvestmentReportRecord>
		calculateWithMonthlyDeposits(const InvestmentData& t_data) const;
};

#endif // AIRGEAD_INVESTMENT_CALCULATOR_H_
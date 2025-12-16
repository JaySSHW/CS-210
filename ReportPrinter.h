#ifndef AIRGEAD_REPORT_PRINTER_H_
#define AIRGEAD_REPORT_PRINTER_H_

#include <vector>
#include "InvestmentData.h"
#include "InvestmentReportRecord.h"

// The ReportPrinter class prints the input summary and both output reports.
class ReportPrinter {
public:
    void printInputSummary(const InvestmentData& t_data) const;

    void printReportWithoutDeposits(
        const std::vector<InvestmentReportRecord>& t_records) const;

    void printReportWithDeposits(
        const std::vector<InvestmentReportRecord>& t_records) const;

private:
    void printReportHeader(const char* t_title) const;
};

#endif // AIRGEAD_REPORT_PRINTER_H_
import pandas as pd
import numpy as np

class spreadsheetHandle:
    def __init__(self, expense, *args, **kwargs):
        self.filePath = 'Bilancio'
        self.newFilePath = 'UpdatedBilancio'
        self.expense = expense
        self.balance = {"MonthlyBalance":0, "BankAccountBalance":0, "PrepaidCardBalance":0}
        self.dataframe = pd.read_excel(self.filePath+".xlsx")

        self.setDataframe()
        print(self.dataframe)
        self.recordData()

    def setDataframe(self):
        float(self.expense['Amount'])
        self.lastUpdateRow = self.dataframe.iloc[-1,-3:].values
        self.expense = {col: self.expense[col] for col in self.dataframe.columns[:-3]}

    def recordData(self):
        print(self.expense)
        print(self.balance)
        print(self.lastUpdateRow)
        self.updateBalance()
        self.dataframe.loc[len(self.dataframe)] = self.updateRow
        print(self.dataframe)

        self.updateExcel()

    def updateBalance(self):
        if self.expense['Direction'] == "Uscita":
            self.balance['MonthlyBalance'] = self.lastUpdateRow[0] - float(self.expense['Amount'])
            self.balance['BankAccountBalance'] = self.lastUpdateRow[1] - float(self.expense['Amount'])
            if self.expense['PaymentMethod'] == "Prepagata":
                self.balance['PrepaidMethod'] = self.lastUpdateRow[2] - float(self.expense['Amount'])
            else:
                self.balance['PrepaidMethod'] = self.lastUpdateRow[2]
        else:
            self.balance['MonthlyBalance'] = self.lastUpdateRow[0] + float(self.expense['Amount'])
            self.balance['BankAccountBalance'] = self.lastUpdateRow[1] + float(self.expense['Amount'])
            if self.expense['PaymentMethod'] == "Prepagata":
                self.balance['PrepaidMethod'] = self.lastUpdateRow[2] + float(self.expense['Amount'])
            else:
                self.balance['PrepaidMethod'] = self.lastUpdateRow[2]
        self.updateRow = self.expense | self.balance


    def updateExcel(self):
        self.dataframe.to_excel(self.newFilePath+".xlsx", index=False)
        self.dataframe.to_csv(self.newFilePath+".csv", index=False)
        self.dataframe.to_excel(self.filePath+".xlsx", index=False)
        self.dataframe.to_csv(self.filePath+".csv", index=False)
        print("Excel saved")
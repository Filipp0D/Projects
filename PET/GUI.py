import tkinter as tk
from tkinter import ttk
import time
import dotenv
import os
import json
import SpreadsheetHandle as SH

class window(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)
        # Adding a title to the window
        self.wm_title("MANEI")

        self.grid_columnconfigure(index=5)
        self.grid_rowconfigure(index=0)

        self.mixed_data = mixed_data
        self.defineIntroductionFrame()
        self.defineDateFrame()
        self.defineDirectionFrame()
        self.defineTypeFrame()
        self.defineDescriptionFrame()
        self.defineAmountFrame()
        self.definePaymentMethodFrame()

        # Confirm Data
        self.grid_rowconfigure(index=7)
        self.frameConfirm = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameConfirm.grid_configure(row=7, column=1)
        self.buttonConfirm = ttk.Button(master=self.frameConfirm,
                                   text="Conferma",
                                   command=self.recordAndResetData,
                                   width=40)
        #self.buttonConfirm.bind('<<Confirm&Reset>>', self.recordAndResetData)
        self.buttonConfirm.pack()

    def defineIntroductionFrame(self):
        # INTRODUCTION
        self.frameIntroduction = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameIntroduction.grid_configure(row=0, column=0, columnspan=6)
        self.labelIntroduction = ttk.Label(master=self.frameIntroduction,
                                      text="Inserisci i dati: ",
                                      foreground="white",
                                      background="black",
                                      width=80)
        self.labelIntroduction.pack()

    def defineDateFrame(self):
        # DATE
        self.date = tk.StringVar()
        self.grid_rowconfigure(index=1)
        self.frameDate = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameDate.grid_configure(row=1, column=1)
        self.labelIntroduction = ttk.Label(master=self.frameDate,
                                      text="Data: ",
                                      width=20)
        self.labelIntroduction.pack(side="left")
        self.entry_data = tk.Entry(master=self.frameDate,
                              textvariable=self.date,
                              width=60
                              )
        self.entry_data.pack(side="right")
    def defineDirectionFrame(self):
        # DIRECTION
        self.direction = tk.StringVar()
        self.grid_rowconfigure(index=2)
        self.frameDirection = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameDirection.grid_configure(row=2, column=1)
        self.labelDirection = ttk.Label(master=self.frameDirection,
                                   text="Direzione: ",
                                   width=20)
        self.labelDirection.pack(side="left")
        self.comboboxDirection = ttk.Combobox(master=self.frameDirection,
                                         textvariable=self.direction,
                                         values=self.mixed_data["direction"],
                                         state="readonly",
                                         width=60
                                         )
        self.comboboxDirection.bind('<<ComboboxSelected>>', self.updateTypeOption)
        self.comboboxDirection.pack(side="right")

    def defineTypeFrame(self):
        # TYPE
        self.type = tk.StringVar()
        self.grid_rowconfigure(index=3)
        self.frameType = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameType.grid_configure(row=3, column=1)
        self.labelType = ttk.Label(master=self.frameType,
                              text="Tipologia: ",
                              width=20)
        self.labelType.pack(side="left")
        self.comboboxType = ttk.Combobox(master=self.frameType,
                                   textvariable=self.type,
                                   width=60,
                                   )
        self.comboboxType.pack(side="right")
        self.updateTypeOption()

    def defineDescriptionFrame(self):
        # DESCRIPTION
        self.description = tk.StringVar()
        self.grid_rowconfigure(index=4)
        self.frameDescription = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameDescription.grid_configure(row=4, column=1)
        self.labelDescription = ttk.Label(master=self.frameDescription,
                                     text="Descrizione: ",
                                     width=20)
        self.labelDescription.pack(side="left")
        self.entryDescription = ttk.Entry(master=self.frameDescription,
                                     textvariable=self.description,
                                     width=60
                                     )
        self.entryDescription.pack(side="right")

    def defineAmountFrame(self):
        # AMOUNT
        self.amount = tk.StringVar()
        self.grid_rowconfigure(index=5)
        self.frameAmount = ttk.Frame(master=self, relief=tk.FLAT)
        self.frameAmount.grid_configure(row=5, column=1)
        self.labelAmount = ttk.Label(master=self.frameAmount,
                                text="Valore: ",
                                width=20)
        self.labelAmount.pack(side="left")
        self.entryAmount = ttk.Entry(master=self.frameAmount,
                                textvariable=self.amount,
                                width=60
                                )
        self.entryAmount.pack(side="right")

    def definePaymentMethodFrame(self):
        # PAYMENT METHOD
        self.paymentMethod = tk.StringVar()
        self.grid_rowconfigure(index=6)
        self.framePaymentMethod = ttk.Frame(master=self, relief=tk.FLAT)
        self.framePaymentMethod.grid_configure(row=6, column=1)
        self.labelPaymentMethod = ttk.Label(master=self.framePaymentMethod,
                                       text="Metodo di pagamento: ",
                                       width=20)
        self.labelPaymentMethod.pack(side="left")
        self.comboboxPaymentMethod = ttk.Combobox(master=self.framePaymentMethod,
                                            textvariable=self.paymentMethod,
                                            values=["Conto", "Prepagata", "Satispay", "Contanti"],
                                            width=60
                                            )
        self.comboboxPaymentMethod.pack(side="right")

    def ascActualTime():
        t = time.localtime(time.time())
        ascLocalTime = time.asctime(t)
        os.environ['DATE'] = ascLocalTime
        return ascLocalTime

    def updateTypeOption(self, event=None):

        os.environ['DIRECTION'] = self.direction.get().lower()
        newOptions = self.mixed_data["type"].get(os.environ['DIRECTION'], [])
        self.comboboxType['values'] = newOptions
        self.type.set("Seleziona una direzione" if not newOptions else newOptions[0])

    def recordAndResetData(self, event=None):
        date = self.date.get()
        direction = self.direction.get()
        type = self.type.get()
        description = self.description.get()
        amount = self.amount.get()
        paymentMethod = self.paymentMethod.get()

        expense = {'Date': date,
                   'Direction': direction,
                   'Type': type,
                   'Description': description,
                   'Amount': amount,
                   'PaymentMethod': paymentMethod}
        sh = SH.spreadsheetHandle(expense)

        # Reset StringVar variables (reset widget values)
        self.date.set("")
        self.direction.set("")
        self.type.set("")
        self.description.set("")
        self.amount.set("")
        self.paymentMethod.set("")

        # Reset type combobox options
        self.updateTypeOption()


if __name__ == "__main__":
    path = "mixed_data.json"
    dotenv.load_dotenv("vars.env")
    with open(path, 'r') as file:
        mixed_data = json.load(file)
    print(mixed_data)
    testObj = window()
    testObj.mainloop()
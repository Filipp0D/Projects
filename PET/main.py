import json
import os
import tkinter as tk
from tkinter import ttk
import pandas as pd
import numpy as np
import time
import dotenv
import os

dotenv.load_dotenv("vars.env")
mixed_data = json.loads("mixed_data.json")

def ascActualTime():
    t = time.localtime(time.time())
    ascLocalTime = time.asctime(t)
    return ascLocalTime

def setExcelDate():
    yr, month, day, hr, minute = map(int, time.strftime("%Y %m %d %H %M").split())
    date = str(day)+"/"+str(month)+"/"+str(yr)
    return date

def chooseOptionByDirection(event):
    os.environ['DIRECTION'] = comboboxDirection.get()
    print(os.environ['DIRECTION'])
    if os.environ['DIRECTION'] == "Entrata":
        print("")
    elif os.environ['DIRECTION'] == "Uscita":
        print("")


print(setExcelDate())

window = tk.Tk()
title = window.title("MANEI")

window.grid_columnconfigure(index=5)
window.grid_rowconfigure(index=0)
frameIntroduction = ttk.Frame(master=window, relief=tk.FLAT)
frameIntroduction.grid_configure(row=0, column=0, columnspan=6)

labelIntroduction = ttk.Label(master=frameIntroduction,
                        text="Inserisci i dati: ",
                        foreground="white",
                        background="black",
                        width=80)
labelIntroduction.pack()

# DATE
window.grid_rowconfigure(index=1)
frameDate = ttk.Frame(master=window, relief=tk.FLAT)
frameDate.grid_configure(row=1, column=1)
labelIntroduction = ttk.Label(master=frameDate,
                        text="Data: ",
                        width=20)
labelIntroduction.pack(side="left")
entry_data = tk.Entry(master=frameDate,
                       textvariable=tk.StringVar(value=ascActualTime()),
                      width=60
                      )
entry_data.pack(side="right")

# DIRECTION
direction = tk.StringVar()
window.grid_rowconfigure(index=2)
frameDirection = ttk.Frame(master=window, relief=tk.FLAT)
frameDirection.grid_configure(row=2, column=1)
labelDirection = ttk.Label(master=frameDirection,
                        text="Direzione: ",
                        width=20)
labelDirection.pack(side="left")
comboboxDirection = ttk.Combobox(master=frameDirection,
                                 values=["Entrata", "Uscita"],
                                 state="readonly",
                                 width=60
                                 )
comboboxDirection.pack(side="right")
comboboxDirection.bind('<<ComboboxSelected>>', chooseOptionByDirection)

# TYPE
window.grid_rowconfigure(index=3)
frameType = ttk.Frame(master=window, relief=tk.FLAT)
frameType.grid_configure(row=3, column=1)
labelType = ttk.Label(master=frameType,
                        text="Tipologia: ",
                        width=20)
labelType.pack(side="left")
optmenuType = ttk.Combobox(master=frameType,
                            value=["Caffè", "Stipendio", "Cena", "Spesa"],
                            width=60,
                            )
optmenuType.pack(side="right")

# DESCRIPTION
window.grid_rowconfigure(index=4)
frameDescription = ttk.Frame(master=window, relief=tk.FLAT)
frameDescription.grid_configure(row=4, column=1)
labelDescription = ttk.Label(master=frameDescription,
                        text="Descrizione: ",
                        width=20)
labelDescription.pack(side="left")
entryDescription = ttk.Entry(master=frameDescription,
                      width=60
                      )
entryDescription.pack(side="right")

# AMOUNT
window.grid_rowconfigure(index=5)
frameAmount = ttk.Frame(master=window, relief=tk.FLAT)
frameAmount.grid_configure(row=5, column=1)
labelAmount = ttk.Label(master=frameAmount,
                        text="Valore: ",
                        width=20)
labelAmount.pack(side="left")
entryAmount = ttk.Entry(master=frameAmount,
                      width=60
                      )
entryAmount.pack(side="right")

# PAYMENT METHOD
window.grid_rowconfigure(index=6)
framePaymentMethod = ttk.Frame(master=window, relief=tk.FLAT)
framePaymentMethod.grid_configure(row=6, column=1)
labelPaymentMethod = ttk.Label(master=framePaymentMethod,
                        text="Metodo di pagamento: ",
                        width=20)
labelPaymentMethod.pack(side="left")
optmenuPaymentMethod = ttk.Combobox(master=framePaymentMethod,
                                 value=["Conto", "Prepagata", "Satispay"],
                                 width=60
                                 )
optmenuPaymentMethod.pack(side="right")

# Confirm Data
window.grid_rowconfigure(index=7)
frameConfirm = ttk.Frame(master=window, relief=tk.FLAT)
frameConfirm.grid_configure(row=7, column=1)
buttonConfirm = ttk.Button(master=frameConfirm,
                        text="Conferma",
                        width=40)
buttonConfirm.pack()

tk.mainloop()
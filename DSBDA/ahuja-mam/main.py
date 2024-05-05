import pandas as pd
import numpy as np

df = pd.read_csv("studentDetails.csv")
print("\n isnull() Function: \n",df.isnull())

gB = df.groupby("Branch")
print("\n groupby() Function: \n", gB.get_group("Computer"))

df = df.replace(to_replace = np.nan, value = 0.0)
print("\n replace() Function: \n", df)

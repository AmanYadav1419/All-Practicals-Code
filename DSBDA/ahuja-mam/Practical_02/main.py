import pandas as pd
import numpy as np

student_details = {
  "Name" :["Hitesh","Satyam","Salim","Absahrul"],
  "CGPA" :[np.nan,8.0, np.nan, 9],
  "Year" :["TE","BE","TE","BE"]
}

df = pd.DataFrame(student_details)

print("Example of GroupBy Function:\n")
group_by = df.groupby("Year")
print(group_by.get_group("TE"))

print("Before Replacement:\n")
print(df)

df = df.replace(to_replace = [np.nan], value = 9)
print("After Replacement:\n")
print(df)



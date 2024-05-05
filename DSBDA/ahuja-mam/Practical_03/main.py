import pandas as pd
import numpy as np
import math
import csv
import statistics

with open("wine.csv","r",encoding="latin-1") as f:
	wines = list(csv.reader(f))

scores = [w[2] for w in wines]

scores.remove(scores[0])

num_scores len(scores)

Scores = [float(x) for x in scores]

sum_of_scores = sum(Scores)
min_of_scores = min(Scores)
max_of_scores = max(Scores)
median_of_scores = statistics.median(Scores)
standard_deviation = statistics.stdev(Scores)

mean_of_scores = statistics.mean(Scores)

print("Mean: ",mean_of_scores)
print("Minimum: ",min_of_scores)
print("Maximum: ",max_of_scores)
print("Median: ",median_of_scores)
print("Standard Deviation: ",standard_deviation)	

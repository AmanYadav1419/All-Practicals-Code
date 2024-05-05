# Read the Iris dataset from a CSV file
iris_data <- read.csv("Iris.csv")

# List down the features and their types
str(iris_data)

# Create a histogram for each feature
par(mfrow = c(2, 2)) # Divide the plot area into a 2x2 grid
for (i in 1:4) {
  hist(iris_data[, i], main = colnames(iris_data)[i], xlab = "Value", ylab = "Frequency", col = "steelblue")
}

# Create a boxplot for each feature
par(mfrow = c(2, 2)) # Divide the plot area into a 2x2 grid
for (i in 1:4) {
  boxplot(iris_data[, i], main = colnames(iris_data)[i], ylab = "Value", col = "steelblue", border = "black")
}


# To compare distributions and identify outliers using the code provided, you can follow these steps:

# 1. Run the code to generate the histograms and boxplots for each feature in the Iris dataset.

# 2. Analyze the histograms: Look for differences in the shape and spread of the distributions for each feature. Check if the histograms are skewed or symmetric, and note any unusual patterns or gaps in the data.

# 3. Analyze the boxplots: Look for differences in the medians, interquartile ranges (IQR), and the presence of outliers. Outliers can be identified as individual data points that are plotted beyond the whiskers of the boxplot.

#4. Compare distributions: Compare the histograms and boxplots across different features. Look for variations in the distributions between features. For example, check if the distributions of sepal length differ from petal length or if there are notable differences between different species.

#5. Identify outliers: In the boxplots, look for individual data points that are plotted as circles or dots outside the whiskers. These points represent potential outliers. Note their values and consider whether they might be genuine extreme observations or if they could be errors or anomalies in the data.

#By visually inspecting the histograms and boxplots, you can compare the distributions of each feature and identify any potential outliers that deviate significantly from the typical range of values. Remember to consider the context of the data and domain knowledge when interpreting outliers.

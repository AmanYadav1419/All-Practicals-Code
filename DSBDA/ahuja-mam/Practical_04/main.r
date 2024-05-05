
#load the Boston Housing DataSet
dataset <- read.csv("Boston.csv")
 
data <- head(dataset,100)
# Extract the columns for RM and MEDV

x <- data$rm
y <- data$medv

# Fit a linear regression model
fit <- lm(y ~ x)

# save the graph as
png(file = "linearRegression.pn")

#plot the data and the regression line
plot(x,y,main="Linear Regression Model for Boston Housing Dataset",
	xlab = "Average Number of Rooms per Dwelling",
	ylab = "Median Value of Owner-Occupied Homes",
	pch  = 16, col = "blue")
abline(fit,col = "red")



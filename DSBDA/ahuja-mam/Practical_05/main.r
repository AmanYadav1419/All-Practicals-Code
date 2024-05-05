#load the dataset
data <- read.csv("Boston.csv")

#filter the size
#data <- head(dataset,200)

#calculate the median for medv
medv_median <- median(data$medv)

#Extract the columns
x <- data$lstat
y <- ifelse(data$medv >= medv_median,1,0)

#Fit a regression model
fit <- glm(y ~ x, data = data, family="binomial")

#Save the graph here
png(file="logisiticRegression.png")

#Create a graph for regression
plot(x,y,main = "Logistic Regression",
	 xlab = "Lower Status of Population",
	 ylab = "Probablity of High Median value",
	 col  = ifelse(y == 1,"red","blue"))
abline(fit,col = "red")
curve(predict(fit,data.frame(x),type = "response"),
	add = TRUE, col = "black", lwd = 2)
	
dev.off()	

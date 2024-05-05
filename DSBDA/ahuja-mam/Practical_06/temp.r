library(e1071)

iris <- read.csv("Iris.csv")

trainIndex <- sample(1:nrow(iris), 0.7*nrow(iris), replace = FALSE)
train <- iris[trainIndex,]
test <- iris[-trainIndex,]

# Creating the Naive Bayes model
model <- naiveBayes(Species ~ ., data = train)

# Making predictions on the test set
predictions <- predict(model, test)
print("Predictions")
print(predictions)

# Creating the confusion matrix
conf_matrix <- table(test$Species, predictions)

print("Confusion Matrix")
print(conf_matrix)

# Calculating the evaluation metrics
TP <- conf_matrix[1,1]
FP <- conf_matrix[2,1] + conf_matrix[3,1]
TN <- conf_matrix[2,2] + conf_matrix[3,2] + conf_matrix[1,3] + conf_matrix[2,3] + conf_matrix[3,3]
FN <- conf_matrix[1,2] + conf_matrix[1,3]

Accuracy <- sum(diag(conf_matrix))/sum(conf_matrix)
Error_rate <- 1 - Accuracy
Precision <- TP/(TP+FP)
Recall <- TP/(TP+FN)

print(c("Accuracy: ",Accuracy))
print(c("Error_rate: ",Error_rate))
print(c("Precision: ",Precision))
print(c("Recall: ",Recall))

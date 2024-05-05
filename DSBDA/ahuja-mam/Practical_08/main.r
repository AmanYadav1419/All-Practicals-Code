
# READ THE DATASET
titanic_dataset <- read.csv("Titanic.csv")

# SAVE HISTOGRAM IN FILE
png(file = "histogram.png")

# PLOT THE HISOTGRAM
hist(titanic_dataset$Fare, breaks = 20, col = "steelblue", border = "black",
     xlab = "Ticket Price", ylab = "Count", main = "Ticket Price Distribution")

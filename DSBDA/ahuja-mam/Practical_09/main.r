# Load the Titanic dataset from the "tidyverse" package
titanic_dataset <- read.csv("Titanic.csv")

# Remove rows with missing or non-numeric values in the age variable
titanic_dataset <- titanic_dataset[!is.na(titanic_dataset$Age) & is.finite(titanic_dataset$Age),]
titanic_dataset <- titanic_dataset[!is.na(titanic_dataset$Sex), ]

age <- titanic_dataset$Age
sex <- titanic_dataset$Sex

unique_sex <- unique(sex)
print(unique_sex)

# SAVE THE BOXPLOT IN PNG
png(file="BoxPlot.png")

# Create a box plot for age distribution by gender and survival status
boxplot(
  age ~ sex,
  data = titanic_dataset,
  xlab = "Gender",
  ylab = "Age",
  main = "Age Distribution by Gender and Survival Status",
  col = factor(titanic_dataset$Survived),
  border = "black",
  notch = TRUE
)
legend(
  "topleft",
  legend = c("No", "Yes"),
  fill = c("white", "gray"),
  border = "black",
  title = "Survived"
)


library(dplyr)
library(ggplot2)
library(plyr)
getwd()
setwd("/Users/noblyan/Desktop")
#2-1
middle_data <- read.table("middle_data.txt", header=TRUE, sep=",")

View(middle_data)


middle_data[middle_data=='?'] <- NA
data <- middle_data

head(data[,48:50])

str(data)


#2-2
length(data$Symptoms)/sum(is.na(data$Symptoms))
data2 <- colSums(is.na(data))
tapply(data$Symptoms, data$Alcohol, sum(is.na))

sum(is.na(data$Symptoms))

pMiss <- function(i){
  
  return(colSums(is.na(i)))
}
data2 <- pMiss(data)


#3

boston_housing <- read.csv("BostonHousing.csv", header=TRUE)
plot_hs <- boston_housing[c("NOX", "DIS", "PTRATIO", "AGE", "CAT..MEDV")]
plot_hs

boxplot(plot_hs$NOX~plot_hs$CAT..MEDV)
boxplot(plot_hs$DIS~plot_hs$CAT..MEDV)
boxplot(plot_hs$AGE~plot_hs$CAT..MEDV)
boxplot(plot_hs$PTRATIO~plot_hs$CAT..MEDV)


#4
laptopsale <- read.csv("LaptopSalesJanuary2008.csv", header=T, stringsAsFactors = F)
View(laptopsale)
#Store.Postcode별 Retail.Price 구할 것.


lapsale<-laptopsale %>% group_by(Store.Postcode) %>% 
          select(Retail.Price) %>% 
           mutate(max_p = max(Retail.Price), min_p=min(Retail.Price))
lapsale
ggplot(lapsale, aes(x=lapsale$Store.Postcode, y=lapsale$Retail.Price))+geom_col()



#5
x = -5:0
y = -x^3
plot(x,y,type='l')

x1 = 0:1
y1 = (x1)^2
plot(x1,y1,type='l')








#1
update.packages("datasets")
library(datasets)

boxplot(Orange$circumference ~ Orange$Tree)$stats


#2

boxplot(Orange$age, names = c("age"), range = 1.2)
points(c(sd(Orange$age)), pch=1, col=1, cex=1)
points(c(mean(Orange$age)), pch=1, col=1, cex=1)

hist(Orange$circumference, 5,
     col=c("red","orange","yellow","green","blue"))

#3
complaints <- c("o" ,"o", "n", "j", "c", "f","b" ,"b","f" ,"o" ,"j" ,"o" ,"o", "m", "o", "f", "f", "o", "o", "n", "o", "n" ,"j", "f", "j", "b", "o", "c", "j", "o", "j", "j", "f", "n","o", "b", "m", "o", "j" ,"m", "o" ,"b", "o", "f", "j", "o", "o", "b", "n", "c", "o", "o", "o", "m", "b", "f" ,"j", "o", "f", "n")

complaints <- toupper(complaints)
complaints[complaints=="N"]<-"C"
complaints_table <- addmargins(table(complaints))
complaints_table

#4
pie(x=table(complaints) 
    ,labels = c("Back Pain","Cold","Fatigue","Joint swelling","Musscle weakness","Other")
    ,lty = 1
    ,main="Shape of the Complaint")

#5

i <- 1
element <- c()
while(1){
  i = 2*i
  element <- c(element,i)
  if(i>=1024) 
    break
}
element

mean(element)
sd(element)

#6
mean(element[element<500])
sd(element[element<500])


#7
#(a)
addmargins(table(airquality[,c(5,4)]))


#(b)
library(dplyr)
attach(airquality)

Month_Temp <- as.data.frame(airquality[,c(4,5)])
Month_Temp

june_august<- Month_Temp %>% 
  group_by(Month %in% c(6:8)) %>% 
  filter(Temp >= 90)

june_august <- c(june_august$Month)
june_august <- june_august[1:13]

barplot(table(june_august)
        ,names.arg = c("June", "July", "August")
        ,main = "Monthly high temperature count"
        ,xlab = "Month"
        ,ylab = "Frequency"
        ,col = "lightpink")
        
        
        
        
        
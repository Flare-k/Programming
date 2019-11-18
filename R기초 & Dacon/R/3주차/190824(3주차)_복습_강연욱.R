
ls()
rm(list = ls())
#1
exam <- c()
for(i in 1:9){
        for(j in 1:9){
          result = i * j
         exam<-c(exam,print (paste(i,"x",j,"=",result)))
        }
  }
exam

gugu <- matrix(exam, nrow = 9, ncol=9)
gugu


#2

table(is.na(airquality$Ozone))
airmean = sum(airquality$Ozone, na.rm = T)/length(airquality$Ozone)
airmean

for(i in 1:length(airquality$Ozone)){
  if(is.na(airquality$Ozone[i])){
    airquality$Ozone[i] <- airmean
  }
  else{
    next
  }
}
airquality$Ozone
table(is.na(airquality$Ozone))


#3

data(airquality)
airquality$Temp  #화씨 기준

celsius <- c()

feel_temp <- function(fah){
  celsius <- NULL
  temp <- NULL
  for(i in 1:length(fah)){
    celsius[i] <- (fah[i]-32)/(1.8)
    temp[i] <- celsius[i]
  }

  phytemp <- NULL
  for(i in 1:length(temp)){
    phytemp[i] <- (13.12 + 0.6215*temp[i] - 11.37*(airquality$Wind[i])^0.16 + 0.3965*(airquality$Wind[i])^(0.16)*temp[i])
  }
  return(phytemp)
}
feel_temp(airquality$Temp)  


#4

airquality$feeling_temp <- feel_temp(airquality$Temp)

getwd()
setwd("/Users/noblyan/Desktop")
getwd()

write.csv(airquality, "my_exam.csv", row.names = F)
my_airquality <- read.csv("/Users/noblyan/Desktop/my_exam.csv")
my_airquality

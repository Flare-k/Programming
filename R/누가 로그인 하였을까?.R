install.packages('rpart')
library(rpart)
install.packages("doBy")
library(doBy)
getwd()
setwd("/Users/noblyan/Desktop")
getwd()

install.packages('data.table')
install.packages('tidyverse')

library(data.table)
library(tidyverse)

train<-fread("/Users/noblyan/Desktop/train.csv",header=T, stringsAsFactors = T)
test<-fread("/Users/noblyan/Desktop/test.csv",header = T, stringsAsFactors = T)
View(train)

train$Sex<-ifelse(train$Sex=="male",1,0) # 남자 1, 여자 0
table(is.na(train$past_login_total))

train$past_login_total<-ifelse(is.na(train$past_login_total),as.integer(mean(train$past_login_total,na.rm = T)),train$past_login_total)
table(is.na(train$past_1_month_login))


train$past_1_month_login<-ifelse(is.na(train$past_1_month_login),as.integer(mean(train$past_1_month_login,na.rm = T)),train$past_1_month_login)
table(is.na(train$past_1_week_login))

train$past_1_week_login<-ifelse(is.na(train$past_1_week_login),as.integer(mean(train$past_1_week_login,na.rm = T)),train$past_1_week_login)
table(is.na(train))

train$email_type<-as.factor(train$email_type)
train$login<-as.factor(train$login)
train<-train %>% 
  select(-c(phone_rat,apple_rat,person_id))


View(train)
table(train$login)

set.seed(12345)

train_rand <- train[order(runif(1000)),]

summary(train$login)
summary(train_rand$login)
head(train$login)
head(train_rand$login)

train_1 <- train_rand[1:900,]
test_1 <- train_rand[901:1000,]


install.packages("C50")
library(C50)
View(train)

train_model <- C5.0(train[-17], train$login)
summary(train_model)
View(train_model)


train_pred <- predict(train_model, test_1)
train_pred

install.packages("gmodels")
library(gmodels)
CrossTable(test_1$login, train_pred,
           prop.chisq = FALSE, prop.c=FALSE, prop.r=FALSE,
           dnn = c("actual login", "predict login"))
View(test_1)
test_1$Sex<-ifelse(test_1$Sex=="male",1,0)
test_1$past_login_total<-ifelse(is.na(test_1$past_login_total),as.integer(mean(test_1$past_login_total,na.rm = T)),test_1$past_login_total)
test_1$past_1_month_login<-ifelse(is.na(test_1$past_1_month_login),as.integer(mean(test_1$past_1_month_login,na.rm = T)),test_1$past_1_month_login)
test_1$past_1_week_login<-ifelse(is.na(test_1$past_1_week_login),as.integer(mean(test_1$past_1_week_login,na.rm = T)),test_1$past_1_week_login)


test_1$login
write.csv(test_1, "submission.csv", row.names = F)

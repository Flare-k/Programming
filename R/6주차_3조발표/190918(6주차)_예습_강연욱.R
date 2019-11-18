#gg  = grammar of graphic


gender <- c("남", "여", "남", "여", "남",
            "여", "남", "여", "남", "여",
            "남", "여", "남", "여", "남", 
            "여", "남", "여", "남", "여")
bloodType <- c('A', 'B', 'A', 'AB',
               'O', 'A', 'O', 'B',
               'A', 'O', 'O', 'B',
               'O', 'A', 'AB', 'B',
               'O', 'A', 'A', 'B')

classDF <- data.frame(gender, bloodType)
classDF
classTable <- table(classDF)
classTable

library(ggplot2)

classCovDF <- as.data.frame(classTable) #이렇게 해야 Frequency열이 추가 된다.
classCovDF

ggplot(classCovDF, aes(x=bloodType, y=Freq))

ggplot(classCovDF, aes(x=bloodType, y=Freq)) + geom_col()
ggplot(classCovDF, aes(x=bloodType, y=Freq)) + geom_col(aes(fill = gender))

library(dplyr)
library(plyr)
col_data <- data.frame(count(bloodType))

bar_data <- data.frame(bloodType)
bar_data
ggplot(bar_data, aes(x=bloodType)) + geom_bar()

ggplot(bar_data, aes(x=bloodType, fill = gender)) + geom_bar()

ggplot(bar_data, aes(bloodType, fill = gender)) + geom_bar(position = "dodge")


BloodType <- c('A', 'B', 'A', 'AB',
                 'O', 'A', 'O', 'B',
                 'A', 'O', 'O', 'B',
                 'O', 'A', 'AB', 'B',
                 'O', 'A', 'A', 'B')
Vision <- c(1.0, 1.2, 0.3, 0.4,
            0.5, 1.5, 0.6, 0.4,
            0.8, 0.7, 1.0, 2.0,
            1.2, 0.2, 0.1, 0.2,
            0.4, 0.5, 0.7, 0.8)
Blood_Vision <- data.frame(BloodType, Vision)
ggplot(Blood_Vision, aes(x=BloodType)) + geom_bar()
#Vision이 y축으로 위치하게 됨 
ggplot(Blood_Vision, aes(x=BloodType, y=Vision))+geom_bar(stat = "identity")


data("airquality")
ggplot(data=airquality,
       aes(x=Month, y=Temp, group=Month))+
  geom_boxplot(fill = 'slategrey', color = 'darkslategrey', width = 0.3,
               outlier.color = 'red', outlier.shape = 4)

ggplot(data=airquality,
       aes(x=Month, y=Temp, group=Month))+
  geom_boxplot(fill = 'lightpink', color = 'darkslategrey', width = 0.3,
               outlier.shape=NA)

ggplot(classDF, 
       aes(x=bloodType, fill = gender)) +
  geom_bar()
+ geom_bar()


ggplot(classCovDF, 
       aes(x=bloodType, y=Freq))+
  geom_col(aes(fill = gender))+
  geom_point(aes(shape=gender), size = 2)


ggplot(classCovDF, 
       aes(x=bloodType, y=Freq))+
  geom_col(aes(fill = gender))+
  geom_point(aes(shape=gender), size = 2)+
  geom_line(aes(group = gender, linetype = gender))

BloodbarChart <- ggplot(classCovDF,
                        aes(x=bloodType, y = Freq))+
  geom_col(aes(fill = gender))+
  ggtitle("비타민 혈액형 비율",
           subtitle = "(혈액형/성별 기준)")+
  labs(x="혈액형",
       y="인원수",
       fill="성별")


BloodbarChart +
  theme_classic() +
  theme(plot.title = element_text(family = "serif",
                                  face = "bold.italic",
                                  hjust = 0.5,
                                  size = 30,
                                  color = "black"),
        plot.subtitle  = element_text(family = "serif",
                                      face = "bold.italic",
                                      hjust = 0.5,
                                      size = 13,
                                      color = "black"),
        axis.title = element_text(face = "bold.italic", size = 20, color = "black"),
        axis.text.x = element_text(colour="grey20", size=15, hjust=.5, vjust=.5, face = "bold.italic"),
        axis.text.y = element_text(colour="grey20", size=15, face = "bold.italic")) +
  theme(legend.title = element_text(face = "bold", size = 15, color = "Black")) +
  theme(legend.box.background = element_rect(fill = "Black"), legend.box.margin = margin(2, 2, 2, 2))

ggplot(classCovDF,
       aes(x=bloodType, y=Freq))+
  geom_col(aes(fill=gender))+
  ggtitle("비타민 혈액형 비율", subtitle="(혈액형/성별 기준)")

ggplot(classCovDF,
       aes(x=bloodType, y=Freq))+
  geom_col(aes(fill=gender))+
  ggtitle("Rate of BITAmin's BloodType", subtitle="(Standard of BT/Gender)")+
  labs(x="BloodType",
       y="Population",
       fill="Gender")

BloodbarChart+theme_void()
BloodbarChart+theme_dark()
BloodbarChart+theme_minimal()
BloodbarChart+theme_classic()


#시계열
company <- c('A', 'A', 'A', 'A', 'B', 'B', 'B', 'B')
year <- c('1980', '1990', '2000', '2010', '1980', '1990', '2000', '2010')
sales <- c(2750, 2800, 2830, 2840, 2760, 2765, 2775, 2790)

coSalesDF <- data.frame(company, year, sales)

coSalesDF
coSa <- table(coSalesDF)
coo <- as.data.frame(coSa)
coo


ggplot(coSalesDF, aes(x=year, y=sales)) + geom_line(aes(group=company))

ggplot(coSalesDF, aes(x=year, y=sales)) + geom_line(size =2,aes(group=company, colour=company))

ggplot(coSalesDF, aes(x=year, y=sales)) + geom_line(size =2,aes(group=company, colour=company))+
  geom_point(size=2)


head(economics)

ggplot(economics, aes(x=date, y=unemploy)) + geom_line()

ggplot(economics, aes(x=date, y=unemploy)) + geom_line(size=1, color='lightblue')+
  ggtitle("연도별 실업자 수")+
  labs(x="연도",
       y="실업자 수")
#자동으로 월일 뺴고 연도만 잡는건가???

#상관관계는 인과관계의 필요조건이다.

str(cars)

plot(cars$speed, cars$dist, xlab="velocity", ylab="distance")

ggplot(data=cars, aes(x=speed, y=dist)) + 
  geom_point(shape=8, size=2, colour="red") +
  ggtitle("Scatter Plot: Speed vs Dist")

plot(cars$speed, cars$dist, xlab="velocity", ylab="distance")
lines(lowess(cars$speed, cars$dist))

ggplot(data=cars, aes(x=speed, y=dist)) + 
  geom_point(shape=8, size=2, colour="red") +
  ggtitle("Scatter Plot: Speed vs Dist")+
  stat_smooth(method = 'lm', color='black')


str(iris)

plot(iris)

plot(iris$Sepal.Width, iris$Species)

cor(iris$Sepal.Length, iris$Sepal.Width)
plot(iris$Sepal.Length, iris$Sepal.Width)

cor(iris$Petal.Length, iris$Petal.Width)
plot(iris$Petal.Length, iris$Petal.Width)

new_iris <- subset(iris, select = -Species)
cor(new_iris)

install.packages("corrplot")
library(corrplot)
cor_iris <- cor(new_iris)
corrplot(cor_iris)

corrplot(cor_iris, method = c("number"))


#트리맵

getwd()
setwd("/Users/noblyan/Desktop/R/6주차_3조발표/")
getwd()
x11()
sales_df <- read.table(file = "clipboard", header=TRUE , sep="\t")

str(sales_df)
sales_df

install.packages("treemap")
library(treemap)

library(dplyr)
library(ggplot2)

d <- diamonds
treemap(d, vSize='price', index = c('cut', 'clarity'), title="price")

d %>% filter(cut=="Ideal",clarity=="SI2")

treemap(d, vSize = "price", index=c("cut", "clarity","color"), title="price")


#군집합은 거리로 판단 

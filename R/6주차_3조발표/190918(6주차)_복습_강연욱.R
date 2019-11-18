library(plyr)
library(ggplot2)

#1
head(diamonds) #diamonds 데이터에 대한 내용확인
ggplot(diamonds, aes(clarity, fill=cut))+
  geom_bar(position = "dodge")+
  ggtitle("Diamonds")+
  theme_dark()+
  theme(plot.title = element_text(family = "serif",
                                  face = "bold.italic",
                                  hjust = 0.5,
                                  size = 30))

#2

ggplot(mpg, aes(x=class, y=cty, group=class))+
  geom_boxplot(fill="skyblue", color="black", width = 0.3,
               outlier.color = "red", outlier.shape = 4)+
  theme(axis.title = element_text(face = "bold.italic", size = 15, color="Black"),
        axis.text.x = element_text(face= "bold.italic", size = 12),
        axis.text.y = element_text(face= "bold.italic", size = 12))


#3
#월, 온도 변수 생성
month <- c(1,2,3,4,5,6,7,8,9,10,11,12)
temp <- c(1,4,11,18,23,26,28,29,35,18,11,4)

data_temp <- data.frame(month, temp) #생성한 변수들로 데이터프레임 생성.
data_temp
ggplot(data_temp, aes(x=month, y=temp))+
  geom_line(size=2, color='lightskyblue')+
  ggtitle("월 최고 기온") + labs(x='월',y='기온')+
  scale_x_continuous(breaks = seq(0,12,1))+   # x축에 대해 세밀히 조정
  scale_y_continuous(breaks = seq(0,35,5))   # y축에 대해 세밀히 조정


#4
head(airquality)   #airquality에 대한 데이터 확인

new_air <- airquality[c(-5,-6)] #month, day변수 제거
head(new_air)
new_air <- na.omit(new_air)#결측치를 제거한 것을 저장
head(new_air)
library(corrplot)
cor_new_air <- cor(new_air)
corrplot(cor_new_air, method = c("ellipse"))


#5

library(treemap)

treemap(diamonds, vSize = "price", index = c("cut", "clarity"), title = "sum_of_price")












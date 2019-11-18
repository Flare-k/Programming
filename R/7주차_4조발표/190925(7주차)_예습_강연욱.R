install.packages('ggmap')
library('ggmap')

install.packages('extrafont')
library('extrafont')

install.packages(c('devtools','curl'))
devtools::install_github("dkahle/ggmap")


Sys.setlocale("LC_ALL","ko_KR.UTF-8")

register_google(key="AIzaSyBqylSSnPgQL5jLcnZMuY77e79_W5zf-pU")

names <- c("용두암","성산일출봉","정방폭포",
           "중문관광단지","한라산1100고지","차귀도")
addr <- c("제주시 용두암길 15",
          "서귀포시 성산읍 성산리",
          "서귀포시 동홍동 299-3",
          "서귀포시 중문동 2624-1",
          "서귀포시 색달동 산1-2",
          "제주시 한경면 고산리 125")
gc <- geocode(enc2utf8(addr))

gc
class(gc)
str(gc)
#tibble???  -> 일종의 데이터 프레임
#데이터 프레임을 보기좋게 정리해둔것. 데이터프레임과 호환이 됨
#factor로 변하는걸 방지해줌 

#geocode(location="장소이름", output=c("latlon", "latlona", "more"...))
df <- data.frame(name = names,
                 lon = gc$lon,
                 lat = gc$lat)

cen <- c(mean(df$lon), mean(df$lat))                 
map <- get_googlemap(center = cen,
                     maptype = "roadmap",
                     zoom = 10,
                     size = c(640,640),
                     markers = gc)
class(gc)

str(iris)
head(iris)
class(iris)

str(gc)
as.data.frame(gc)
gc

geocode("Kyunghee university", "latlon")   #lon_위도 lat_경도
geocode("Kyunghee university", "more")
geocode("Kyunghee university", "all")

geocode(location = enc2utf8("경희대학교&language=ko"), "more")

library(ggmap)
library(ggplot2)

data("quakes")
str(quakes)

df <- head(quakes, 100)   #quakes information

cen <- c(mean(df$long), mean(df$lat))  #map location

gc <- data.frame(lon=df$long, lat=df$lat)

gc$lon <- ifelse(gc$lon > 180, -(360-gc$lon), gc$lon) ; gc$lon

library(dplyr)
get_googlemap(center = cen,
              maptype = "roadmap",
              zoom = 4,   #
              marker = gc) %>% ggmap()

#Zoom : 3(continent) ~ 21(building) 디폴트 값 : 10(city)

map <- get_googlemap(center = cen,
                     maptype = "roadmap",
                     zoom = 4,
                     marker = gc)

#테두리 꾸밈에 대한 옵션들
ggmap(map)+theme(axis.title.x = element_blank(),
                 axis.text.x = element_blank(),
                 axis.ticks.x = element_blank(),
                 axis.title.y = element_blank(),
                 axis.text.y = element_blank(),
                 axis.ticks.y = element_blank())


#mpg에 따른 원의 크기 표시
ggmap(map)+geom_point(data=df, #산점도 표현
                aes(x=long, y=lat, size=mag), #원의 크기를 mag로 표시
                alpha=0.5)  #투명도 표시


#depth에 따른 색깔 표시
ggmap(map)+
  geom_point(data=quakes, aes(x=long, y=lat, col=depth), size=1)



#지하철 2,3호선 역 나타내기
getwd()
setwd('/Users/noblyan/Desktop/R/7주차_4조발표')
data <- read.csv('/Users/noblyan/Desktop/R/지하철역위치.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")

data2 <- data[,c(2,3,8,9)]
colnames(data2) <- c('전철역명', '호선', 'x좌표', 'y좌표')

head(data2)
head(data)

library("dplyr")
#2호선 뽑기
s_2 <- data2 %>% filter(호선=='2')

#상/하행이 2호선(순환선)은 겹치므로 반만 저장함.
N <- seq(1,44,2)

s_21 <- s_2[N,]
s_21
center <- c(mean(s_2$y좌표), mean(s_2$x좌표))
seoul <- get_map(center, zoom = 11, maptype = 'roadmap')

ggmap(seoul)+geom_point(data = s_21, aes(x=y좌표, y=x좌표),
                        size=2.5, alpha=0.7)

#3호선 뽑기
s_3 <- data2 %>% filter(호선=='3')
center <- c(mean(s_3$y좌표), mean(s_3$x좌표))
seoul <- get_map(center, zoom = 11, maptype = 'roadmap')

ggmap(seoul)+geom_point(data = s_3, aes(x=y좌표, y=x좌표),
                        size=2.5, alpha=0.7)


#2,3호선 표시

ggmap(seoul, size=c(300,300))+
  geom_point(data=s_2, aes(x=y좌표, y=x좌표), size=2.5, alpha=0.8, col='black', fill='white', stroke=3, shape=21)+
  geom_point(data=s_3, aes(x=y좌표, y=x좌표), size=2.5, alpha=0.8, col='red')+
  geom_line(data=s_3, aes(x=y좌표, y=x좌표), linetype=1)+
  geom_label(data=s_3, aes(x=y좌표, y=x좌표+0.005, label=전철역명, fontface='bold'), size=2)+  #0.005는 시각적인 모습때메 조금 조절한것일뿐.
  geom_text(data=s_2, aes(x=y좌표, y=x좌표+0.005, label=전철역명), size=2.8)+
  theme(axis.title.x = element_blank(),
        axis.text.x = element_blank(),
        axis.ticks.x = element_blank(),
        axis.title.y = element_blank(),
        axis.text.y = element_blank(),
        axis.ticks.y = element_blank(),
        panel.background = element_rect(fill='green'), legend.position = 'right')

names <- c("용두암","성산일출봉","정방폭포",
           "중문관광단지","한라산1100고지","차귀도")
addr <- c("제주시 용두암길 15",
          "서귀포시 성산읍 성산리",
          "서귀포시 동홍동 299-3",
          "서귀포시 중문동 2624-1",
          "서귀포시 색달동 산1-2",
          "제주시 한경면 고산리 125")
gc <- geocode(enc2utf8(addr))

jeju <- data.frame(name = names,
                 lon = gc$lon,
                 lat = gc$lat)

cen <- c(mean(jeju$lon), mean(jeju$lat))

get_googlemap(center = cen,
              maptype = 'roadmap',
              zoom = 10,
              size = c(640,640),
              marker = gc) %>% ggmap()


data <- read.csv('/Users/noblyan/Desktop/R/poppulation_2014.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")

head(data)
region <- data$지역명
lon <- data$lon
lat <- data$lat
pop <- data$population

data <- data.frame(region, lon, lat, pop)

head(data)

data[8,2] <- 127.296620
data[8,3] <- 36.535268

center <- c(mean(data$lon), mean(data$lat))
map <- get_map(loacation = center, maptype = "watercolor", zoom = 5)
m1 <- ggmap(map) ; m1

m1+geom_point(data = data, aes(x=lon, y=lat))


m1+geom_point(data=data, aes(x=lon, y=lat, color=pop, size=pop))+
  geom_text(data=data, aes(x=lon, y=lat+0.1, label=region), size=3)+
  scale_color_continuous(name="인구")+
  scale_size_continuous(name="인구")
  
  
  

data <- read.csv('/Users/noblyan/Desktop/R/university.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")
head(data)  
str(data)  

library(ggmap)
map <- get_map("seoul", zoom=11, maptype="watercolor")
ggmap(map)

map2 <- ggmap(map)+
  geom_point(data=data,
             aes(x=lon, y=lat, color=학교명),
             size=3)

map2 + geom_text(data=data,
                 aes(x=lon+0.01, y=lat+0.01, label=학교명),
                 size=3)


map2 + geom_text(data=data,
                 aes(x=lon+0.01, y=lat+0.01, label=학교명),
                 size=3)+
  scale_color_discrete(name="학교명")










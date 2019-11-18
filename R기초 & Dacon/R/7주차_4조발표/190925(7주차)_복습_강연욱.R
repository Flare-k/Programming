library(ggmap)
library(ggplot2)
library(dplyr)


#1-1
register_google(key="AIzaSyBqylSSnPgQL5jLcnZMuY77e79_W5zf-pU")

names <- c("뉴오더클럽")
addr <- c("서울 마포구 동교로34길 3")

gc <- geocode(enc2utf8(addr))
gc

df <- data.frame(name=names,
                 lon=gc$lon,
                 lat=gc$lat)
cen <- c(mean(df$lon), mean(df$lat))

map <- get_googlemap(center=cen,
                     maptype = "hybrid",
                     zoom = 18,
                     size=c(640,640),
                     marker=gc)#지도 그리기
gmap <- ggmap(map)

gmap + geom_text(data = df, 
                 aes(x = lon, y = lat),
                 size=5,
                 label=df$name)

#1-2
myLoc <- geocode("서울특별시 서대문구 신촌동 134", "latlon")

cen <- c(mean(myLoc$lon), mean(myLoc$lat))
map1 <- get_googlemap(center = cen,
                      maptype = "hybrid",
                      zoom = 18,
                      size = c(640,640),
                      marker = myLoc)#지도 그리기
ggmap(map1)


#2-1

data <- read.csv('/Users/noblyan/Desktop/R/7주차_4조발표/서울시장난감도서관위치현황.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")

lib_toy <- get_map("seoul", zoom=11, maptype = 'roadmap')   #지도 그리기

ggmap(lib_toy)+geom_point(data=data, aes(x=LON, y=LAT), size=2.5, alpha=1.0, col='red')


#2-2
ggmap(lib_toy)+geom_point(data=data, aes(x=LON, y=LAT), size=2.5, alpha=1.0, col='red')+
  geom_text(data=data,aes(x=LON, y=LAT+0.005),label=data$Name,size=2.5)



#3-1
map <- get_map(location='south korea', zoom=7, maptype='roadmap', color='bw')#지도 그리기
ggmap(map)

airport <- read.csv('/Users/noblyan/Desktop/R/7주차_4조발표/airport.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")
route <- read.csv('/Users/noblyan/Desktop/R/7주차_4조발표/route.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")

head(airport)
head(route)

#3-2
ggmap(map) + geom_point(data=airport, aes(x=lon, y=lat))

#3-3
ggmap(map) + geom_point(data=airport, aes(x=lon, y=lat))+
  geom_line(data=route, aes(x=lon, y=lat, group=id))


#4-1
wifi <- read.csv('/Users/noblyan/Desktop/R/7주차_4조발표/wifi2.csv', header = T,fileEncoding = "CP949",encoding = "UTF-8")
head(wifi)

ggmap(map) + geom_point(data=wifi, aes(x=lon, y=lat, color=company))

#4-2
ggmap(map) + stat_density_2d(data=wifi, aes(x=lon, y=lat))


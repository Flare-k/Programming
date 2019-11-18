[Data fields]
① train.csv - 서울시 날짜에 따른 시간별 기상상황과 따릉이 대여 수 (기간: 2017년 4월, 5월)

id : 날짜와 시간별 id
temperature : 기온
precipitation : 비가 오지 않았으면 0, 비가 오면 1
windspeed : 풍속(평균)
humidity : 습도
visibility : 시정(視程), 시계(視界)(특정 기상 상태에 따른 가시성을 의미)
ozone : 오존
pm10 : 미세먼지(머리카락 굵기의 1/5에서 1/7 크기의 미세먼지)
pm2.5 : 미세먼지(머리카락 굵기의 1/20에서 1/30 크기의 미세먼지)
count : 시간에 따른 따릉이 대여 수

③ submission.csv : submission 파일의 예시
id : 날짜와 시간별 id
count : 예측한 대여 수 기입 


getwd()
setwd("/Users/noblyan/Desktop/따릉이")
getwd()
train_final <- fread("/Users/noblyan/Desktop/따릉이//train_final.csv", header = T)
test_final <- fread("/Users/noblyan/Desktop/따릉이/test_final.csv", header = T)

View(train_final)

table(is.na(train_final$id))
table(is.na(train_final$hour))
table(is.na(train_final$hour_bef_temperature))

train_final$hour_bef_temperature <- ifelse(is.na(train_final$hour_bef_temperature), as.integer(mean(train_final$hour_bef_temperature, na.rm = T)), train_final$hour_bef_temperature)
table(is.na(train_final$hour_bef_temperature))

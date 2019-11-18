myfunc01 = function(){
  return(1)
}
myfunc01()

my_fun = function(i,j){
  k = (i+j)*2
  return(k)
}
class(my_fun)
my_fun(2,3)


input = c(1,2,3)
my_fun2 = function(obj){
  obj = obj*2
  input = obj
  return(obj)
}
my_fun2(input)

input

#제곱
mypower01 = function(n){
  n = n*n
  return(n)
}
mypower01(3)

#2 _ 반복문 쓸 경우
mypower02 = function(x, y){
  num = 1
  for(i in 1:y){
    num = num*x
  }
  return(num)
}
#2 _ 반복문 안 쓸 경우
mypower03 = function(x, y){
  r = x^y
  return(r)
}
mypower02(3,4)
mypower02(3,5)
mypower03(3,4)


# 2.6.2 제어문 실습

# Q.1
myindex = function(x){
  if(x>1){
    return(1)
  }
  else{
    return(0)
  }
}
myindex(9)
myindex(-9)

# Q.2
mydistance = function(a, b){
  if(a-b >= 0){
    return(a-b)
  }
  else{
    return(-(a-b))
  }
}
mydistance(1,2) ; mydistance(2,1)


# 2.6.2 if/else 실습
#iris 데이터에 Sepal.Length가 5미만인 경우 very short 
# 5~6 short / 6~7 long / 7~ very long
data(iris)
iris$Sepal.Length
iris
aa <- ifelse(a <- c(iris$Sepal.Length < 5), a <- "very short", 
             ifelse(b <- c(iris$Sepal.Length >= 5 & iris$Sepal.Length < 6), b <- "short",
                    ifelse(c <- c(iris$Sepal.Length >= 6 & iris$Sepal.Length < 7), c <- "long",  "very long")))
iris$Sepal.Length <- aa

iris






#2.6.2.2 for 실습

#Q.1
myeven = function(x){
  sum = 0
  for(i in 1:x){
    if(i%%2 == 0){
      sum = sum + i
    }
  }
  return(sum)
}
paste("1~4의 짝수들의 합 = ",myeven(4))


# Q.2_1
x <- c(1,2,3,NA,4,5,NA)

myplus01 = function(x){
  sum = sum(na.omit(x))
  return(sum)
}
myplus01(x)


# Q.2_2
myplus02 = function(x){
  sum1 = 0
  for(i in 1:length(na.omit(x))){
    sum1 = sum1 + i
  }
  return(sum1)
}
myplus02(x)


# Q.2_3
myplus03 = function(vec){
  d = 0
  for(i in 1:length(vec)){
    if(is.na(vec[i])){
      next
    }else{
      d = d+vec[i]
    }
  }
  return(d)
}

myplus03(x)


#객체 조회/삭제/저장/불러오기

getwd()
setwd("/Users/noblyan/Desktop")
getwd()

v_vector = c(1,2,3,4,5)
v_df <- data.frame(v_vector)
ls()
save(v_vector, v_df, file='save_test.rdata')
rm(list = ls())
load("save_test.rdata")
v_vector


ls()

getwd()
ex_csv_df = read.table(file = "exam.csv", header = T, sep=",", stringsAsFactors = F, fileEncoding = "euc-kr")
ex_csv_df
ex_csv_df <- read.csv(("/Users/noblyan/Desktop/exam.csv"),fileEncoding = "euc-kr")
read.csv("exam.csv",fileEncoding = "euc-kr")

str(ex_csv_df)

#col.names = 변수이름을 첫행에 넣을 것인가? TRUE라 하면 첫행에 변수이름이.. (안 써줘도 디폴트 값임)
#row.names = csv로 저장하면 앞에 인덱스가 붙는데 그걸 안 붙게 해줌.
#만약 추가적인 내용을 같은 이름의 파일에 이어 붙이고 싶으면 col.names를 FALSE로 두면 된다. 그리고 append는 TRUE로.


install.packages("dplyr")
library("dplyr")



myfunc01 <- function(){
  return(1)
}

myfunc01()

my_fun <- function(i, j){
  k=(i+j)*2
  return(k)
}

class(my_fun)
my_fun(2,3)

my_fun = function(i, j){ (i+j)*2}
my_fun(2,4)

mypower01 = function(i){
  return (i*i)
}
mypower01(3)

input = c(1,2,3)
my_fun2 = function(obj){
  obj = obj*2
  input = obj
  return(obj)
}
my_fun2(input)
input = my_fun2(input)
input
my_fun2(input)


my_fun3 = function(score){
  if(score >= 80){
    "합격"
  }
  else{
    "불합격"
  }
}
70 >= 80
my_fun3(70)
my_fun3(90)

my_fun4 = function(score){
  ifelse(score >= 80, "합격", "불합격")
}
my_fun4(70)
my_fun4(90)

my_fun4_1 = function(score){
  ifelse(score >= 80, "고득점", ifelse(score >= 60 & score < 80, "평타", "망함"))
}
my_fun4_1(70)
my_fun4_1(59)

my_fun5 = function(score){
  if(score >= 80){
    "합격"
  }
  else if(score >= 75){
    "대기"
  }
  else{
    "불합격"
  }
}
my_fun5(70)
my_fun5(78)
my_fun5(90)

my_fun5_1 = function(score){
  ifelse(score>=80, "합격", ifelse(score>=75, "대기", "불합격"))
}
my_fun5_1(78)


my_fun6 = function(num){
  for(x in 1:10){
    print(num + x)
  }
}

my_fun6(10)

myloop2 = function(){
  a = 0
  for (i in 3:7){
    a = a+1
  }
  return(a)
}
myloop2()

mysum = function(n){
  i = 0
  for(j in 1:n){
    i = i+j
  }
  return(i)
}
mysum(10)

b = c()
num = 10
for (i in 1:10){
  b = c(b, num+i)
}
b

n = 3
m = 1:9
for (i in m){
  times = n*i
  print(paste(n,"x",i,"=",times))
}


x = 0
y= 0
while(y<=10){
  x = x+y
  y = y+1
}
x;y

ls()
setwd("/Users/noblyan/Desktop")
getwd()

ex_csv_df <- read.table(file = "exam.csv", header=TRUE, sep=",", stringsAsFactors=FALSE, fileEncoding = "euc-kr")
str(ex_csv_df)
ex_csv_df

write.table(ex_csv_df, file = "test_file_save.csv", sep=",", col.names=T, row.names=F, append = F)
write.csv(ex_csv_df, "test_file_save.csv", row.names=F)
write.table(ex_csv_df, file = "test_file_save.csv", sep=",", col.names = F, row.names = F, append = T)


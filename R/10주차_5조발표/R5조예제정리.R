library(ggplot2)
theme_set(theme_bw(base_family = "AppleGothic"))

# d = probability Density = 확률을 계산(정규분포의 PDF)
# p = cumulative Probability = 누적 확률을 계산(정규분포의 CDF)

#PDF(Probability Density Function)
#1
plot(x=100:500, y=dnorm(100:500, mean=300, sd=8), type = 'l', xlab = 'Score', ylab = 'Probability')#평균이 300, 표준편차가 8인 정규분포에서 x값이 100~500인 확률 값.
#2
x <- seq(-10,10, length = 200)
plot(x, dnorm(x, mean=0, sd=1), type = 'l', main="Probability Density Function")
#3
sample <- seq(-5,5, length = 101)
plot(sample, dnorm(sample, mean = 0, sd=1),type = 'l', main = "Probability Density Function")
#4
#확률밀도함수
height=rnorm(n=1000000, mean=175, sd=5) #데이터생성 
hist(height, breaks=100, probability = T)
lines(density(height))
#4-1
hist(height, breaks=20, probability=TRUE)
hist(height, breaks=100, probability=TRUE)#정규분포는 연속확률분포의 일종으로, 평균에 대하여 대칭인 그래프를 가진다.
lines(density(height))

#CDF(Cumulative Density Function)
#1
pnorm(312,300,8) - pnorm(288,300,8)#288~312에 x값이 있을 확률 // 누적분포함수의 값계산
#2
cdf <- seq(-10,10,length = 200)
plot(cdf, pnorm(cdf, mean = 0, sd=1),type = 'l', main = "Cumulative Density Function")
#3
sample <- seq(-5,5, length = 101)
plot(sample,pnorm(sample, mean = 0, sd=1), type='l',main = "Cumulative Density Function")


# q = probability Quantility = 누적 확률의 inverse
#분위수
qnorm(p=0.025, mean = 0, sd=1, lower.tail = T)
qnorm(p=0.975, mean = 0, sd=1, lower.tail = T)
#따라서 95% 적중구간에 대한 값은 많이 나오는 -1.96 이상  +1.96 이하의 범위로 설명된다.



# r = probability Random = 주어진 정규분포로 랜덤 값 생성
#난수
rnorm(100, mean = 0, sd = 1)
hist(rnorm(100, mean = 0, sd = 1))
hist(rnorm(100000, mean = 0, sd = 1))
#중심극한 정리에 의해 랜덤 개수 n이 증가할 수록 점차 표준 정규분포에 가까운 hist가 그려지는것을 확인할 수 있다.


#중심극한정리..
#샘플 수가 적당히 크면(n>=30 정도) 표본의 확률분포가 정규분포에 가깝다는 정리

#예를들어 한 반의 학생이 40명인데 시험을 보았다. 시험은 100점 만점이다. 
#3명에게 무작위로 점수를 물어보고 평균을 낸 다음, 이와 같은 행위를 2000번 정도 하면 표본의 평균이 2000개가 생기게 된다.
#이 2000번에 대한 분포를 히스토그램으로 보면 평균에 해당하는 히스토그램 막대가 가장 높이 나타난다.
#1
set.seed(0529) #난수 시드를 설정
score<-sample(1:100, 40, replace=T) #1~100까지 40명에 대해 난수의 값을 할당해준다.
score
mean(score)#표본에 대한 평균과 분포를 확인한다.
hist(score)  #현재까지의 내용에 대해 히스토그램으로 표현

students <- NULL
students <- sapply(1:2000, function(i)mean(sample(score,3,replace=T)))
hist(students)  #3명을 복원추출로 뽑아서 평균을 계산하고, 이를 2000번 반복한다.

mean(students)
#이번에는 30명을 복원추출로 뽑아서 평균을 계산하고, 이를 2000번 반복한다.
students <- NULL
students <-  sapply(1:2000, function(i)mean(sample(score, 30, replace=T)))
hist(students, breaks = 30)
mean(students)


b_time <- sample(395:405, 100, replace=T)
battery <- NULL
battery <- sapply(1:100, function(i)mean(sample(b_time, 25, replace = T)))
mean(battery)
#2
#1~6의 수를 가진 주사위를 5번씩 던지며 그 작업을 500번 반복하는 데이터를 R에서 제공하는 sample 함수를 통해서 만들어보자.
dice <- matrix(sample(1:6, 5*500, replace=T), ncol=5, byrow=T)
#총 2500번 던지며 주사위 특성상 중복이 가능하기때문에 replace값을 True로 설정.
#matrix함수로 matrix 타입으로 변환 후 dice라는 변수에 할당.
head(dice)

#각 열별로 평균값 구할 것
#solution 1
rowMeans(dice)
#solution 2
apply(dice, 1, mean)

#지금까지의 내용을 함수로 작성
central_limit <- function(no.throw=5, no.rep = 500){
  exp.res<-matrix(sample(1:6, no.throw*no.rep, replace=T), ncol = no.throw, byrow = T)
  return(rowMeans(exp.res))
}

hist(central_limit(no.throw = 5, no.rep = 50000), nclass = 20, col = "light grey", border = "grey", main = "Central Limit Theorem")














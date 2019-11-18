#포아송, 랜덤으로 추출한 경우.
poisson1 <- rpois(n=10000, lambda = 1)
poisson2 <- rpois(n=10000, lambda = 2)
poisson3 <- rpois(n=10000, lambda = 3)
poisson10 <- rpois(n=10000, lambda = 10)
poisson20 <- rpois(n=10000, lambda = 20)

hist(poisson1)
hist(poisson2)
hist(poisson3)
hist(poisson10)
hist(poisson20)

#정규분포에서 1~2 색 채우기
x <- seq(-3, 3, length = 100) #-3~3에서 순서대로 100개의 값
y <- dnorm(x) 
plot(x, y, type = "l") 
abline(h = 0) 
xlim <- x[1 <= x & 2 >= x]
ylim <- y[1 <= x & 2 >= x] 
xlim <- c(xlim[1], xlim, tail(xlim, 1))
ylim <- c(0, ylim, 0)
polygon(xlim, ylim, density = 20)



#정규분포 그릴 수 있는 함수 만들기. 
drawND<-function(mean,sigma){
  
  x<-seq(-5,5, length=100); # x는 -5에서 5사이에 순서대로 100개 값을 구한다.
  y <- dnorm(x); # 나온 100개의 x 값에 해당하는 정규분포 높이 값 y를 100개 구한다.
  #y<-(1/sqrt(2*pi*sigma))*exp(-((x-mean)^2/2*(sigma^2))) 와 같은 의미
  plot(x,y, type="l"); # 두 점을 연결하는 것을 직선으로 한다
  
}
drawND(0, 1)#결과 호출..




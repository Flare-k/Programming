#제곱
mypower01 = function(n){
  n = n*n
  return(n)
}
mypower01(3)

#거듭제곱
mypower02 = function(x,y){
  j=1
  for(i in 1:y){
    j=j*x
  }
    return(j)
}
mypower02(3, 4)

#조건문 1
myindex = function(x){
  if(x>1){
    return(1)
  }
  else{
    return(0)
  }
}
myindex(2)

#조건문 2

mydistance = function(a, b){
  if(a-b < 0){
    return(-1*(a-b))
  }
  else{
    return(a-b)
  }
}
mydistance(1, 2); mydistance(2,1)


# if/else _ 1
attach(iris)
if(Sepal.Length < 5){
  Sepal.Length = "very short"
}

#for문 _ 1
myeven = function(x){
  sum = 0
  for(i in 1:x){
    if(i%%2 == 0){
      sum = sum + i
    }
  }
  return(sum)
}
myeven(10)

#for문 _ 2







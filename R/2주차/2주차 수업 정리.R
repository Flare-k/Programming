id <- c(1:4)
name <- c("갑","을","병","정")
age <- c(22,34,30,28)
isMarried <- c(F,T,F,T)
df <- data.frame(id,name,age,isMarried)
df

#열 = 변수 
str(df)
#stringAsFactors는 디폴트 값으로 문자열을 팩터로 변환한다. 
#그래서 팩터를 문자열로 바꿔주려면 stringAsFactors = F를 해줘야한다.
df <- data.frame(id,name,age,isMarried, stringAsFactors = F)
str(df)

#df[행, 열]
df[c(1,2)]
df[c(1,2),]
df[1]

#df$name >> 변수의 값이 1차원 형태인 벡터로 출력된다.
df$name
df$id
str(name)
class(name)


iris
cars
str(iris)
iris$Species
str(iris$Species)
head(iris)
head(iris,11)
level(iris$Species)
levels(iris$Species) #범주를 찾아줌
levels(iris$Sepal.Length)
nrow(iris) #행의 개수
ncol(iris) #열의 개수
dim(iris) #행과 열의 개수
table(iris)
summary(iris)
# 1st Qu = 첫번째 사분위수 , Median = 2번째 사분위수, 3rd =세번째 사분위수, Max = 4번째 사분위수 

View(iris)  #엑셀과 같은 기능을 해준다.

subset(iris, Sepal.Length > 7)
subset(iris, Sepal.Length > 7 & Petal.Length < 6.5)
iris$Sepal.Length
Sepal.Length

# subset(데이터, 조건, select = 열)
subset(iris, Sepal.Length>7, select=3)

sub_dat <- subset(iris, Sepal.Length > 7 & Petal.Length < 6.5, select = -c(2,4))
#이렇게 하면 의도치 않은 열이 제거될 가능성이 있으므로 추천 ㄴㄴ
sub_dat
iris

iris[iris$Sepal.Length > 7 & iris$Petal.Length <= 6.5 , ]
#subset은 변수이름을 써주면되는데 인덱싱의 경우 $기호를 필요로함.. 그래서 
#subset이 좀더 편할수도있다..

attach(iris) #이렇게 하면 인덱싱을 이용할 경우 $을 안써도 된다.
iris[Sepal.Length >7 & Petal.Length <= 6.5 , ]

iris[Sepal.Length >7 & Petal.Length <= 6.5 , ][2,3]
head(iris[,c("Sepal.Length")])
head(iris[,c("Sepal.Length"), drop = F])

df
which(df == T, arr.ind=T)


ex_df <- data.frame(name=c("이정민","김영석","고광민","최지은"),age=c(24,24,23,23),sex=c("남","남","남","여"), stringsAsFactors=F)
ex_df

a <- order(ex_df$age) #나이가 적은순으로 위치값을 정렬

ex_df[a,]


b <- order(ex_df$age, decreasing = T)  #나이가 많은순으로 위치값을 정렬
ex_df[b,]

ex_df[1,3] <- "여"
ex_df
wh_idx <- which(ex_df =="여", arr.ind =T)
wh_idx
ex_df[wh_idx] <- "남"
#wh_idx가 행,렬의 정보를 가져왔기때문에 []안에 넣어도 문제 없다.
ex_df

data(iris) #원래 내장 데이터가 리셋된 상태로 불러와 짐

#새로운 변수를 넣고 싶으면 $새로운변수 를 해준다. 알아서 오른쪽 끝 열에 추가된다.
new_iris <- iris
new_iris$new <- "강연욱"   #알아서 행의 개수만큼 복사를 한다.. 150개가 생김.
head(new_iris, 3)

#추가한 변수 제거
new_iris <- new_iris[, -1]
head(new_iris,3)

new_iris$new <- NULL
head(new_iris,3)

new_iris <- iris
#열(변수) 이름 바꾸기
colnames(new_iris)
df
df[1,2]
df[2]
df[2,]
df

#리스트 생성
vec_1 <- c(1:5)
vec_2 <- rep(c(T,F),c(2,3))
vec_3 <- data.frame(name=c("a","b","c","d"),age=seq(22,28,2))
vec_list <- list(vec_1,vec_2,vec_3)
vec_list
vec_list[[1]]
vec_list[1]
names(vec_list)

vec_list <- list(v1 = vec_1, v2 = vec_2, v3= vec_3)
names(vec_list)

names(vec_list) <- c("1st", "2nd", "3rd")
names(vec_list)
vec_list$"1st"
# $를 이용하면 리스트나 데이터프레임 값등이 1차원 벡터로 표현되게 해준다.
vec_list$`2nd`
View(vec_list)
vec_list[[2]][2]

vec_list[[3]]
vec_list[[3]] <- c(2:6)   #값의 수정은 데이터타입을 신경쓰지 않고 바꿀수 있다. 
vec_list[[3]]



"variable" <- c(2:3)

vec_list[-2]
vec_list[[-1]]
vec_list
vec_list[-1]
vec_list
vec_list[[-1]]
vec_list
#값을 지운것을 유지하고 싶으면 새로운 변수에다가 할당해주는것이다. 

vec_list
vec_list[-1]
vec_list
#추가는 계속 추가된채로 업데이트가 되는데 삭제는 일시적?? >> Yes!


#apply() 함수
str(iris)
iris_setosa <- subset(iris, Species == "setosa", select = c(-Species))
apply(iris_setosa, 1, mean) #행 별 평균
apply(iris_setosa, 2, mean) #열 별 평균

korea_temp <- list("경기" = c(-10, 2, 1, -2), "강원" = c(0, -4, -5, -10))

result_lapply <- lapply(korea_temp, mean) #리스트로 출력
result_sapply <- sapply(korea_temp, mean) #벡터로 출력
result_lapply; result_sapply



#tapply & aggregate
tapply_dat <- tapply(iris$Sepal.Length, iris$Species, mean) ; tapply_dat
#(목표변수,그룹변수, 함수)
aggre_dat <- aggregate(Sepal.Length~Species, iris, mean) ; aggre_dat
#(목표변수~그룹변수, 데이터, 함수)
totalaggre_dat <- aggregate(.~Species, iris, mean); totalaggre_dat

airquality




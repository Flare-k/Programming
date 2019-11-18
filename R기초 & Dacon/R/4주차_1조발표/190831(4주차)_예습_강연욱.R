install.packages("dplyr")

library(dplyr)

update("dplyr")

search()

searchpaths()

.libPaths()

help(package = "dplyr")

install.packages("ggplot2")

library(ggplot2)

#mpg데이터프레임화
mpg <- as.data.frame(ggplot2::mpg)
head(mpg)
tail(mpg)
summary(mpg)

str(mpg)

library(dplyr)

mpg %>% select(fl)
select(mpg, fl)

mpg %>% filter(cyl > 5)
select(mpg, fl)

mpg %>% arrange(hwy)

mpg %>% arrange(desc(hwy))

mpg <- mpg %>% mutate(centry = ifelse(year >= 2000, "20th", "19th")) #변수 추가
str(mpg)

dit.table <- mpg %>% summarise(min.cty = min(cty), max.cty = max(cty))
dit.table

mpg$manufacturer <- as.factor(mpg$manufacturer)
mpg %>% group_by(manufacturer) %>% summarise(min.cty = min(cty), max.cty = max(cty))

table(mpg$fl)

fuel <- data.frame(fl = c("c", "d", "e", "p", "r"),
                   price_fl = c(2.35, 2.38, 2.11, 2.76, 2.22),
                   stringsAsFactors = F)
fuel


mpg_new <- left_join(mpg, fuel, by = "fl")
mpg_new %>% select(fl, price_fl) %>% head()


group_a <- data.frame(id = c(1,2,3,4,5),
                      test = c(60, 80, 70, 90, 85))
group_b <- data.frame(id = c(1,2,3,4,5),
                      test = c(70, 83, 65, 95, 80))
group_all <- bind_rows(group_a, group_b)
group_all

data(mpg)
mpg %>% filter(year == 2008)

mpg %>% filter(year != 2008)

mpg %>% filter(year == 2008 & cty>18)

mpg %>% filter(year == 2008 | cty>18)

mpg %>% filter(manufacturer %in% c("audi","dodge","forge","hyundai","jeep"))

cty18low <- mpg %>% filter(cty<18)
cty18up <- mpg %>% filter(cty>18)
cty18 <- mpg %>% filter(cty==18)
list(`도시연비18미만`=nrow(cty18low),`도시연비18`=nrow(cty18),`도시연비18미만`=nrow(cty18up))

mpg %>% select(manufacturer)
mpg %>% select(1)
mpg %>% select(starts_with("m"))
mpg %>% select(ends_with("r"))
mpg %>% select(contains("r"))
mpg %>% select(matches("y"))
mpg %>% select(matches(".y"))
mpg %>% select(matches("y."))
mpg %>% select(matches(".y."))


mpg %>% filter(cty > 18) %>% select(manufacturer,cty,hwy)
subset(mpg, c(manufacturer,cty,hwy), subset = (cty>18))
mpg %>% 
  filter(cty > 18) %>% 
  select(manufacturer,cty,hwy) %>% 
  head

mpg %>% 
  filter(cty > 18) %>% 
  select(manufacturer,cty,hwy) %>% 
  head(10)

mpg %>%
  arrange(cty) %>% 
  head

mpg %>% 
  arrange(desc(cty)) %>% 
  head(5)

mpg %>% 
  arrange(desc(cty), desc(hwy)) %>% 
  head(5)

mpg %>% 
  arrange(manufacturer)

mpg %>% 
  mutate(tot = (cty + hwy)/2) %>% 
  head
mpg %>% 
  mutate(tot = (cty + hwy)/2) %>% 
  mutate(test = ifelse(tot>=23,"pass", "fail"))

head


mpg %>% 
  filter(manufacturer=="hyundai") %>% 
  select(manufacturer,year,cty, hwy) %>%
  mutate(tot = (cty+hwy)/2)         

exam1 <- data.frame(id=c(1,2,3,4),
                    math=c(80,75,90,95),
                    english=c(60,80,55,80))
exam1

exam1 %>% summarise(mean_math = mean(math))
exam1 %>% summarise(median_math = median(math))
exam1 %>% summarise(sd_math = sd(math))   #표준편차
exam1 %>% summarise(sum_math = sum(math))
exam1 %>% summarise(sum(math)) #합계 (변수설정 X)

exam1 %>% summarise(mean(math),median(math),min(math))
summarise(exam1,mean_math=mean(math),max_math=max(math)) #변수 설정 O
summarise(exam1,mean(math),max(math)) #변수 설정 O

total<-data.frame(id=c(1,2,3),midterm=c(60,80,70),final=c(70,83,65))
summary(total)

summary(total$midterm)

summarise(total,midterm)

summarise(total,mean(midterm))

summarise(total,eunjo=mean(midterm))

exam <- data.frame(class=c(2,1,2,1,1,2),
                   english=c(98,97,86,98,80,89),
                   science=c(50,60,78,58,65,98))
exam

exam %>% group_by(class) %>%
  summarise(mean_science = mean(science))


mpg %>% group_by(manufacturer, model) %>% summarise(mean_cty = mean(cty)) %>% head()



group_a <- data.frame(id=c(1,2,3),
                      test=c(60,80,70))
group_b <- data.frame(id=c(4,5,6),
                      test=c(70,83,65))
group_a;group_b
group_ab <- bind_rows(group_a,group_b)
group_ab


test1 <- data.frame(id=c(1,2,3),
                    midterm=c(60,80,70))
test2 <- data.frame(id=c(1,2,3),
                    final=c(70,83,65))
test1;test2;

total <- left_join(test1, test2, by = "id")
total


library(dplyr)
inf1 <- data.frame(ID=c(1,2,3,4,6,7),
                   SEX=c("F","F","M","F","M","F"),
                   height=c(180,175,166,163,185,155))

inf2 <- data.frame(ID=c(1,2,3,5,7,8),
                   weight=c(70,65,55,50,85,45))
inf1;inf2

inf_inner <- inner_join(inf1,inf2,by="ID")
inf_inner

inf_full <- full_join(inf1,inf2,by="ID")
inf_full

inf_full %>% arrange(ID)


data_a <- data.frame(ID=c(1,2,3),
                     AREA=c("서울","부산","제주"))
data_b <- data.frame(ID=c(1,2,4),
                     SEX=c("남","여","남"))
data_a;data_b

#left join
left_join(data_a,data_b,by="ID")

#inner join
inner_join(data_a,data_b,by="ID")

#full join
full_join(data_a,data_b,by="ID")

library(ggplot2)
head(mpg) 

mpg %>%
  group_by(manufacturer) %>%
  filter(class == "suv") %>%
  mutate(tot = (cty+hwy)/2) %>%   #통합 연비 변수 추출
  summarise(mean_tot = mean(tot)) %>% #통합 연비 평균 산출
  arrange(desc(mean_tot)) %>%
  head(5)

fuel<-data.frame(fl=c("c","d","e","p","r"),price_fl=c(2.35,2.38,2.11,2.76,2.22),stringsAsFactors=F)
fuel

mpg_left <- left_join(mpg,fuel,by="fl")
View(mpg_left)

mpg_left %>%
  select(model,fl,price_fl) %>%
  head(10)

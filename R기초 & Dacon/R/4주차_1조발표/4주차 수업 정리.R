library(dplyr)
search()
searchpaths()

.libPaths()
update.packages("dplyr")


library(ggplot2)
mpg
mpg %>% filter(manufacturer %in% c("audi", "jeep"))


rm(list = ls())
ls()
mpg <- as.data.frame(ggplot2::mpg)
mpg

cty18low <- mpg %>% filter(cty < 18)
cty18up <- mpg %>% filter(cty > 18)
cty18 <-  mpg %>% filter(cty == 18)
View(cty18low)

View(list("도시연비18미만" = nrow(cty18low), "도시연비18초과" = nrow(cty18up), "도시연비18" = nrow(cty18)))

mpg %>% 
  filter(manufacturer == "audi", cty < 18) %>% 
  select(manufacturer, hwy, cty)

mpg %>% 
  filter(manufacturer == "hyundai") %>% 
  select(manufacturer, year, cty, hwy) %>%
  mutate(avg = (cty+hwy)/2) %>% 
  arrange(desc(avg), desc(cty)) %>% 
  head(10)


exam <- data.frame(class = c(2,1,2,1,1,2), 
                   english = c(98, 97, 86, 98, 80, 89), 
                   math = c(50, 60, 78, 58, 65, 98))
exam


inf1 <- data.frame(ID=c(1,2,3,4,6,7),
                   SEX=c("F","F","M","F","M","F"),
                   height=c(180,175,166,163,185,155))

inf2 <- data.frame(ID=c(1,2,3,5,7,8),
                   weight=c(70,65,55,50,85,45))
inf1;inf2

inf_inner <- inner_join(inf1, inf2, by = "ID")
View(inf_inner)

full_inner <- full_join(inf1, inf2, by = "ID")
View(full_inner)
full_inner



# 회사별로 “suv” 자동차의 
# 도시 및 고속도로 통합 연비 평균을 구해
# 내림차순으로 정렬하고, 
# 1~5위 출력하기
mpg %>% 
  group_by(manufacturer) %>% 
  filter(class == "suv") %>% 
  mutate(avg = (cty+hwy)/2) %>% 
  summarise(mean_avg = mean(avg)) %>% 
  arrange(desc(mean_avg)) %>% 
  head(5)

table(mpg$manufacturer)


fuel <- data.frame(fl = c("c", "d", "e", "p", "r"),
                   price_fl = c(2.35, 2.38, 2.11, 2.76, 2.22),
                   stringsAsFactors = F)
fuel
mpg_left <- left_join(mpg, fuel, by="fl")
View(mpg_left)






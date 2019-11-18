#1
library("dplyr")
library("ggplot2")
#dplyr & ggplot2 패키지 불러오기.
diamonds   #diamonds 데이터 호출
diamonds <- as.data.frame(ggplot2::diamonds)
str(diamonds)
diamonds %>% filter(clarity == 'SI2' & price <= 400)


#2
diamonds %>% select(contains("a")) %>% 
  head() #너무 길어서 상위 6개만 출력.

#3
diamonds %>% group_by(cut) %>%   #cut을 범주화 함
  summarise(mean_price = mean(price)) %>% 
  arrange(desc(mean_price)) %>% 
  head(3)

#4
bitamin <- data.frame(sex = c('F', 'F', 'M', 'F', 'M', 'M', 'F', 'F', 'M', 'M'),
                      test = c(65, 70, 77, 82, 97, 86, 55, 99, 67, 85))
bitamin

#5
bitamin_a <- bitamin %>%  mutate(grade = ifelse(bitamin$test < 65 , 'F', 
                                   ifelse(bitamin$test >= 65 & bitamin$test < 75, 'C',
                                          ifelse(bitamin$test >= 75 & bitamin$test < 85, 'B', 'A')) ))
bitamin_a

#6
bitamin_a %>% group_by(sex) %>% 
  summarise(mean(test), sd(test), n())


#7
bitamin_b <- data.frame(sex = c('F', 'M'),
                        code =c(1,2))   #bitamin_b 데이터프레임 생성
bitamin_b    #bitamin_b 내용 확인
bitamin_full <- full_join(bitamin, bitamin_b, by = 'sex') #bitamin과 bitamin_b를 full_join해줌
bitamin_full %>% 
  arrange(code, desc(test))   #code에 대해선 오름차순, test에 대해서는 내림차순으로 정리

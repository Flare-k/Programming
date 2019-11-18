summary(lm(cars$speed~cars$dist))

#n = 10
ex1=sample(1:30, 10)
qqnorm(ex1); qqline(ex1)
                    
#n = 30
ex2 = sample(1:30, 30)
qqnorm(ex2);qqline(ex2)

#항목 수가 30개 미만인 벡터 데이터 생성
shapiro_test_vector = c(74,87,89,98,65,82,70,70,70)
#Shapiro_wilk 검정
shapiro.test(shapiro_test_vector)

#sample vector1
var_test_vector1 <- c(75,67,78,81,53,71,71,55,40,78,76,42,67,98,59,63,84,50,67,80,83)
#sample vector2
var_test_vector2 <- c(58,81,77,80,76,63,54,64,85,54,70,71,71,55,40,78,76,100,51,42,63,61,82,57,48)

#분산이 같은지 확인
var.test(var_test_vector1, var_test_vector2)

#비타민에 다니기 전의 학생 점수
before_study <- c(34,76,76,63,73,75,67,78,81,53,58,81,77,80,43,65,76,63,54,64,85,54,70,71,71,55,
                  40,78,76,100,51,93,64,42,63,61,82,67,98,59,63,84,50,67,80,83,66,86,57,48)
#비타민에 다닌 후 학생 점수
after_study <- c(74,87,89,98,65,82,70,70,70,84,56,76,72,69,73,61,83,82,89,75,48,72,80,66,82,
                 71,49,54,70,65,74,63,65,101,82,75,62,83,90,76,87,90,78,63,59,79,74,65,77,74)

t.test(before_study, after_study, paired = T)

t.test(before_study, after_study, paired = T, alternative = 'less')


#t-검정 수행(단측검정-greater)
t.test(before_study, after_study, paired = T, alternative = 'greater')

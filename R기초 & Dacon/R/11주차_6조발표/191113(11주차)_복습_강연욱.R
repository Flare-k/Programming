#1
#1-1
#H0(귀무가설) = 두 집단의 암기법에는 차이가 없다.
#Ha(대립가설) = 두 집단의 암기법에는 차이가 있다.
par(mfrow = c(1,2))
#1-2
a_group <- c(6,7,3,8,4,4,7,4,2,5,4,3,5,2,6,5,2,3,5,6,3,4)
b_group <- c(7,6,5,8,6,4,9,4,5,6,4,5,3,2,3,4,3,4,5,3,5,5)
qqnorm(a_group) ; qqline(a_group)
qqnorm(b_group) ; qqline(b_group)
# 두 그래프 모두 정규분포를 따른다.
# #H0(귀무가설) = 두 집단의 암기법에는 차이가 없다.
  #Ha(대립가설) = 두 집단의 암기법에는 차이가 있다.
  
#1-3
var.test(a_group, b_group)
#=P-value>0.05 = Ho 기각 X = 두 집단의 분산의 차이가 없다.
#Ho = 두 집단의 암기법에는 차이가 없다.
#Ha(대립가설) = 두 집단의 암기법에는 차이가 있다.

#1-4
t.test(a_group, b_group, alternative = "two.sided", var.equal = TRUE)

#p-value = 0.3043 > 0.05
#Ho = 두 집단의 암기법에는 차이가 없다.
#Ha(대립가설) = 두 집단의 암기법에는 차이가 있다.

#-------------------------------------------
#2
# 주간학생 성적 > 야간학생 성적   
#차이가 10점 정도 나는데 사실인지..
#같은시간에 같은 문제로 시험을.. 주간40명 야간50명
#모집단 2개 종속적..
#2-1
#Ho = 주간학생과 야간학생의 성적은 차이 나지 않는다.
#Ha = 주간학생과 야간학생의 성적 차이는 10점 정도 이다.

ds_data = rnorm(n=40, mean=70, sd=10) ; ds_data
ns_data = rnorm(n=50, mean=83, sd=12) ; ns_data
#정규성검정
shapiro.test(ds_data)#p-value = 0.06293
shapiro.test(ns_data)#p-value = 0.06567
#두 데이터 모두 정규성 충족.

#등분산 검정
var.test(ds_data, ns_data)#p-value = 0.3701 -> 등분산 가정 충족.


#2-2
#검정 통계량(등분산) -> 양측검정이용 // 두 집단의 모평균 차이가 존재하는지..
t.test(ds_data, ns_data, alternative = "two.sided", var.equal = TRUE)
#p-value가 0.05보다 작으므로 대립가설 채택.
#Ha = 주간학생과 야간학생의 성적 차이는 10점 정도 이다.



#2-3
#검정 통계량(이분산) -> 양측검정이용 // 두 집단의 모평균 차이가 존재하는지..
t.test(ds_data, ns_data, alternative = "two.sided", var.equal = FALSE)
#p-value가 0.05보다 작으므로 대립가설 채택.
#Ha = 주간학생과 야간학생의 성적 차이는 10점 정도 이다.

#2-4
mu_ds <- 70
sigma_ds <- 10
n_ds <- 40
ds_bar <- 70.37413

mu_ns <- 83
sigma_ns <- 12
n_ns <- 50
ns_bar <- 81.42820

z_ds<-(ds_bar - mu_ds)/(sigma_ds/sqrt(n_ds))
p_value_ds <- 1-pnorm(z_ds) ; p_value_ds
# 0.4xxx.. 이므로 0.05보다 커서 귀무가설 채택
z_ns<-(ns_bar - mu_ns)/(sigma_ns/sqrt(n_ns))
p_value_ns <- 1-pnorm(z_ns) ; p_value_ns
# 0.8xxx.. 이므로 0.05보다 커서 귀무가설 채택


#3
#1. 환자의 방사선 사진을 보고 암인지 아닌지 판단한다.
#2. 생산된 부품의 데이터를 보고 이 제품이 불량인지 아닌지 판단한다.
#4. 고객의 카드 사용 패턴을 통해 고객의 거주지를 예측한다.
#5. 최근 날씨들의 정보를 이용하여 다음날의 기온을 예측한다.



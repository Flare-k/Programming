library(stringr)
library(rvest)
#COURTS는, 80개의 유통망과 14,000개 이상의 제품을 보유한 싱가포르의 전자제품 및 가구 유통업체이다.
#LG전자에서 일하고 있는 당신은 특정 제품군을 검색했을 때 10위 안에 
#LG의 제품이 삼성 제품에 비해 많이 출현하는지 알아보고 싶다. 
#조건이 아래와 같을 때, 이를 구현하는 코드를 작성하라.

keyword <- c('refrigerator',
             'washing+machine',
             'tv')

urls <- paste0('https://www.courts.com.sg/catalogsearch/result/?q=',keyword)

df <- data.frame(cate=NA, LG=NA, SAMSUNG=NA, judge=NA)
for(i in 1:3){
  page_source <-read_html(urls[i])
  htxt1 <- page_source %>% html_nodes('.product-item-link') %>% html_text
  htxt2 <-htxt1[2:11]
  htxt3 <- str_trim(htxt2)
  
  lg<-sum(str_count(htxt3, 'LG')) #LG의 글자를 찾아줌 ,, 있으면 1 없으면 0
  ss <- sum(str_count(htxt3, "SAMSUNG"))
  judge <- ifelse(lg>ss, "LG Win",
                  ifelse(lg<ss, "SAMSUNG Win", "Draw"))
  df[i,] <- c(keyword[i], lg, ss, judge)
}
View(df)


View(htxt1) #1번이 비게 되는데 1번빼고 슬라이싱 하면 됨

htxt1 <- htxt1[2:17]



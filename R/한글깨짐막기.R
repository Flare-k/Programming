df <- data.frame(엑스=1:10, 와이=1:10)

#이 코드 쓰면 한글 안 깨짐.
theme_set(theme_bw(base_family = "AppleGothic"))

library(ggplot2)

ggplot(df, aes(x=엑스, y=와이))+geom_point()


1+1
plot(airquality$Ozone)
nchar("ABCDEFG")

v_ch <- c("사과", "복숭아","사과","오렌지","사과","오렌지","복숭아")
v_ch
v_fac <- factor(v_ch, levels=c("사과","복숭아"));v_fac

v_fac <- factor(v_ch, levels=c("복숭아","사과","오렌지"));v_fac

ex_label <- c("하하","중하","중","중상","상상")
ordered_factor <- factor(ex_label, ordered=T);ordered_factor
factor(ex_label, levels = c("하하","중하","중","중상","상상"), ordered=T)
ordered_factor

t_vec = c(1,2,3,4,5,6)
t_vec[1:3]
t_vec[-1]

i=importdata('error.txt')
h=i(:,1);
method1=i(:,2);
method2=i(:,3);
method3=i(:,4);
figure

plot(h,method1)
hold on
plot(h,method2)
hold on
plot(h,method3)
title('Plot to compare error w.r.t method used for variable step sizes')
xlabel('step size (h)')
ylabel('error')
legend('method1','method2','method3', 'Location','northwest')
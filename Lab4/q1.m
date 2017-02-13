%TO SAVE THE PLOTS

%I
k = -1:1e-2:1;
fk = exp(k);
plot(k,fk,'green')
hold on;

%II
x = [-1,-0.5,0,0.5,1];
A = [1,x(1),x(1)^2,x(1)^3,x(1)^4; 
    1,x(2),x(2)^2,x(2)^3,x(2)^4; 
    1,x(3),x(3)^2,x(3)^3,x(3)^4; 
    1,x(4),x(4)^2,x(4)^3,x(4)^4; 
    1,x(5),x(5)^2,x(5)^3,x(5)^4];

B = [exp(x(1)); exp(x(2)); exp(x(3)); exp(x(4)); exp(x(5))];

C = inv(A)*B;

Px = C(1) + C(2).*k + C(3).*(k.^2) + C(4).*(k.^3) + C(5).*(k.^4)
plot(k,Px,'^')
hold on;

%IV
Tx = 1 + k + (k.^2)/2 + (k.^3)/6 + (k.^4)/24 
plot(k, Tx, '+r')

%III
ErrorLIP = fk - Px;
figure
plot(k,ErrorLIP)
title('Error between exp(x) and P(x)');
hold on;

% Error in Taylor
ErrorTP = fk - Tx;
plot(k, ErrorTP, '+g')

% V
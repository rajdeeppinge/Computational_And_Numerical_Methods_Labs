clear


A= [1 0 0 0 0 0 0 0;
    0 0 0 0 1 0 0 0;
    0 1 1 1 0 0 0 0;
    0 0 0 0 0 1 1 1;
    0 1 2 3 0 -1 0 0;
    0 0 1 3 0 0 -1 0;
    0 0 1 0 0 0 0 0;
    0 0 0 0 0 0 1 3];

b= [1;0;-1;1;0;0;0;0];

answer = inv(A)*b;

diffx0 = 1.5;
diffx1 = 0.5;

s0x = answer(4)*(diffx0^3)+ (answer(3))*(diffx0^2)+ answer(2)*(diffx0)+ (answer(1))
s1x = answer(8)*(diffx1^3)+ (answer(7))*(diffx1^2)+ answer(6)*(diffx1)+ (answer(5))

s0x =zeros(41,1);
s1x = zeros(41,1);

for i=-2:0.1:2
diffx0 = i- (-1);
diffx1 = i-0;

a = int16((i+2)*10 +1);
s0x(a) = answer(4)*(diffx0^3)+ (answer(3))*(diffx0^2)+ answer(2)*(diffx0)+ (answer(1));
s1x(a) = answer(8)*(diffx1^3)+ (answer(7))*(diffx1^2)+ answer(6)*(diffx1)+ (answer(5));

end

x = -2:0.1:2;

plot(x,s0x)
hold on
plot(x,s1x)
hold on
plot(x,x.^4)

% clamped boundary
A1= [1 0 0 0 0 0 0 0;
    0 0 0 0 1 0 0 0;
    0 1 1 1 0 0 0 0;
    0 0 0 0 0 1 1 1;
    0 1 2 3 0 -1 0 0;
    0 0 1 3 0 0 -1 0;
    0 1 0 0 0 0 0 0;
    0 0 0 0 0 1 2 3];

b1= [1;0;-1;1;0;0;-4;4];

answer1 = inv(A1)*b1;

diffx0 = 1.5;
diffx1 = 0.5;

s0x_m2 = answer1(4)*(diffx0^3)+ (answer1(3))*(diffx0^2)+ answer1(2)*(diffx0)+ (answer1(1))
s1x_m2 = answer1(8)*(diffx1^3)+ (answer1(7))*(diffx1^2)+ answer1(6)*(diffx1)+ (answer1(5))

s0x_m2 =zeros(41,1);
s1x_m2 = zeros(41,1);

for i=-2:0.1:2
diffx0 = i- (-1);
diffx1 = i-0;

a = int16((i+2)*10 +1);
s0x_m2(a) = answer(4)*(diffx0^3)+ (answer(3))*(diffx0^2)+ answer(2)*(diffx0)+ (answer(1));
s1x_m2(a) = answer(8)*(diffx1^3)+ (answer(7))*(diffx1^2)+ answer(6)*(diffx1)+ (answer(5));

end

x = -2:0.1:2;

figure
plot(x,s0x_m2)
hold on
plot(x,s1x_m2)
hold on
plot(x,x.^4)

%quadratic
Aq= [1 0 0 0 0 0;
    0 0 0 1 0 0;
    0 1 1 0 0 0;
    0 0 0 0 1 1;
    0 1 2 0 -1 0;
    0 0 1 0 0 0];

bq= [1;0;-1;1;0;0];
answerq = inv(Aq)*bq

diffx0 = 1.5;
diffx1 = 0.5;

s0xq = (answerq(3))*(diffx0^2)+ answerq(2)*(diffx0) + (answerq(1))
s1xq = (answerq(6))*(diffx1^2)+ answerq(5)*(diffx1)+ (answerq(4))


s0xq =zeros(41,1);
s1xq = zeros(41,1);


for i=-2:0.1:2
diffx0 = i- (-1);
diffx1 = i-0;

a = int16((i+2)*10 +1);
s0xq(a) = (answerq(3))*(diffx0^2)+ answerq(2)*(diffx0) + (answerq(1));
s1xq(a) = (answerq(6))*(diffx1^2)+ answerq(5)*(diffx1)+ (answerq(4));
end

x = -2:0.1:2;

figure
plot(x,s0xq)
hold on
plot(x,s1xq)
hold on
plot(x,x.^4)


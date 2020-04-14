function y=nest(d,c,x,b)
if nargin<4
    b=zeros(d,1);
end
y=c(d+1);
for i=d:-1:1
    y=y.*(x-b(i))+c(i);
end

function c=newtdd(x,y,n)

for j=1:n
    v(j,1)=y(j);  %y column
end

for i=2:n  %column
    for j=1:n+1-i   %row
        v(j,i)=(v(j+1,i-1)-v(j,i-1))/(x(j+i-1)-x(j)); %count
    end
end

for i=1:n
    c(i)=v(1,i); %output the coefficient
end

%create sin value
%input:x
%output:vagued sin(x)

function y=sin1(x)
%reserve the coefficient
b=pi*(0:3)/6;
yb=sin(b);
c=newtdd(b,yb,4);
s=1;
x1=mod(x,2*pi);
if x1>pi
    x1=2*pi-x1;
    s=-1;
end
if x1>pi/2
    x1=pi-x1;
end
y=s*nest(3,c,x1,b);
end

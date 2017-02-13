% program to find solution of given system of equations by Gauss-Siedel method

% starting point
X0 = [0;0;0;0];

% we can also define A first and use L=tril(A, -1) and U=triu(A, 1) and D=diag(A)

% lower triangular matrix with diagonal elements 0
L = [0 0 0 0;
     1 0 0 0;
     0 1 0 0;
     1 0 1 0];

% upper triangular matrix with diagonal elements 0
U = [0 1 0 1;
     0 0 1 0;
     0 0 0 1;
     0 0 0 0];

% Diagonal Matrix
D = [4 0 0 0;
     0 4 0 0;
     0 0 4 0;
     0 0 0 4];

A = L + D + U;

b = [1;-2;2;-2];

% Iteration matrix
H = -inv(L+D) * U;

% constant matrix
C = inv(L+D) * b;

% Root at each iteration
X = X0;

for i = 1:4
   X = H * X + C
end

% checking if final answer matches matrix b
A*X
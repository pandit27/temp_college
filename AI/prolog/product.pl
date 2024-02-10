% Documentation : product of two numbers
% Predicate: multi/3
% Paramenters : N1, N2, R
% - N1 : first number
% - N2 : second number
% - R : product of N1 & N2 

% main program :
multi(N1, N2, R) :-
    R is N1 * N2.

% dry run :
% multi(4, 5, R)
% output : R = 20
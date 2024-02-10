% Documentation : maximum of two numbers
% Predicate: max_of_two/3
% Paramenters : X, Y, M
% - X : first number
% - Y : second number
% - M : max of X & Y 

% main program :
max_of_two(X, Y, M) :-
    X >= Y,
    M is X.

max_of_two(X, Y, M) :-
    Y > X,
    M is Y.

% dry run :
% max_of_two(4, 5, M)
% output : M = 5
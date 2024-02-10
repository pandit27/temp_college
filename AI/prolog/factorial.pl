% Documentation : Fibonacci Series
% Predicate: factorial/2
% Paramenters : N, F
% - N : number
% - F : factorial of nth term

% main program :
factorial(0, 1).
factorial(1, 1).
factorial(N, F) :-
    N > 1,
    X is N - 1,
    factorial(X, F1),
    F is N * F1.


% dry run :
% factorial(4, F)
% output : T = 24
% Documentation : Fibonacci Series
% Predicate: generate_fib/3
% Paramenters : N, T
% - N : number
% - T : nth term of series

% main program :
generate_fib(0, 0).
generate_fib(1, 1).
generate_fib(N, T) :-
    N > 1,
    X is N-1,
    Y is N-2,
    generate_fib(X, T1),
    generate_fib(Y, T2),
    T is T1 + T2.

% dry run :
% generate_fib(5, T)
% output : T = 5
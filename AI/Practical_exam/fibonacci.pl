%- main predicate to start the program
main :-
    %- take N
    write('Enter N: '),
    read(N),
    
    %- calculate the Nth term of the fibonacci series
    fib(N, T),
    
    %- display the result
    write('The Nth term is: '),
    write(T),
    nl.

% base case: if N = 0 or N = 1
fib(0, 0). 
fib(1, 1).

%- recursive case: if N > 1
fib(N, T) :-
    N > 1,
    N1 is N - 1,
    N2 is N - 2,
    fib(N1, T1),
    fib(N2, T2),
    T is T1 + T2.
    

%- main predicate to start the program
main :-
    %- take N
    write('Enter a number: '),
    read(N),
    
    %- calculate factorial
    fact(N, F),
    
    %- display the result
    write('The factorial of N is :'),
    write(F),
    nl.

%- base case: factorial of 0 is 1
fact(0, 1).

%- recursive case: if N > 0
fact(N, F) :-
    N > 0,
    N1 is N - 1,
    fact(N1, F1),
    F is N * F1.
    

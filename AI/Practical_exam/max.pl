%- the main predicate to start the program
main :-
    %- take first number
    write('Enter the first number: '),
    read(X),
    
    %- take second number
    write('Enter the second number: '),
    read(Y),
    
    %- find the maximum of X & Y
    max(X, Y, M),
    
    %- display the result
    write('The maximum of X & Y is: '),
    write(M),
    nl.

%- predicate to find max of X & Y
max(X, Y, M) :-
    %- if X >= Y, then M = X
    X >= Y,
    M = X.

max(X, Y, M) :-
    %- if X < y, then M = Y
    X < Y, 
    M = Y.

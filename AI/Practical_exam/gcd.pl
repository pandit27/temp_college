%- main predicate to start the program
main :-
    %- take X
    write('Enter X: '),
    read(X),
    
    %- take Y
    write('Enter Y: '),
    read(Y),
    
    %- calculate the gcd of X & Y
    gcd(X, Y, G),
    
    %- display the result
    write('The gcd of X & Y is: '),
    write(G),
    nl.

% base case
gcd(X, 0, X).      % GCD of any number and 0 is the number itself
gcd(0, Y, Y).      % GCD of 0 and any number is the number itself

%- recursive case
gcd(X, Y, G) :-
    Y > 0,
    Z is X mod Y,
    gcd(Y, Z, G).

%- the main predicate to start the program
main :-
    %- take X from the user
    write('Enter the first number: '),
    read(X),
    
    %- take Y from the user
    write('Enter the second number: '),
    read(Y),
    
    %- calulate the sum of X & Y
    sum(X, Y, Sum),
    
    %- display the sum
    write('The sum is: '),
    write(Sum),
    nl. %- new line

%- predicate to calculate the sum
sum(X, Y, Sum) :-
    Sum is X + Y.

% Documentation : reverse of a list l
% Predicate: reverse/2
% Paramenters : L R
% - L : original list
% - R : revserse of L

% main program :
reverse([Head|Tail], R) :-
    reverse(Tail, ReversedTail),
    append(ReversedTail, [Head], R).
    
% dry run :
% reverse([1, 2, 3, 4], R)
% output : R = [4, 3, 2, 1].
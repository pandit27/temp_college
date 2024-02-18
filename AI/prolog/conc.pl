% Documentation : concatenation of two lists L1 & L2
% Predicate: conc/3
% Paramenters : L1, L2, L3
% - L1 : first list
% - L2 : second list
% - L3 : concatenation of L1 & L2

% main program :
conc([], L, L).

conc([X|L1], L2, [X|L3]) :-
    conc(L1, L2, L3).
    
% dry run :
% conc([1, 2, 3], [4, 5, 6], L3)
% output : L3 = [1, 2, 3, 4, 5, 6]
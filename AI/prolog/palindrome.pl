% Documentation : check if the list L is a palindrome
% Predicate: palindrome/1
% Paramenters : L
% - L : list

% main program :
palindrome([]).

palindrome([_]).
 
palindrome([First|Last]) :-
    append(Middle, [First], Last),
    palindrome(Middle).
    
% dry run :
% palindrome([1, 2, 2, 1])
% output : true
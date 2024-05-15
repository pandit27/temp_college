memb(X, [X|_]).        % X is a member of the list if it's the head of the list.
memb(X, [_|T]) :-      % X is a member of the list if it's a member of the tail of the list.
    memb(X, T).

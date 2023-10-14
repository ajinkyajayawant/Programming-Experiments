rev l = lst_rev where
    first_el = head l
    rest_list = tail l
    lst_rev = if rest_list == []
    then [first_el]
    else rev rest_list ++ [first_el]

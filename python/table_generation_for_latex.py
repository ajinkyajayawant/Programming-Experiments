import pandas as pd
import numpy as np

def argmax_max_two_tables(table1_path, table2_path, col_inds, save_path):
    """ This function computes the maximum column from table one and applies that to table 2
    col_inds is a list."""
    tab1 = pd.read_table(table1_path, delim_whitespace=True, usecols=col_inds, header=None)
    tab2 = pd.read_table(table2_path, delim_whitespace=True, header=None)

    # Create a table using tab2
    max_args = tab1.idxmax(axis=1)

    red_tab2 = tab2.iloc[:, col_inds]
    tab2_modified = tab2.assign(New_Column=-1)
    
    for i, row in tab2_modified.iterrows():
        tab2_modified.loc[[i], ['New_Column']] = tab2_modified.loc[i, max_args[i]]

    tab2_modified.to_csv(save_path, header=False)
    
    return

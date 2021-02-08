python3.6 -m viztracer -o /tmp/report.html --log_var a1 arr1 -- viztracer_exp.py
python3.6 -m viztracer -o /tmp/report.json --log_var a1 arr1 -- viztracer_exp.py


python3.6 -m viztracer -o /tmp/report.json --log_var a3 arr2 -- viztracer_exp.py
# filering by file name reduces the amount of data
python3.6 -m viztracer -o /tmp/report2.json --include_files viztracer_exp_2.py --log_var a3 arr2 -- viztracer_exp.py
# Trying html version visualization
python3.6 -m viztracer -o /tmp/report2.html --include_files viztracer_exp_2.py --log_var a3 arr2 -- viztracer_exp.py

# See whether we can filter by the function name
# This does not filter out the function
python3.6 -m viztracer -o /tmp/report2.json --log_func_exec doubler --log_var a3 arr2 -- viztracer_exp.py

# This logs other out of file functions as well
# Using a double line break between functions prevents this issue
# In my case creating a log_sparse marking in a separate branch works so I don't have to modify the source code
python3.6 -m viztracer -o /tmp/report3.json --log_sparse --log_var a5 arr3 -- viztracer_exp.py
# Check if only one variable gets saved
# That doesn't happen
python3.6 -m viztracer -o /tmp/report6.json --log_sparse --log_var arr3 -- viztracer_exp.py

# Trying to see if just using a specific variable name works to reduce data
# No this does not do any filtering
python3.6 -m viztracer -o /tmp/report8.json --log_var a5 -- viztracer_exp.py

# The best bet we have to filter effectively is to either have the function in a separate file or to use log_sparse decorators
# We can have a very few variables in that function if we want to observe the variable we are interested in easily.

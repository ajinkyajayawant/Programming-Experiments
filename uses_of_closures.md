In this article I will explain and show how can closures be used in different situations.

# Make constants harder to change
In python there's no const keyword. So it's difficult to design code that prevents another programmer from accidentally changing the value of a variable that is supposed to be constant. Defining variables inside functions makes them much harder to be changed. Instead of
```
x = 10
```
we write
```
defun var_x():
     return 10
```
. So every time we want to use the variable `x` we can simply use `var_x()` instead of `x`.

# Objects
Objects which maintain state but you do not want to expose state can be defined using closures. The nonlocal keyword is needed here because integer variables are non mutable in python.
```
def get_plus_one():

    count = 0
    def plus_one():

        nonlocal count
        count = count + 1
        return count

    return plus_one
```

# Caching
Caching is required for algorithms that need memoization. Dynamic programming algorithms typically need memoization. A memoized version of a function can be manually generated(if you dont want to use teh library function) using closures.
```
def memoize(func):
    cache = dict()

    def memoized_func(*args):
        if args in cache:
            result = cache[args]
        else:
            result = func(*args)
            cache[args] = result
        return result

    return memoized_func
```

# Partial application/currying
Sometimes you want to initialize the function with a few arguments first, and the remaining arguments are top be provided at runtime.
```
def my_adder(a, b):
    return a + b

def get_partial_adder(c):
    def partial_adder(d):
        return my_adder(c, d)
    return partial_adder
```
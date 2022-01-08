# Find out how to make dictionary with a counter
# How to do list comprehensions over a string
# I think I can do list comprehensions over the substrings
# In order to avoid storing all the substrings I can write a generator expresssion
# Find a library function for the python substrings


def get_indices_where_found(orignal_string, list_words):
    # This is the main function and this returns a list of indices
    # where the appropriate substrings were found
    # Need a boolean function for whether the substring was found at that
    # index or not

    # Find the substring length that we need
    substring_length = find_substring_length(list_words)

    correct_indices = [do_words_exist_in_substring(substring) for substring in substring_generator]

    integer_indices = find(correct_indices)

    return integer_indices

def find_substring_length(list_words):
    if list_words:
        word_length = len(list_words[0])
    else:
        words_length = 0

    list_length = len(list_words)

    return words_length*list_length


def substring_generator(orignal_string):
    for i, char in enumerate(orignal_string):
        yield get_substring(orignal_string, i, substring_length)


def get_substring(orignal_string, index, substring_length):
    # This gives a substring of the original string of the ppropriate size
    # if it exist or returns something like null
    # TODO: Replace this with a library function

    return original_string[i:i+substring_length]


def do_words_exist_in_substring(substring, word_length, dict_words):
    # This takes input as the substring of the original string of the
    # appropriate size and sees if that string is a concatenation of the
    # word list

    first_word = get_first_word(substring, word_length)

    if search_word_in_list(substring, word_length, dict_words):
        # Decrease the dictionary
        # Decrease the substring size
        exists = do_words_exist_in_substring(substring, word_length, dict_words)
    else:
        exists = false

    return exists


def get_first_word(substring, word_length):
    first_word = substring[:word_length]

    return first_word

def search_word_in_list(word, given_list):
    if word in given_list:
        exists = True
    else:
        exists = False

    return exists

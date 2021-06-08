
def filter_lines_with_pattern(input_path, output_path, pattern):
    with open(input_path, 'r') as file_in:
        for myline in file_in:
            if myline.find(pattern) != -1:
                with open(output_path, "a") as file_out:
                    file_out.writelines(myline)
    return


def remove_lines_with_pattern(input_path, output_path, pattern):
    with open(input_path, 'r') as file_in:
        for myline in file_in:
            if myline.find(pattern) == -1:
                with open(output_path, "a") as file_out:
                    file_out.writelines(myline)
    return


def filter_blocks_with_regex(input_path, output_path, pattern):
    with open(input_path, 'r') as file_in:
        lines = file_in.readlines()

    re.search(r"[a-zA-Z]\d{3}[a-zA-Z]", lines)
    with open(output_path, "a") as file_out:
        file_out.writelines(myline)

    return


def remove_blocks_with_regex(input_path, output_path, pattern):
    with open(input_path, 'r') as file_in:
        lines = file_in.readlines()

    re.sub('<.*?>', '', string)
    with open(output_path, "a") as file_out:
        file_out.writelines(myline)

    return

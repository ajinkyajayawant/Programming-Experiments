from pathlib import Path

from text_filtering import (filter_lines_with_pattern,
                            remove_lines_with_pattern,
                            filter_blocks_with_regex,
                            remove_blocks_with_regex)

def test_filter_lines_with_pattern():
    file1 = "/tmp/a101.txt"
    file2 = "/tmp/a201.txt"

    content = "donut"

    # Write a text file with one word
    Path(file1).write_text(content)

    # Apply filter for that word
    filter_lines_with_pattern(file1, file2, content)

    # Read the new file
    written_content = Path(file2).read_text()

    # Compare the result after the filter with the original word
    err_msg = "The written content and the original content should be the same."
    assert(written_content == content), error_msg


def test_remove_lines_with_pattern():
    return


def test_filter_blocks_with_regex():
    return


def test_remove_blocks_with_regex():
    return

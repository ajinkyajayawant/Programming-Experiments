text_filtering.remove_lines_with_pattern("/tmp/clippings/clip.txt", "/tmp/clippings/clip3.txt", "dawkins")

text_filtering.filter_blocks_with_regex("/tmp/clippings/clip.txt", "/tmp/clippings/clip3.txt", "dawkins")

# To filter latex edits with blue textcolor
text_filtering.filter_blocks_with_regex("/tmp/atry.txt", "/tmp/ctry.txt", r"\\textcolor\{blue\}\{.*\}")

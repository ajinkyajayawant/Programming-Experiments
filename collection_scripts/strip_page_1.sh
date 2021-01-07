#!/bin/bash

# Usage: ./strip_page_1.sh ./file_name.pdf

inputName=$1
outputDir="/tmp/pdftkTemp/"
outputFile="/tmp/pdftkTemp/a1.pdf"

mkdir $outputDir
pdftk $inputName cat 2-end output $outputFile
rm $inputName
mv $outputFile $inputName
rm -r $outputDir

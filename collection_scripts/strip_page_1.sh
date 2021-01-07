#!/bin/bash

inputName=$1
outputDir="/tmp/pdftkTemp/"
outputFile="/tmp/pdftkTemp/a1.pdf"

mkdir $outputDir
pdftk $inputName cat 2-end output $outputFile
rm $inputName
mv $outputFile $inputName
rm -r $outputDir

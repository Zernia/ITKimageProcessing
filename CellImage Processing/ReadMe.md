Problem 1
For all the program, the argv[1] is the inputFile: The yeast cell image;
The argv[2] is the outputFile: The result file.
1 segment cells.

a.	Use the morphology watershed from maker image to segment the cells
Morphology watershed can do one input and one marker input which mark the input minima and give them a lable, So when there is a cell, the intensity of the cell will circular the nuclei of the cell.
1.	build a marker use the original image, 

a.	keep the edge(curvatureFilow), 
b.	try to identify the local minima,(HconcaveImagefilter)(actually I’d like to make the local minima stronger, but I didn’t get a really good filter), 
c.	Invert the intensity(try to strong the local minima, it’s not the way. But a little diffrence)
   
2 build a input Image.
 try to separate the cell the background and the nuclei
use otsu threshold, threshold image. rescale, etc.

3 use morphology watershed to combine the image
4 color the image label

The output is
![](iMAGE/output1.png)
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output1.png)
[https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output1.png|alt=octocat]]
<img src="https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output1.png">
<img src="https://github.com/favicon.ico" height="240" width="480">
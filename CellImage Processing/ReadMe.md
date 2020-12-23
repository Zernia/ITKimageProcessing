Problem 1<br/>
For all the program, the argv[1] is the inputFile: The yeast cell image;
The argv[2] is the outputFile: The result file.
1 segment cells.
The inputFile is<br/>
<img src="https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output8.png" width="350" height="400" />

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

The output is<br/>
<img src="https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output1.png" width="350" height="400" /><br/>

It’s not original watershed. But can see the edge between the connected cells. Change the threshold in the connected threshold image filter will give different boundary of the cells.

2 A failed water shed, but can see the separate.
Similar algorithm, just the way to strong the local minima and smoothing the image is different. This one use HMinimaImageFIlter and Vector gradientAnisotropic diffusion Image filter. 
The output is <br/>
<img src="https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output2.png" width="350" height="400" /><br/>

3 otsu and threshold to separate the image 
But this one doesn't give a good separate for the connected cell. 
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output3.png)

The is all the threshold image, but the output is not very obvious for the connected Cells. .

2.	Calculate the average area
For calculating the average area. use the pixel number *pixel represents the physical space / the cell number.
The problem is how to get the total number of pixels and how to get the cells number.

a.	Use a binary image .
(1). get an image just with the cell nucleus. The yeast cell has just one nucleus because of the character of the eukaryotic cell. Then use threshold to create an image just with nucleus. This can use binarythresholdImagefilter, the upper threshold set to 255. The lower set to 110.<br/>
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output4.png)<br/>
(2).Calculate the number of the nucleus. This one can use a   binaryImagetoLabelMapFilter to give each nucleus a label. Then get the object number. The number is 20
(3). Get the cells area. It depends on how accurate the result by get the cell image.
This binary image the threshold is 40 for lower, 255 for upper.<br/>
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output5.png)<br/>
4).Calculate the pixel number. Visit all the pixels, there are 2 ways;
     The First way is using a double for-loop use Image size, from left to right->x, top to down->y.
     Set a ImageType the index is x, y . If the pixel value is 255. Then counter ++; return the counter;
    Second way is use ImageRegionConstIteration to visit the pixels;
    This can use for loop or while loop;
    I did this way and use a while loop;
    set the total region of the image for the iteration, and also set a counter=0.
    Iteration begins;
    While the iteration is not in the end
          If the pixel value is object; 
          Counter ++;
    Iteration ++;

For this image the black pixel is 376700;

If for this image each pixel represents 0.01um^2 space;
Then the average area of the cells is 188.35.
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output6.png)<br/>
2 Use Color Image
The idea is similar. Still get the number of the cells and the area of the total cells.
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output7.png)<br/>
![](https://github.com/Zernia/ITKimageProcessing/blob/main/CellImage%20Processing/iMAGE/output9.png)<br/>
Get the color map of the nucleus, calculate the specific pixel numbers, do the division. Label the number of the object, sum up the pixel volume





# stbi_image_bmp-jpg-png
Problem: undefined reference to 'stbi_image_bmp' in CodeBlocks.
Using: CodeBlocks, GLUT project, headers stb_image.h and stb_image_write.h.
Target: load file (image), changing colors to gray, save file (image JPG or BMP or PNG format).

The main problem is in save image after changing colors to gray and using full path to load image (C:\Users\...)
Trying use function stbi_write_bmp() / stbi_write_jpg() / stbi_write_png() and taking problem from compile.
Tried using solution for my project in video YouTube: https://www.youtube.com/watch?v=1OyQoPCp46o

Perhabs I haven't not enough configuration my CodeBlocks for load and save images in project.
I had to put all path (C:\Users\...\project-stbi-images\image.bmp) in code, but many coders use just "image.bmp" for load and save file (image).

I dont know how to solve this problem.

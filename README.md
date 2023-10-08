# FDF

## Description
This program is a simple graphic tool to visualize a basic landscape in 3d. This landscape can be codified in a file that specifies the coords of each point in space. The program will take the file and convert it to an isometric view of the landscape it represents.

`minilibx` graphics library has been used in this project. It contains very basic functionality such as window creation, drawing and event management. Any other functionality has to be coded by yourself. That is a feature (not a bug), because it forces you to learn about graphics algorithms; like Bresenham's line algorithm if you intend to draw lines (which you are most likely to, btw).

![alt-text](https://github.com/javihernant/fdf/blob/master/scr.gif)

## Features
- Translation and rotation of the rendered object in space
- Bend object
- Modify height of all points
- Zoom to an specific point
- Fit and center, so the object is completely visible
- Colors
- Side pane with all key and mouse controls

## Usage
Type `make` in a terminal to compile the program. Then, just pass one of the maps at the `maps/` directory as an argument:
```./fdf: <map.fdf>```

## Future work
- [Side panel] Add Debuging info
- One point-perspective
- Conic
- antialising

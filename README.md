
# Image Colorization and Data Structure Manipulation Project (PROJET SDA2)

## Overview
This is a Datastructure project, developed during my second year of computer sciences studies ,it is a sophisticated software tool designed to manipulate and color images, particularly those in the PBM (Portable Bitmap) and PPM (Portable Pixmap) formats. The project leverages advanced data structures, including trees and linked lists, to efficiently handle pixel data and implement algorithms for image processing.

- **Image Reading and Writing**: Supports reading PBM ASCII images and writing PPM images, storing pixel data in a two-dimensional array.
- **Image Generation**: Capable of generating black and white images with specified dimensions.
- **Colorization**: Implements a colorization algorithm that assigns random RGB colors to white pixels while maintaining the integrity of black pixels.
- **Data Structures**: Utilizes custom data structures for pixels, lists, and trees to manage pixel data and relationships effectively.

### Data Structure Implementations
- **Pixel Data Structure**: Handles pixel color, rank, and relationships within the image.
- **Tree Structure**: Supports operations like `makeset`, `findset`, and `union` for efficient data management.
- **List Structure**: Includes functionality for creating sets, finding set representatives, and union operations.

## Installation
To compile and run the project, navigate to either the `liste` or `arbre` directory and execute the following commands:

```bash
## Features
make
./liste <PBM image path> <output PPM image name>
# or
./arbre <PBM image path> <output PPM image name>
```

## Usage
The project provides two main executable files for different implementations:
- **Liste**: For list-based image processing.
- **Arbre**: For tree-based image processing.

You can color a PBM image by specifying the input PBM file and the output PPM file name as command-line arguments.

## Challenges Encountered
- **File Inclusion Issues**: Initially faced challenges with file inclusions which were later resolved.
- **Performance Optimization**: Significant efforts were made to optimize the coloring algorithm, especially for the list implementation which now processes images significantly faster.

## Contributions
Feel free to fork the project, submit pull requests, or open issues for any suggestions or bug reports.

## License
[MIT License](LICENSE)
```

This README provides a clear introduction to your project, its features, how to use it, and other relevant details. You can add a `LICENSE` file in your GitHub repository if you haven't already, to make the licensing clear.

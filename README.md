# cpp-project

***
# part1:
  # Vector Implementation Performance Comparison

## Overview

This project compares the performance of two custom vector implementations in C++. The first implementation uses a single pointer for internal storage, while the second uses a double pointer. The comparison involves inserting and removing elements using both vector implementations and measuring the time taken for these operations.

## Components

- **SinglePointerVector**: A vector implementation using a single pointer for internal storage.
- **DoublePointerVector**: A vector implementation using a double pointer for internal storage.
- **main.cpp**: Main file that includes both vector classes and performs the performance comparison.

## One of my test example:
![res](Part1/result1.png)

The vector that made by double pointer is working faster than the other one.

# part2:
# Geometric and Physical Calculation Headers

This repository contains three C++ header files designed for geometric and physical calculations: `poly.h`, `shape.h`, and `device.h`. These headers provide functionalities to create geometric shapes, calculate their properties, and compute physical characteristics based on those shapes.

## Headers Overview

### `poly.h`

The `poly.h` header file contains definitions and functions for creating and managing 2D polygonal shapes.
  
### `shape.h`

The `shape.h` header file extends 2D shapes into 3D and provides functions to create and manage 3D shapes, compute their volume, and calculate their surface area.

#### Key Functions

- **`ThreeDShape create3DShape(float height, const Polygon& base)`**
  - Constructs a 3D shape using a base polygon and a specified height.
  
- **`float getVolume()`**
  - Calculates the volume of the 3D shape.
  
- **`float getSurfaceArea()`**
  - Calculates the surface area of the 3D shape.

### `device.h`

The `device.h` header file computes physical properties related to the shape and the device using vectors.

#### Key Functions

- **`float calculateMass(const ShapeProperties& shapeVector, const DeviceProperties& deviceVector)`**
  - Computes the mass of the shape based on shape and device properties.

- **`float calculateVolume(const ShapeProperties& shapeVector)`**
  - Computes the volume using the shape's properties.

- **`float calculateSurfaceArea(const ShapeProperties& shapeVector)`**
  - Computes the surface area using the shape's properties.

## Example Usage

### Create a 2D Shape

```cpp
#include "poly.h"

int main() {
    // Create a polygon with 6 sides and a distance of 10 units from the center
    Polygon po

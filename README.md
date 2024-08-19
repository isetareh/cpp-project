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
Average insertion time for Vector in milliseconds: 1.4

Average remove time for Vector in milliseconds: 1

Average insertion time for VectorPtr in milliseconds: 0.1

Average remove time for VectorPtr in milliseconds: 0

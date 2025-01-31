# Campus Navigation System

## Overview

The **Campus Navigation System** is a console-based pathfinding application that helps users find the shortest route between landmarks within a campus grid using the *A*\* algorithm\*\*.

## Features

- **40x40 Campus Grid**: A virtual map representing a campus layout.
- **Landmarks & Obstacles**: Multiple landmarks denoted by their initials and obstacles (`|`) for realistic navigation.
- *A*\* Pathfinding Algorithm\*\*: Efficiently calculates the shortest route between two landmarks.
- **User-Friendly Display**: The grid visually represents paths (`-`), obstacles (`|`), landmarks (`L, C, H, etc.`), and the optimal path (`*`).
- **Interactive Input**: Users can select a starting and destination landmark from the predefined options.

## Legend (Landmarks & Symbols)

| Symbol | Location          |                    |
| ------ | ----------------- | ------------------ |
| L      | Library           |                    |
| C      | Cafeteria         |                    |
| H      | Hostel            |                    |
| A      | Auditorium        |                    |
| G      | Gymnasium         |                    |
| M      | Main Gate         |                    |
| S      | Science Block     |                    |
| T      | Technology Center |                    |
| D      | Dormitory         |                    |
| P      | Parking Lot       |                    |
| F      | Football Field    |                    |
| R      | Research Center   |                    |
| B      | Basketball Court  |                    |
| N      | Nursing Block     |                    |
| O      | Office Block      |                    |
| Pipe(|)|                   | Obstacle (Blocked) |
| -      | Open Path         |                    |
| \*     | Optimal Path      |                    |

## How to Run

### Compilation

```sh
 g++ campus_navigator.cpp -o campus_navigator
```

### Execution

```sh
 ./campus_navigator
```

### User Input

1. The program will display the **campus grid** with landmarks and obstacles.
2. Enter the **initial landmark letter** from the provided legend.
3. Enter the **destination landmark letter** from the legend.
4. The program will compute and display the **optimal path**.


## Technologies Used

- **C++**
- *A*\* Pathfinding Algorithm\*\*

## License

This project is open-source under the MIT License.


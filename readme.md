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
|        |                   | Obstacle (Blocked) |
| -      | Open Path         |                    |
| \*     | Optimal Path      |                    |

## How to Run

### Compilation

Ensure you have a C++ compiler installed. Use the following command to compile the program:

```sh
 g++ campus_pathfinder.cpp -o campus_pathfinder
```

### Execution

Run the compiled program:

```sh
 ./campus_pathfinder
```

### User Input

1. The program will display the **campus grid** with landmarks and obstacles.
2. Enter the **initial landmark letter** from the provided legend.
3. Enter the **destination landmark letter** from the legend.
4. The program will compute and display the **optimal path**.

## Example Output

```
Campus Grid:
- - - - - L - - - - - - - - - - - - - - | - - - - - - - - - - - - - - - - - -
- - - - - - - - - - - - - - - - - - - - | - - - - - - - - - C - - - - - - - -
- - - - - - - - - - - - - - M - - - - - | - - - - - - - - - - - - - - - - - -
...
Enter the initial landmark letter: L
Enter the destination landmark letter: G

Optimal Path:
L - - - - - * * * * * * * * * * * * * * * * * * * * G
```

## Technologies Used

- **C++**
- *A*\* Pathfinding Algorithm\*\*

## Future Enhancements

- Add a graphical interface for a better user experience.
- Expand the map dynamically based on user input.
- Implement real-time updates with movement simulation.

## Author

[Your Name]

## License

This project is open-source under the MIT License.


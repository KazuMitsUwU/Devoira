*This project has been created as part of the 42 curriculum by manoaran.*

---

# Libft

## Description

Libft project is the very first project in the common core. This projects aims to make the student know how to mimic every useful function in the original libc by implementing them themselves. It helps the student master pointers and memory.
This project also requires the student to make additional functions that need libc functions calling, giving them the opportunity to master these functions by calling their own versions of these funtions. Additionally, this project introduce the concept of lists and list handling.

## Instructions

### Compilation

To compile the library and generate the static archive `libft.a`, run:
=> make

- Cleaning Object Files -
To remove all compiled object files (.o):
=> make clean

- Full Clean -
To remove all object files and the compiled library:
=> make fclean

- Recompile Everything -
To fully clean and rebuild the project:
=> make re

- Using the Library in Another Project -
Include the library header in your source files:
=> #include "libft.h"


##  Resources

### Documentation

The following official and educational resources were used to understand the expected behavior of functions and system concepts:

- Manual pages (`man`) — Primary reference for understanding standard C library function behavior.
- The Open Group Base Specifications — For standardized behavior of certain functions.
- GNU C Library documentation — Additional clarification on edge cases and implementation details.
- [W3Schools](https://www.w3schools.com/)

---

### Peer Learning
Discussions and evaluations with other 42 students were used to:

- Compare logic and approaches to problem solving
- Improve understanding of memory management and pointer manipulation
- Review code clarity and efficiency
- Validate understanding of project requirements

All implementations were written independently after discussion and comprehension.

---

### AI Usage

AI assistance was used for:

- Explaining C concepts (memory management, pointers, undefined behavior, etc.)
- Clarifying expected behavior of functions and help find bugs
- Helping understand Makefile structure and build logic
- Reviewing explanations and documentation clarity
- Improving README structure and wording

All of the functions were written manually after understanding the concepts.
Same goes for these comments you can find above the functions, I took time to redact them so I could keep track of the code's organization.

Thank you for reading :D

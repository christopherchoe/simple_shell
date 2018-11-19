#  `hsh_`

## Table of Contents
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Implementation](#implementation)
* [Bugs](#bugs)
* [Authors](#authors)
* [License](#license)
## Description
**hsh** is a simple command line interpreter based on the functionality of the POSIX 1003.2-conformant Dash command line interpreter on Ubuntu 14.04. It was implemented as part of a group project for the low-level programming track at Holberton School in San Francisco. For pedagogical reasons, **hsh** was written using only limited subset of the C89 standard library (see [Implementation](#implementation)).
## Installation
- Clone this repository:
`git clone "https://github.com/christopherchoe/simple_shell.git"`
- Compile all `C` source files in the `simple_shell`  directory using `gcc 4.8` or later:
`gcc -Wall -pedantic -Werror -Wextra *.c -o hsh`
## Usage
- To run in interactive mode: `./hsh`
- To run in non-interactive mode: `echo "ls -l" | ./hsh`
### `hsh` Builtin Commands
- [x] **exit**
- [x] **env**
- [ ] **setenv**
- [ ] **unsetenv**
- [ ] **cd**

## Implementation
**hsh** was written using only limited subset of the C89 standard library including the following standard functions and system calls:
`access, execve, exit, fork, free, getline, malloc, perror, wait, write, isatty`
## Bugs
**hsh** has many bugs, known and unknown.
## Authors
* Christopher Choe | [GitHub](https://github.com/christopherchoe)
* Fernando González-Morales | [GitHub](https://github.com/fgonza52)

## License
This project is free to use without permission.
However, it is provided as-is and with absolutely no warranties.

> Written with [StackEdit](https://stackedit.io/). Seriously, check it out.

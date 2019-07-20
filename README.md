#  `hsh_`

## Table of Contents
* [Description](#description)
* [Installation](#installation)
* [Usage](#usage)
* [Implementation](#implementation)
* [Authors](#authors)
* [License](#license)
## Description
**hsh** is a simple command line interpreter based on the functionality of the POSIX 1003.2-conformant Dash command line interpreter on Ubuntu 14.04. For pedagogical reasons, **hsh** was written using only limited subset of the C89 standard library (see [Implementation](#implementation)).
## Installation
- Clone this repository: <br>
`git clone "https://github.com/christopherchoe/simple_shell.git"`</br>
- Compile all `C` source files in the `simple_shell`  directory using `gcc 4.8` or later: <br>
`gcc -Wall -pedantic -Werror -Wextra *.c -o hsh`</br>
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
## Authors
Chris and Fernando are software engineers always open to new opportunities, so do not hesitate to contact us.
* Christopher Choe | [GitHub](https://github.com/christopherchoe) | [LinkedIn](https://linkedin.com/in/choechristopher)
* Fernando González-Morales | [GitHub](https://github.com/fgonza52) | [LinkedIn](https://www.linkedin.com/in/fernando-gonzalez-morales-3748259a)

## License
This project is free to use without permission.
However, it is provided as-is and with absolutely no warranties.

> Written with [StackEdit](https://stackedit.io/). Seriously, check it out.

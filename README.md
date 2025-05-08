# Pipex

## Table of Contents
1. [Description](#description)
2. [Installation](#installation)
3. [Run](#run)
4. [Credits](#credits)
5. [Contributing](#contributing)
6. [License](#license)

## Description

Pipex is a project from the 42 Common Core curriculum designed to introduce the use of the fork() function to create child processes, pipe() to create pipes, explore the envp argument in main, and execute external binary from the initial program.

As part of the 42 curriculum, this project comes with strict coding guidelines:
- The standard C library is forbidden, requiring the use of custom code for all tasks.
- A strict rule of 5 functions per file and 25 lines per function is enforced.
- There are restrictions such as no assignments on the same line and a focus on clean, maintainable code.

### Purpose

The goal of this program is to execute commands given as arguments, such as cat | ls, simulating the behavior of pipes in a shell.

### Technologies used

- C language.
- Make.

### Challenges and Future Features

The main challenges were understanding the third argument of main, called char **env, learning how to parse and detect if a binary exists, properly using fork() to create child processes, ensuring actions only occur in the child process, and executing commands.

I’m not planning to add any new features at this time.

## Installation

- Ensure you have a C compiler installed, such as [Clang](https://clang.llvm.org/) or [GCC](https://gcc.gnu.org/)
```bash
clang --version
gcc --version
```
- Ensure you have installed [Make](https://www.gnu.org/software/make/) to build the project
```bash
make --version
```

## Run

1. Build the project:
```bash
make bonus
```

2. This will create a `./pipex` binary.

3. Run the program with the following arguments:

```bash
./pipex infile cmd1 cmd2 cmd...outfile
```

## Credits

- [CodeVault](https://www.youtube.com/c/CodeVault) for his great videos explaining how pipes, fork(), and other functions work.

## Contributing

To report issues, please create an issue here:  [issue tracker](https://github.com/Vpekdas/pipex/issues).

To contribute, follow these steps:

1. **Fork the repository**: Start by forking the repository to your own GitHub account.

2. **Clone the repository**: Clone the forked repository to your local machine.
```bash
git clone https://github.com/Vpekdas/pipex
```

3. **Create a new branch**: Create a new branch for each feature or bug fix you're working on.
```bash
git checkout -b your-branch-name
```

4. **Commit your changes**: Commit your changes.
```bash
git commit -m "Your commit message"
```

5. **Push your changes**: Push your changes to your forked repository on GitHub.
```bash
git push origin your-branch-name
```

6. **Create a pull request**: Go to your forked repository on GitHub and create a new pull request against the master branch.

## License

This project is licensed under the [MIT License](LICENSE).

# Minishell - 42 Project

![Minishell](https://img.shields.io/badge/status-completed-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Grade](https://img.shields.io/badge/grade-100%2F100-brightgreen)

---

## Introduction

**Minishell** is a 42 project that involves creating a simplified version of a Unix shell. The goal is to understand how shells work by implementing features like command execution, pipes, redirections, and environment variable management.

---

## Overview

This project requires you to build a basic shell that can interpret and execute commands, handle pipelines, and manage file redirections. It also includes features like environment variable expansion and signal handling.

---

## Requirements

- The program must be written in **C**.
- The program must handle command execution, pipes (`|`), and redirections (`>`, `<`, `>>`).
- The program must manage environment variables (`$VAR`).
- The program must handle signals like `Ctrl-C` and `Ctrl-D`.

---

## Installation

1. Clone the repository:
```
   git clone https://github.com/your-username/minishell.git
   cd minishell
```
2. Compile the program using make:
```
  make
  The executable minishell will be generated.
```
## Usage
Run the program with the following command:
```
./minishell
```
Once inside the shell, you can execute commands like:
```
ls -la | grep .c
echo $HOME > output.txt
```
## Features
Command execution (e.g., ls, echo).

Pipes (|) and redirections (>, <, >>).

Environment variable expansion ($VAR).

Signal handling (Ctrl-C, Ctrl-D).

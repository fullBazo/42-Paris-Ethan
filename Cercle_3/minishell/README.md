*This project has been created as part of the 42 curriculum by ehuet, rdupoix.*

# Minishell

## Description

Minishell is a simplified Unix shell built from scratch in C. The goal is to recreate the core behavior of bash, handling command execution, piping, redirections, environment variables, and signal management — all while respecting the constraints of the 42 Norm.

The project covers fundamental systems programming concepts: process creation with `fork`, program execution with `execve`, file descriptor manipulation with `dup2`, inter-process communication with `pipe`, and signal handling with `sigaction`. It also involves building a tokenizer and parser to interpret user input, expand environment variables, and manage quoting rules.

### Features

- Interactive prompt with command history (via `readline`)
- Execution of system binaries and built-in commands
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Pipes (`|`) to chain commands
- Input/output redirections (`<`, `>`, `>>`)
- Here-documents (`<<`) with delimiter and optional variable expansion
- Environment variable expansion (`$VAR`, `$?`)
- Single and double quote handling
- Signal handling: `ctrl+C`, `ctrl+D`, `ctrl+\` (matching bash behavior)
- Proper exit codes (`$?`) propagation across commands, pipes, and signals
- Clean memory management (no leaks on all execution paths)
- Graceful behavior when launched with an empty environment (`env -i`)

### Architecture

The project is split into two main parts:

- **Parsing** (ehuet): Tokenization of user input, quote handling, syntax validation, environment variable expansion, and construction of a command list from tokens.
- **Execution** (rdupoix & ehuet): Process management, pipe setup, redirection handling, here-document collection, built-in execution, signal management, and error handling.

## Instructions

### Prerequisites

- A Unix-based system (Linux / macOS)
- `gcc` or `cc` compiler
- `make`
- `readline` library installed (`libreadline-dev` on Debian/Ubuntu, `readline` on Fedora)

### Compilation

```bash
git clone <repository-url>
cd minishell-42
make
```

This produces the `minishell` binary at the root of the project.

### Execution

```bash
./minishell
```

You will be greeted with a prompt. Type commands as you would in bash.

### Usage Examples

```bash
minishell$ echo "Hello, World!"
Hello, World!

minishell$ ls -la | grep minishell | wc -l
3

minishell$ export NAME=42
minishell$ echo $NAME
42

minishell$ cat << EOF
> line one
> line two
> EOF
line one
line two

minishell$ echo hello > out.txt
minishell$ cat < out.txt
hello

minishell$ exit 42
```

### Testing with Valgrind

```bash
valgrind --leak-check=full --show-leak-kinds=definite --suppressions=readline.supp ./minishell
```

The `readline` library produces "still reachable" blocks that are not actual leaks. Use `--show-leak-kinds=definite` to filter them out.

## Resources

### Documentation and References

- [The Open Group Base Specifications — Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) — POSIX shell specification, the authoritative reference for shell behavior.
- [Bash Reference Manual (GNU)](https://www.gnu.org/software/bash/manual/bash.html) — detailed documentation of bash features and behavior, used as the primary comparison target.
- [man pages](https://man7.org/linux/man-pages/) — `fork(2)`, `execve(2)`, `pipe(2)`, `dup2(2)`, `waitpid(2)`, `sigaction(2)`, `open(2)`, `stat(2)`, `readline(3)`.
- [Harm-Smits' 42 Minishell Guide](https://harm-smits.github.io/42docs/projects/minishell) — community walkthrough of the project structure and common pitfalls.
- [42 Norm V4](https://github.com/42School/norminette) — coding style rules enforced on the project.

### Use of AI

AI (Claude by Anthropic) was used as a learning and debugging companion throughout the project. Specifically:

- **Conceptual understanding**: Explaining how signals, process groups, file descriptors, and terminal settings interact in a Unix shell. Understanding the difference between `SIGINT`/`SIGQUIT` behavior in interactive mode vs. during execution.
- **Debugging assistance**: Analyzing Valgrind output to trace memory leaks and invalid reads. Identifying root causes such as double frees from shared pointers between tokens and commands, off-by-one errors in `ft_strncmp`, and uninitialized struct fields.
- **Architecture decisions**: Designing the heredoc system (fork-based collection, temporary file naming with PID, signal handling within the child process). Structuring `t_shell` as a central state container for clean memory management across all exit paths.

All code was written, understood, and validated by the team. AI was not used to generate code blindly — every suggestion was reviewed, tested, and adapted to fit the project's architecture and constraints.

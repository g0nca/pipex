# 🚀 PIPEX Project

## 📌 What is PIPEX?
The **PIPEX** project from **42** aims to recreate the behavior of the shell pipeline operator (`|`). In other words, you will create a program that links the output of one command to the input of another, just like when using the terminal command:

```sh
ls -l | grep "txt"
```

### 🔍 Objective
Create a C program that executes:

```sh
./pipex file1 "cmd1" "cmd2" file2
```

This should replicate the following shell command:

```sh
< file1 cmd1 | cmd2 > file2
```

In other words:
1️⃣ **Read** data from `file1`
2️⃣ **Execute** `cmd1` using `file1` as input
3️⃣ **Pass** the output of `cmd1` as input to `cmd2`
4️⃣ **Save** the final result in `file2`

---

## 🛠️ How to Implement - Step by Step

### 1️⃣ Open the files
- Use `open()` to open `file1` (read) and `file2` (write).

### 2️⃣ Create a pipe
- Use `pipe()` to create a communication channel between processes.

### 3️⃣ Create processes
- Use `fork()` to create two child processes.

### 4️⃣ Redirect input and output
- The first process redirects `file1` to the command input.
- The second process redirects the output of the first command to the input of the second.

### 5️⃣ Execute the commands
- Use `execve()` to replace the current process with the desired command.

### 6️⃣ Close files and wait for processes
- Use `close()` and `waitpid()` to ensure everything finishes correctly.

---

## 🔧 Essential Functions

### 📂 `open()`
Opens files for reading or writing. It returns a file descriptor or `-1` if an error occurs.
```c
int fd = open("file.txt", O_RDONLY);
if (fd == -1) {
    perror("open failed");
}
```

### 🔗 `pipe()`
Creates a unidirectional data channel between two processes. It returns `0` on success and `-1` on failure.
```c
int fd[2];
if (pipe(fd) == -1) {
    perror("pipe failed");
}
```

### 👶 `fork()`
Creates a new child process. Returns `0` in the child process and the child's PID in the parent.
```c
pid_t pid = fork();
if (pid == -1) {
    perror("fork failed");
}
```

### 🔄 `dup2()`
Duplicates a file descriptor to another, redirecting standard input or output.
```c
int fd = open("input.txt", O_RDONLY);
dup2(fd, STDIN_FILENO);
close(fd);
```

### 🚀 `execve()`
Replaces the current process with a new program. It requires the full path of the executable and an argument list.
```c
char *args[] = {"/bin/ls", "-l", NULL};
execve(args[0], args, envp);
perror("execve failed");
```

### ❌ `close()`
Closes a file descriptor, releasing system resources.
```c
close(fd);
```

### 🕒 `waitpid()`
Waits for a specific child process to terminate, ensuring proper process synchronization.
```c
int status;
pid_t pid = waitpid(child_pid, &status, 0);
if (pid == -1) {
    perror("waitpid failed");
}
```

---

## 🔍 PIPEX Execution Flow

```sh
# ./pipex infile cmd1 cmd2 outfile
pipe()
 |
 |-- fork()
      |
      |-- child // cmd1
      :     |--dup2()
      :     |--close end[0]
      :     |--execve(cmd1)
      :
      |-- parent // cmd2
            |--dup2()
            |--close end[1]
            |--execve(cmd2)
```

### Explanation:
- **`pipe()`** creates a communication channel, allowing data to be transferred from one process to another.
- **`fork()`** generates a new child process, so we can run two commands within a single program.
- **Child Process:**
  - Uses **`dup2()`** to redirect input/output.
  - Closes the read end of the pipe.
  - Executes `cmd1` with **`execve()`**.
- **Parent Process:**
  - Uses **`dup2()`** to set up input/output redirection.
  - Closes the write end of the pipe.
  - Executes `cmd2` with **`execve()`**.

### 📌 Understanding `pipe()`
- `pipe()` takes an array of two integers and links them together.
- What is done in `end[0]` is visible to `end[1]`, and vice versa.
- `pipe()` assigns a **file descriptor (fd)** to each end.
- File descriptors allow files to be read and written to. Since each end gets an fd, they can communicate.
- `end[1]` writes to its own fd, and `end[0]` reads from `end[1]`’s fd and writes to its own.

### 📌 Code Example: Pipex Implementation
```c
void pipex(int f1, int f2)
{
    int   end[2];
    pid_t parent;
    
    pipe(end);
    parent = fork();
    if (parent < 0)
         return (perror("Fork: "));
    if (!parent) // if fork() returns 0, we are in the child process
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}
```

### 📌 Understanding `fork()`
- `fork()` splits the process into two subprocesses -> parallel, simultaneous, happen at the same time.
- It returns `0` for the child process, a non-zero value for the parent process, and `-1` in case of an error.

### 📌 File Descriptors (FDs)
- `end[1]` is the child process, `end[0]` is the parent process.
- The child writes, and the parent reads.
- Since for something to be read, it must be written first, `cmd1` is executed by the child, and `cmd2` by the parent.
- `pipex` is run like this: `./pipex infile cmd1 cmd2 outfile`.
- FDs `0`, `1`, and `2` are by default assigned to stdin, stdout, and stderr.
- `infile`, `outfile`, the pipe, stdin, and stdout are all FDs.

#### 🔍 Checking Open File Descriptors on Linux
```sh
ls -la /proc/$$/fd
```

### 📌 FD Table Representation
```
                           -----------------    
                 0         |     stdin     |  
                           -----------------    
                 1         |     stdout    |    
                           -----------------    
                 2         |     stderr    |  
                           -----------------
                 3         |     infile    |  // open()
                           -----------------
                 4         |     outfile   |  // open()
                           -----------------
                 5         |     end[0]    | 
                           -----------------
                 6         |     end[1]    |  
                           -----------------
```


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

## 📢 Conclusion
The **PIPEX** project is an excellent exercise for learning about **processes, pipes, and input/output redirection** in C. It is fundamental for gaining a deeper understanding of how the **shell** works internally. Good luck with your coding! 🚀


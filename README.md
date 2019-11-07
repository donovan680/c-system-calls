# c-system-calls
Running a new program
The UNIX way: fork-and-exec style

There is a family of system calls in UNIX that executes a new program. The system call we will discuss here is execv(). At some point you may want to use other system calls in the exec syscall family. You can use man exec to find more information about them.

The execv system call (and all system calls in the exec family) performs the following:

    Blow away the current process's virtual address space
    Begin executing the specified program in the current process

Note that execv does not "spawn" a process. It destroys the current process. Therefore it's common to use execv in conjunction with fork: we first use fork() to create a child process, and then use execv() to run a new program inside the child.

 Recall that an exec call will load a new program into the process and replace the current running program with the one specified. For example, consider this program, which will execute the ls -l command in the current directory:

There are three main versions of exec which we will focus on:

    execv(char * path, char * argv[]) : given the path to the program and an argument array, load and execute the program
    execvp(char * file, char * argv[]) : given a file(name) of the program and an argument array, find the file in the environment PATH and execute the program
    execvpe(char * file, char * argv[], char * envp[]) given a file(name), an argument array, and the enviroment settings, within the enviroment, search the PATH for the program named file and execute with the arguments.

Each version of execute provides slightly different functionality. For this discussion, we will focus on execv and execvp; we will discuss execvpe latter in the semester.
1.1 Using execv and execvp

The primary difference between execv and execvp is that with execv you have to provide the full path to the binary file (i.e., the program). The argv[] array is the same otherwise.

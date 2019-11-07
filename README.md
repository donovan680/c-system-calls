# c-system-calls
Running a new program
The UNIX way: fork-and-exec style

There is a family of system calls in UNIX that executes a new program. The system call we will discuss here is execv(). At some point you may want to use other system calls in the exec syscall family. You can use man exec to find more information about them.

The execv system call (and all system calls in the exec family) performs the following:

    Blow away the current process's virtual address space
    Begin executing the specified program in the current process

Note that execv does not "spawn" a process. It destroys the current process. Therefore it's common to use execv in conjunction with fork: we first use fork() to create a child process, and then use execv() to run a new program inside the child.

Recall that an exec call will load a new program into the processand replace the current running program with the one specified. Forexample, consider this program, which will execute the ls -l commandin the current directory:There are three main versions of exec which we will focus on:execv(char * path, char * argv[]) : given the path to the programand an argument array, load and execute the programexecvp(char * file, char * argv[]) : given a file(name) of theprogram and an argument array, find the file in the environmentPATH and execute the programexecvpe(char * file, char * argv[], char * envp[]) given afile(name), an argument array, and the enviroment settings, withinthe enviroment, search the PATH for the program named file andexecute with the arguments.Each version of execute provides slightly different functionality. Forthis discussion, we will focus on execv and execvp; we willdiscuss execvpe latter in the semester.1.1 Using execv and execvpThe primary difference between execv and execvp is that withexecv you have to provide the full path to the binary file (i.e.,the program). The argv[] array is the same otherwise. 

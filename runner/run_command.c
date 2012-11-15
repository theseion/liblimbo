//
//  run_command.c
//  runner
//
//  Created by theseion on 06.11.12.
//  Copyright (c) 2012 theseion. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "run_command.h"
#include <signal.h>

char *buffer_array[2];

char** run_command(char *argv[]){
    pid_t pid;
    int out_pipe[2], err_pipe[2];
    int status = 0;
    struct stat out_stat, err_stat;
    char *out_buffer, *err_buffer;
    
    pipe(out_pipe); //create a pipe
    pipe(err_pipe);
    if(!(pid = fork())) //spawn child 
    {
        // Child. Close the read end of the pipe
        close(out_pipe[0]);
        close(err_pipe[0]);
        // redirect stdout and stderr to the write end of the pipe
        dup2(out_pipe[1], STDOUT_FILENO);
        dup2(err_pipe[1], STDERR_FILENO);
        execv(argv[0], argv); //child will terminate here
    }

    //Only parent gets here. Close write end of the pipe
    close(out_pipe[1]);
    close(err_pipe[1]);
    //or wait for the child process to terminate
    waitpid(pid, &status, 0);

    fstat(out_pipe[0], &out_stat);
    fstat(err_pipe[0], &err_stat);
    
    out_buffer = malloc((int)out_stat.st_size);
    err_buffer = malloc((int)err_stat.st_size);
    
    out_buffer[read(out_pipe[0], out_buffer, (int)out_stat.st_size)] = 0;
    err_buffer[read(err_pipe[0], err_buffer, (int)err_stat.st_size)] = 0;
    
    buffer_array[0] = out_buffer;
    buffer_array[1] = err_buffer;
    
    return buffer_array;
}
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
#include <errno.h>
int out_pipe[2], err_pipe[2];

int run_command(char *argv[], int *out_length, int *err_length){
    pid_t pid;
    int status = 0;
    struct stat out_stat, err_stat;
    EINTR
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
        status = execv(argv[0], argv); //child will terminate here
    }

    //Only parent gets here. Close write end of the pipe
    close(out_pipe[1]);
    close(err_pipe[1]);
    //or wait for the child process to terminate
    waitpid(pid, &status, 0);

    fstat(out_pipe[0], &out_stat);
    fstat(err_pipe[0], &err_stat);
    
    *out_length = (int) out_stat.st_size;
    *err_length = (int) err_stat.st_size;
    
    return status;
}

int read_buffers(char *out_buffer, int out_length, char *err_buffer, int err_length){
    out_buffer[read(out_pipe[0], out_buffer, out_length)] = 0;
    err_buffer[read(err_pipe[0], err_buffer, err_length)] = 0;
    
    return 0;
}
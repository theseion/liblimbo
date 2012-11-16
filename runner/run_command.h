//
//  run_command.h
//  runner
//
//  Created by theseion on 06.11.12.
//  Copyright (c) 2012 theseion. All rights reserved.
//

#ifndef runner_run_command_h
#define runner_run_command_h

int run_command(char *argv[], int *std_out_length, int *std_err_length);
int read_buffers(char *out_buffer, int out_length, char *err_buffer, int err_length);

#endif
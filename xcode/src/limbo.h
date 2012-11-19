//
//  limbo.h
//
//  Created by Max Leske on 16.11.12.
//  Copyright (c) 2012 Max Leske. All rights reserved.
//

#ifndef limbo_h
#define limbo_h

int run_command(char *argv[], int *std_out_length, int *std_err_length);
int read_buffers(char *out_buffer, int out_length, char *err_buffer, int err_length);

#endif
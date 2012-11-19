//
//  test.c
//  runner
//
//  Created by theseion on 07.11.12.
//  Copyright (c) 2012 theseion. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "limbo.h"
#include <unistd.h>

int main() {
    char *argv[] = {"/bin/cat", "/etc/hosts", 0};
    int out_length, err_length;
    char *out_buffer, *err_buffer;

    run_command(argv, &out_length, &err_length);
    out_buffer = malloc((int) out_length);
    err_buffer = malloc((int) err_length);
    read_buffers(out_buffer, out_length, err_buffer, err_length);
    
    printf("out: %s\n", out_buffer);
    printf("err: %s\n", err_buffer);
    free(out_buffer);
    free(err_buffer);
    
    return 0;
}
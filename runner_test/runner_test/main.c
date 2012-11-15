//
//  test.c
//  runner
//
//  Created by theseion on 07.11.12.
//  Copyright (c) 2012 theseion. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "run_command.h"
#include <unistd.h>
#include <errno.h>

int main() {
    char *argv[] = {"/bin/cat", "/etc/hosts", 0};
    char **buffer_ptr = run_command(argv);
    
    printf("out: %s\n", buffer_ptr[0]);
    printf("err: %s\n", buffer_ptr[1]);
    free(buffer_ptr[0]);
    free(buffer_ptr[1]);
    return 0;
}
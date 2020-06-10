//
//  anti_debug.c
//  AntiDebugging
//
//  Created by Vadim Drobinin on 10/06/2020.
//  Copyright © 2020 Vadim Drobinin. All rights reserved.
//

#include "anti_debug.h"

void m6d64657663616d70() {
  #if TARGET_CPU_ARM64
  __asm(
    "mov r0, #31\n"
    "mov r1, #0\n"
    "mov r2, #0\n"
    "mov r3, #0\n"
    "mov ip, #26\n"
    "svc #0x80\n"
  );
  #endif
}

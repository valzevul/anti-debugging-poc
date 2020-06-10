//
//  anti_debug.c
//  AntiDebugging
//
//  Created by Vadim Drobinin on 10/06/2020.
//  Copyright © 2020 Vadim Drobinin. All rights reserved.
//

#include "anti_debug.h"


/**
 Heavily inspired by
 - https://stackoverflow.com/a/55575155
 - https://knight.sc/debugging/2019/06/03/debugging-apple-binaries-that-use-pt-deny-attach.html
 */

void m6d64657663616d70() {
  #if TARGET_CPU_ARM64 // Won't work in the Simulator
  __asm(
    "mov r0, #31\n" // set `#define PT_DENY_ATTACH (31)` to r0
    "mov r1, #0\n" // clear r1
    "mov r2, #0\n" // clear r2
    "mov r3, #0\n" // clear r3
    "mov ip, #26\n" // set the instruction pointer to `syscal 26`
    "svc #0x80\n" // SVC (formerly SWI) generates a supervisor call to request privileged operations or access to system resources from an operating system
  );
  // ↑ No need to encode strings as they'll be compiled directly hence won't be present in the `Data` part of the binary.
  #endif
}

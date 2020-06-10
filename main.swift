//
//  main.swift
//  AntiDebugging
//
//  Created by Vadim Drobinin on 10/06/2020.
//  Copyright © 2020 Vadim Drobinin. All rights reserved.
//

import UIKit

m6d64657663616d70() // Launching it before everything else

UIApplicationMain(
    CommandLine.argc,
    CommandLine.unsafeArgv,
    nil,
    NSStringFromClass(AppDelegate.self)
)

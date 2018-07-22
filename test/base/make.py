#!/usr/bin/env python3
#coding: utf-8

import licant
import licant.libs
from licant.cxx_modules import application
from licant.modules import submodule

licant.libs.include("gxx")
licant.libs.include("g1")
licant.libs.include("g3")

application("target",
	sources = ["main.cpp"],
	include_paths = ["../.."],
	include_modules = [
		("gxx", "posix"),
		("gxx.print", "cout"),
		("gxx.dprint", "cout"),
		("gxx.log2", "impl"),
		("gxx.syslock", "mutex"),

		("g1"),
		("g1.allocator", "malloc"),
		("g1.time", "chrono"),

		("g3"),		
	],
)

licant.ex("target")
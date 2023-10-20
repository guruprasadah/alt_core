target_include_directories(alt_core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(alt_core PUBLIC "alt/memory.cpp"
							   "alt/string.cpp"
							   "alt/hash.cpp")

include(${CMAKE_CURRENT_LIST_DIR}/MiniPPGenerator.cmake)

#set(myVar "Begin of file\n")
#mini_pp_generate_unroll(myVar 0 125)

file(READ ${miniPPMainGeneratorInOutFile} inOutFileContent)

string(FIND ${inOutFileContent} "// Unroll Utility" unrollUtilityBegin)

message("miniPPMainGeneratorInOutFile ${miniPPMainGeneratorInOutFile}")


# "Unroll Utility"

file(WRITE ${miniPPMainGeneratorInOutFile} ${inOutFileContent})


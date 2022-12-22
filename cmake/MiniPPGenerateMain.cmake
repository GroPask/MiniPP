include(${dpcmake_SOURCE_DIR}/dpCMake.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/MiniPPGenerator.cmake)

file(READ ${miniPPMainGeneratorInOutFile} inOutFileContent)

string(FIND ${inOutFileContent} "#define MINI_PP_MAX_NB_ARGS" nbArgsDefineBegin)
if (${nbArgsDefineBegin} EQUAL -1)
	return()
endif ()
string(SUBSTRING ${inOutFileContent} 0 ${nbArgsDefineBegin} inOutFileContent)

mini_pp_private_generate_basic_arg_tools(inOutFileContent 125)
string(APPEND inOutFileContent "\n")
mini_pp_private_generate_for_each(inOutFileContent 0 125)
string(APPEND inOutFileContent "\n")
mini_pp_private_generate_int_tools(inOutFileContent 0 1024)
string(APPEND inOutFileContent "\n")
mini_pp_private_generate_while(inOutFileContent 0 1024)
string(APPEND inOutFileContent "\n#endif\n")

file(WRITE ${miniPPMainGeneratorInOutFile} ${inOutFileContent})

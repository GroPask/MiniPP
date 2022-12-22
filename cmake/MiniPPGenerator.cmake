set(miniPPPrivateAvailableSynbolsFirst "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")
set(miniPPPrivateAvailableSynbols "${miniPPPrivateAvailableSynbolsFirst}0123456789")

string(LENGTH ${miniPPPrivateAvailableSynbolsFirst} miniPPPrivateSymbolsCountFirst)
string(LENGTH ${miniPPPrivateAvailableSynbols} miniPPPrivateSymbolsCount)

string(SUBSTRING ${miniPPPrivateAvailableSynbols} 0 1 miniPPPrivateFirstSymbol)

math(EXPR miniPPPrivateLastSymbolsIndexFirst "${miniPPPrivateSymbolsCountFirst} - 1")
math(EXPR miniPPPrivateLastSymbolsIndex "${miniPPPrivateSymbolsCount} - 1")

set_property(GLOBAL PROPERTY miniPPPrivateGeneratedShortNameCache "")

function (mini_pp_private_replace_in_string outVar inString index replaceString)
    if (index GREATER 0)
        string(SUBSTRING ${inString} 0 ${index} result)
    else ()
        set(result "")
    endif ()

    string(APPEND result ${replaceString})

    string(LENGTH ${inString} inStringLength)
    math(EXPR endBegin "${index} + 1")

    if (endBegin LESS ${inStringLength})
        math(EXPR endLength "${inStringLength} - ${endBegin}")
        string(SUBSTRING ${inString} ${endBegin} ${endLength} end)

        string(APPEND result ${end})
    endif ()

    set(${outVar} ${result} PARENT_SCOPE)
endfunction ()

function (mini_pp_private_go_to_next_short_name outVar shortName)
    string(LENGTH ${shortName} shortNameLength)
    math(EXPR symbolIndex "${shortNameLength} - 1")

    while (0 LESS 1)
        string(SUBSTRING ${shortName} ${symbolIndex} 1 symbol)
        string(FIND ${miniPPPrivateAvailableSynbols} ${symbol} symbolIndexInTable)

        if ((${symbolIndexInTable} LESS ${miniPPPrivateLastSymbolsIndexFirst}) OR (${symbolIndexInTable} LESS ${miniPPPrivateLastSymbolsIndex} AND ${symbolIndex} GREATER 0))
            math(EXPR newSymbolIndexInTable "${symbolIndexInTable} + 1")
            string(SUBSTRING ${miniPPPrivateAvailableSynbols} ${newSymbolIndexInTable} 1 newSymbol)

            mini_pp_private_replace_in_string(shortName ${shortName} ${symbolIndex} ${newSymbol})

            break()
        else ()
            mini_pp_private_replace_in_string(shortName ${shortName} ${symbolIndex} ${miniPPPrivateFirstSymbol})

            if (${symbolIndex} EQUAL 0)
                string(PREPEND shortName ${miniPPPrivateFirstSymbol})
                break()
            else ()
                math(EXPR symbolIndex "${symbolIndex} - 1")
            endif ()           
        endif ()
    endwhile ()

    set(${outVar} ${shortName} PARENT_SCOPE)
endfunction ()

function (mini_pp_private_generate_short_name outVar shortNameIndex)
    get_property(shortNameCache GLOBAL PROPERTY miniPPPrivateGeneratedShortNameCache)
    list(LENGTH shortNameCache shortNameCacheLength)

    if (${shortNameCacheLength} EQUAL 0)
        list(APPEND shortNameCache ${miniPPPrivateFirstSymbol})
    endif ()

    list(LENGTH shortNameCache shortNameCacheLength)

    if (${shortNameIndex} GREATER_EQUAL ${shortNameCacheLength})
        math(EXPR lastShorNameIndex "${shortNameCacheLength} - 1")
        list(GET shortNameCache ${lastShorNameIndex} lastShortName)

        foreach (i RANGE ${shortNameCacheLength} ${shortNameIndex})
            mini_pp_private_go_to_next_short_name(lastShortName ${lastShortName})
            list(APPEND shortNameCache ${lastShortName})
        endforeach ()
    endif ()

    list(GET shortNameCache ${shortNameIndex} shortName)
    set(${outVar} ${shortName} PARENT_SCOPE)

    set_property(GLOBAL PROPERTY miniPPPrivateGeneratedShortNameCache ${shortNameCache})
endfunction ()

function (mini_pp_private_generate_basic_arg_tools inOutStringVar maxNbArgs)
    dp_assert(${maxNbArgs} GREATER_EQUAL 1)

    set(result ${${inOutStringVar}})

    string(APPEND result "#define MINI_PP_MAX_NB_ARGS ${maxNbArgs}\n\n")

    string(APPEND result "#define MINI_PP_PRIVATE_ARG_SEQ_MAX_MINUS_ONE_TRUE_THEN_FALSE ")
    if (${maxNbArgs} GREATER_EQUAL 2)
        foreach (i RANGE 2 ${maxNbArgs})
            string(APPEND result "1,")
        endforeach ()
    endif ()
    string(APPEND result "0\n")

    string(APPEND result "#define MINI_PP_PRIVATE_ARG_SEQ_MAX_TO_0 ")
    foreach (i RANGE ${maxNbArgs} 1)
        string(APPEND result "${i},")
    endforeach ()
    string(APPEND result "0\n")

    string(APPEND result "#define MINI_PP_PRIVATE_GET_ARG_INDEX_MAX(")
    foreach (i RANGE 0 ${maxNbArgs})
        mini_pp_private_generate_short_name(argName ${i})
        string(APPEND result "${argName},")
    endforeach ()
    mini_pp_private_generate_short_name(lastArgName ${maxNbArgs})
    string(APPEND result "...)${argName}\n")

    set(${inOutStringVar} ${result} PARENT_SCOPE)
endfunction ()

function (mini_pp_private_generate_for_each inOutStringVar from to)
    dp_assert(${from} GREATER_EQUAL 0)
    dp_assert(${from} LESS_EQUAL ${to})

    set(result ${${inOutStringVar}})

    foreach (variationIndex RANGE ${from} ${to})
        mini_pp_private_generate_short_name(funcArgName 0)
        mini_pp_private_generate_short_name(paramsArgName 1)

        string(APPEND result "#define MINI_PP_PRIVATE_LOOP_UNROLL_${variationIndex}(${funcArgName},${paramsArgName}")

        math(EXPR lastArgIndex "${variationIndex} + 1")

        if (lastArgIndex GREATER_EQUAL 2)
            foreach (argIndex RANGE 2 ${lastArgIndex})
                mini_pp_private_generate_short_name(argName ${argIndex})
                string(APPEND result ",${argName}")
            endforeach ()
        endif ()

        string(APPEND result ")")

        if (lastArgIndex GREATER_EQUAL 2)
            foreach (argIndex RANGE 2 ${lastArgIndex})
                mini_pp_private_generate_short_name(argName ${argIndex})

                if (NOT argIndex EQUAL 2)
                    string(APPEND result " ")
                endif ()

                string(APPEND result "${funcArgName}(${paramsArgName},${argName})")
            endforeach ()
        endif ()

        string(APPEND result "\n")
    endforeach ()

    set(${inOutStringVar} ${result} PARENT_SCOPE)
endfunction ()

function (mini_pp_private_generate_int_tools inOutStringVar from to)
    dp_assert(${from} GREATER_EQUAL 0)
    dp_assert(${from} LESS_EQUAL ${to})

    set(result ${${inOutStringVar}})

     string(APPEND result "#define MINI_PP_MAX_INT ${to}\n\n")

    foreach (i RANGE ${from} ${to})
        string(APPEND result "#define MINI_PP_PRIVATE_INT_TOOL_BASE_${i}_${i}\n")
    endforeach ()

    string(APPEND result "\n#define MINI_PP_PRIVATE_INT_TOOL_0(f,p)f(p,0,NAN,1)(f,p)\n")

    if (${to} GREATER_EQUAL 1)
        math(EXPR toMinusOne "${to} - 1")

        if (${to} GREATER 1)
            foreach (i RANGE 1 ${toMinusOne})
                math(EXPR iMinusOne "${i} - 1")
                math(EXPR iPlusOne "${i} + 1")
                string(APPEND result "#define MINI_PP_PRIVATE_INT_TOOL_${i}(f,p)f(p,${i},${iMinusOne},${iPlusOne})(f,p)\n")
            endforeach ()
        endif ()

        string(APPEND result "#define MINI_PP_PRIVATE_INT_TOOL_${to}(f,p)f(p,${to},${toMinusOne},NAN)(f,p)\n")
    endif ()

    set(${inOutStringVar} ${result} PARENT_SCOPE)
endfunction()

function (mini_pp_private_generate_while inOutStringVar from to)
    dp_assert(${from} GREATER_EQUAL 0)
    dp_assert(${from} LESS_EQUAL ${to})

    set(result ${${inOutStringVar}})

    #string(APPEND result "#define MINI_PP_PRIVATE_WE(p,o,e,s)e s\n")
    #foreach (i RANGE ${from} ${to})
    #    math(EXPR iPlusOne "${i} + 1")   
    #    string(APPEND result "#define MINI_PP_PRIVATE_W${i}(p,o,e,s)MINI_PP_IF_ELSE(p(s),MINI_PP_PRIVATE_W${iPlusOne},MINI_PP_PRIVATE_WE)(p,o,e,MINI_PP_IF(p(s),o)(s))\n")
    #endforeach ()

    string(APPEND result "#define MINI_PP_PRIVATE_WE(p,o,e,s)e s\n")
    foreach (i RANGE ${from} ${to})
        math(EXPR iPlusOne "${i} + 1")   
        string(APPEND result "#define MINI_PP_PRIVATE_W${i}(p,o,e,s)MINI_PP_IF_ELSE(p(${i},s),MINI_PP_PRIVATE_W${iPlusOne},MINI_PP_PRIVATE_WE)(p,o,e,MINI_PP_IF(p(${i},s),o)(${i},s))\n")
    endforeach ()


    string(APPEND result "\n\n\n")
    foreach (i RANGE ${from} ${to})
        math(EXPR iPlusOne "${i} + 1")   
        string(APPEND result "#define MINI_PP_PRIVATE_L${i}(func, ...)func(__VA_ARGS__) MINI_PP_PRIVATE_L${iPlusOne}\n")
    endforeach ()

    string(APPEND result "\n")
    foreach (i RANGE ${from} ${to})
        string(APPEND result "#define MINI_PP_PRIVATE_L${i}MINI_PP_PRIVATE_LE\n")
    endforeach ()

    string(APPEND result "\n")
    foreach (i RANGE ${from} ${to})
        math(EXPR iPlusOne "${i} + 1")
        string(APPEND result "#define MINI_PP_PRIVATE_SEQ_CONSUME${i}(...) MINI_PP_PRIVATE_SEQ_CONSUME${iPlusOne}\n")
    endforeach ()

    string(APPEND result "\n")
    foreach (i RANGE ${from} ${to})
       string(APPEND result "#define MINI_PP_PRIVATE_SEQ_CONSUME${i}FINISH\n")
    endforeach ()

    set(base 8)
    string(APPEND result "\n")
    foreach (i RANGE ${from} ${to})
        string(APPEND result "#define MINI_PP_PARENT${i}(...)")

        math(EXPR baseFactor "${i} / ${base}")
        math(EXPR baseRemainder "${i} % ${base}")

        if (${baseFactor} GREATER 0)
            foreach (j RANGE 1 ${base})
                string(APPEND result "MINI_PP_PARENT${baseFactor}(__VA_ARGS__)")
            endforeach ()
        endif ()

        if (${baseRemainder} EQUAL 0)
        elseif (${i} LESS ${base})
            foreach (j RANGE 1 ${baseRemainder})
                string(APPEND result "(__VA_ARGS__)")
            endforeach ()
        else ()
            string(APPEND result "MINI_PP_PARENT${baseRemainder}(__VA_ARGS__)")
        endif ()
  
        string(APPEND result "\n")
    endforeach ()

    string(APPEND result "\n")
    foreach (i RANGE ${from} ${to})
        math(EXPR iPlusOne "${i} + 1")
        #string(APPEND result "#define MINI_PP_PRIVATE_SG${i}(m)(${i})MINI_PP_PRIVATE_SG${iPlusOne}(m\n")
        #string(APPEND result "#define MINI_PP_PRIVATE_SG${i}(m,d)(${i},d)MINI_PP_IF_ELSE(MINI_PP_IS_EQUAL(${i},m),MINI_PP_PRIVATE_SEQ_CONSUME0,MINI_PP_PRIVATE_SG${iPlusOne})\n")
        #string(APPEND result "#define MINI_PP_PRIVATE_LOOP${i}(p,f,...)f(${i},__VA_ARGS__)MINI_PP_IF_ELSE(p(${iPlusOne},__VA_ARGS__),MINI_PP_PRIVATE_LOOP${iPlusOne},MINI_PP_PRIVATE_SEQ_CONSUME0)\n")

        string(APPEND result "#define MINI_PP_PRIVATE_LOOP${i}(p,o,...)MINI_PP_IF(p(${i},__VA_ARGS__),o(${i},__VA_ARGS__))MINI_PP_IF_ELSE(p(${i},__VA_ARGS__),MINI_PP_PRIVATE_LOOP${iPlusOne},MINI_PP_PRIVATE_SEQ_CONSUME0)\n")
    endforeach ()

    set(${inOutStringVar} ${result} PARENT_SCOPE)
endfunction ()

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

    while (true)
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

function (mini_pp_private_for_each inOutStringVar from to)
    set(result ${${inOutStringVar}})

    foreach (variationIndex RANGE ${from} ${to})
        mini_pp_private_generate_short_name(funcArgName 0)
        mini_pp_private_generate_short_name(paramsArgName 1)

        string(APPEND result "#define MINI_PP_PRIVATE_FOREACH${variationIndex}(${funcArgName},${paramsArgName}")

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

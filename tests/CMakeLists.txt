
add_library(test_smalpha test_smalpha.cpp)
target_link_libraries(test_smalpha smalpha smorse)

add_executable(test_smalpha_main test_smalpha_main.cpp)
target_link_libraries(test_smalpha_main test_smalpha)

add_executable(test_extra_smalpha_main test_extra_smalpha_main.cpp)
target_link_libraries(test_extra_smalpha_main test_smalpha)

add_test(NAME test_smalpha_1 COMMAND test_smalpha_main .--...-.-.-.....-.--........----.-.-..---.---.--.--.-.-....-..-...-.---..--.----.. 1)
add_test(NAME test_smalpha_2 COMMAND test_smalpha_main .----...---.-....--.-........-----....--.-..-.-..--.--...--..-.---.--..-.-...--..- 1)
add_test(NAME test_smalpha_3 COMMAND test_smalpha_main ..-...-..-....--.---.---.---..-..--....-.....-..-.--.-.-.--.-..--.--..--.----..-.. 1)

add_test(NAME test_extra_smalpha_1 COMMAND test_extra_smalpha_main .--...-.-.-.....-.--........----.-.-..---.---.--.--.-.-....-..-...-.---..--.----.. wirnbfzehatqlojpgcvusyxkmd)
add_test(NAME test_extra_smalpha_2 COMMAND test_extra_smalpha_main .----...---.-....--.-........-----....--.-..-.-..--.--...--..-.---.--..-.-...--..- wzjlepdsvothqfxkbgrmyicuna)
add_test(NAME test_extra_smalpha_3 COMMAND test_extra_smalpha_main ..-...-..-....--.---.---.---..-..--....-.....-..-.--.-.-.--.-..--.--..--.----..-.. uvfsqmjazxthbidyrkcwegponl)

find_package(Boost 1.56 COMPONENTS chrono)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    add_library(test_bonus_1_smalpha test_bonus_1_smalpha.cpp)
    target_link_libraries(test_bonus_1_smalpha smalpha smorse Boost::chrono)

    add_executable(test_bonus_1_smalpha_main test_bonus_1_smalpha_main.cpp)
    target_link_libraries(test_bonus_1_smalpha_main test_bonus_1_smalpha)

    function(do_test_bonus_1_smalpha infile num)
        add_test(NAME test_bonus_1_smalpha_${num} COMMAND test_bonus_1_smalpha_main ${infile} ${num})
        set_tests_properties(test_bonus_1_smalpha_${num} PROPERTIES REQUIRED_FILES ${infile})
    endfunction(do_test_bonus_1_smalpha)

    do_test_bonus_1_smalpha(${CMAKE_CURRENT_SOURCE_DIR}/data/smorse2-bonus1.in.txt 1)

endif(Boost_FOUND)

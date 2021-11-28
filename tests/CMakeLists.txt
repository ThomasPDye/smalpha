
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

// TODO: Cmake, нормальная файловая структура, мб больше тестов, проверить атрибуты и теги (что-то добавить, удалить), методы, css

#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

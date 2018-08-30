#include <cctype>
#include <cstdint>
#include <cstring>


#include <gtest/gtest.h>

#include "ozen/ozen_u8_utils_cx.h"



namespace {


// C++ stream interface
class TestCout : public std::stringstream
{
public:
	~TestCout()
	{
		std::cout << str().c_str();
	}
};

}

#define TEST_COUT  TestCout()

TEST(u8ctype_test, is)
{
	for (int i = 0; i < 0x100; ++i) {
		//if (std::isprint(i)) {
		//	TEST_COUT << "value : \'" << (char)i << "\' (" << std::hex << i << ")" << std::endl;
		//}
		//else {
		//	TEST_COUT << "value : " << i << "(" << std::hex << i << ")" << std::endl;
		//}
		EXPECT_EQ(std::isalnum(i) != 0, ozen::u8ctype::isalnum(i));
		EXPECT_EQ(std::isalpha(i) != 0, ozen::u8ctype::isalpha(i));
		EXPECT_EQ(std::isblank(i) != 0, ozen::u8ctype::isblank(i));
		EXPECT_EQ(std::iscntrl(i) != 0, ozen::u8ctype::iscntrl(i));
		EXPECT_EQ(std::isdigit(i) != 0, ozen::u8ctype::isdigit(i));
		EXPECT_EQ(std::isgraph(i) != 0, ozen::u8ctype::isgraph(i));
		EXPECT_EQ(std::islower(i) != 0, ozen::u8ctype::islower(i));
		EXPECT_EQ(std::isprint(i) != 0, ozen::u8ctype::isprint(i));
		EXPECT_EQ(std::ispunct(i) != 0, ozen::u8ctype::ispunct(i));
		EXPECT_EQ(std::isspace(i) != 0, ozen::u8ctype::isspace(i));
		EXPECT_EQ(std::isupper(i) != 0, ozen::u8ctype::isupper(i));
		EXPECT_EQ(std::isxdigit(i) != 0, ozen::u8ctype::isxdigit(i));
	}
}

TEST(u8ctype_test, to)
{
	for (int i = 0; i < 0x100; ++i) {
		EXPECT_EQ(std::tolower(i), ozen::u8ctype::tolower(i));
		EXPECT_EQ(std::toupper(i), ozen::u8ctype::toupper(i));
	}
}



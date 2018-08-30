#include <cstdint>
#include <cstring>
#include <string_view>

#include <gtest/gtest.h>

#include "ozen/ozen_u8_utils_cx.h"

using namespace std::string_literals;
using namespace std::string_view_literals;


// std::string.

TEST(u8_utils_cx_test, s_trim_start)
{
	std::string s;

	s = ozen::u8str_utils<std::string>::trim_start(u8"\t test \n   "s);
	EXPECT_STREQ(u8"test \n   ", s.c_str());
}

TEST(u8_utils_cx_test, s_trim_end)
{
	std::string s;

	s = ozen::u8str_utils<std::string>::trim_end(u8"\t test \n   "s);
	EXPECT_STREQ(u8"\t test", s.c_str());
}

TEST(u8_utils_cx_test, s_trim)
{
	std::string s;

	s = ozen::u8str_utils<std::string>::trim(u8"\t test \n   "s);
	EXPECT_STREQ(u8"test", s.c_str());
}

TEST(u8_utils_cx_test, s_iequals)
{
	EXPECT_TRUE(ozen::u8str_utils<std::string>::iequals(u8"test"s, u8"test"));
	EXPECT_TRUE(ozen::u8str_utils<std::string>::iequals(u8"test"s, u8"TEST"));
	EXPECT_FALSE(ozen::u8str_utils<std::string>::iequals(u8"test "s, u8"TEST"));
	EXPECT_FALSE(ozen::u8str_utils<std::string>::iequals(u8"test"s, u8"TEST "));
}


// std::string_view.

TEST(u8_utils_cx_test, sv_trim_start)
{
	std::string_view sv;
	std::string s;

	sv = ozen::u8str_utils<std::string_view>::trim_start(u8"\t test \n   "sv);
	s = sv;
	EXPECT_STREQ(u8"test \n   ", s.c_str());
}

TEST(u8_utils_cx_test, sv_trim_end)
{
	std::string_view sv;
	std::string s;

	sv = ozen::u8str_utils<std::string_view>::trim_end(u8"\t test \n   "sv);
	s = sv;
	EXPECT_STREQ(u8"\t test", s.c_str());
}

TEST(u8_utils_cx_test, sv_trim)
{
	std::string_view sv;
	std::string s;

	sv = ozen::u8str_utils<std::string_view>::trim(u8"\t test \n   "sv);
	s = sv;
	EXPECT_STREQ(u8"test", s.c_str());
}

TEST(u8_utils_cx_test, sv_iequals)
{
	EXPECT_TRUE(ozen::u8str_utils<std::string_view>::iequals(u8"test"sv, u8"test"));
	EXPECT_TRUE(ozen::u8str_utils<std::string_view>::iequals(u8"test"sv, u8"TEST"));
	EXPECT_FALSE(ozen::u8str_utils<std::string_view>::iequals(u8"test "sv, u8"TEST"));
	EXPECT_FALSE(ozen::u8str_utils<std::string_view>::iequals(u8"test"sv, u8"TEST "));
}


